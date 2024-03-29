# Report significant differences in the buildhistory repository since a specific revision
#
# Copyright (C) 2012 Intel Corporation
# Author: Paul Eggleton <paul.eggleton@linux.intel.com>
#
# Note: requires GitPython 0.3.1+
#
# You can use this from the command line by running scripts/buildhistory-diff
#

import sys
import os.path
import difflib
import git
import re


# How to display fields
list_fields = ['DEPENDS', 'RDEPENDS', 'RRECOMMENDS', 'FILES', 'FILELIST', 'USER_CLASSES', 'IMAGE_CLASSES', 'IMAGE_FEATURES', 'IMAGE_LINGUAS', 'IMAGE_INSTALL', 'BAD_RECOMMENDATIONS']
list_order_fields = ['PACKAGES']
numeric_fields = ['PKGSIZE', 'IMAGESIZE']
# Fields to monitor
monitor_fields = ['RDEPENDS', 'RRECOMMENDS', 'PACKAGES', 'FILELIST', 'PKGSIZE', 'IMAGESIZE']
# Percentage change to alert for numeric fields
monitor_numeric_threshold = 20
# Image files to monitor (note that image-info.txt is handled separately)
img_monitor_files = ['installed-package-names.txt', 'files-in-image.txt']
# Related context fields for reporting (note: PE, PV & PR are always reported for monitored package fields)
related_fields = {}
related_fields['RDEPENDS'] = ['DEPENDS']
related_fields['RRECOMMENDS'] = ['DEPENDS']
related_fields['FILELIST'] = ['FILES']
related_fields['PKGSIZE'] = ['FILELIST']
related_fields['files-in-image.txt'] = ['installed-package-names.txt', 'USER_CLASSES', 'IMAGE_CLASSES', 'ROOTFS_POSTPROCESS_COMMAND', 'IMAGE_POSTPROCESS_COMMAND']
related_fields['installed-package-names.txt'] = ['IMAGE_FEATURES', 'IMAGE_LINGUAS', 'IMAGE_INSTALL', 'BAD_RECOMMENDATIONS']


class ChangeRecord:
    def __init__(self, path, fieldname, oldvalue, newvalue, monitored):
        self.path = path
        self.fieldname = fieldname
        self.oldvalue = oldvalue
        self.newvalue = newvalue
        self.monitored = monitored
        self.related = []
        self.filechanges = None

    def __str__(self):
        return self._str_internal(True)

    def _str_internal(self, pathprefix):
        if pathprefix:
            prefix = '%s: ' % self.path
        else:
            prefix = ''

        def pkglist_split(pkgs):
            pkgit = re.finditer(r'[a-zA-Z0-9.+-]+( \([><=]+ [^ )]+\))?', pkgs, 0)
            pkglist = [p.group(0) for p in pkgit]
            return pkglist

        if self.fieldname in list_fields or self.fieldname in list_order_fields:
            if self.fieldname in ['RDEPENDS', 'RRECOMMENDS']:
                aitems = pkglist_split(self.oldvalue)
                bitems = pkglist_split(self.newvalue)
            else:
                aitems = self.oldvalue.split()
                bitems = self.newvalue.split()
            removed = list(set(aitems) - set(bitems))
            added = list(set(bitems) - set(aitems))
            if removed or added:
                out = '%s:%s%s' % (self.fieldname, ' removed "%s"' % ' '.join(removed) if removed else '', ' added "%s"' % ' '.join(added) if added else '')
            else:
                out = '%s changed order' % self.fieldname
        elif self.fieldname in numeric_fields:
            aval = int(self.oldvalue or 0)
            bval = int(self.newvalue or 0)
            if aval != 0:
                percentchg = ((bval - aval) / float(aval)) * 100
            else:
                percentchg = 100
            out = '%s changed from %s to %s (%s%d%%)' % (self.fieldname, self.oldvalue or "''", self.newvalue or "''", '+' if percentchg > 0 else '', percentchg)
        elif self.fieldname in img_monitor_files:
            if pathprefix:
                prefix = 'Changes to %s ' % self.path
            out = '(%s):\n  ' % self.fieldname
            if self.filechanges:
                out += '\n  '.join(['%s' % i for i in self.filechanges])
            else:
                alines = self.oldvalue.splitlines()
                blines = self.newvalue.splitlines()
                diff = difflib.unified_diff(alines, blines, self.fieldname, self.fieldname, lineterm='')
                out += '\n  '.join(list(diff))
                out += '\n  --'
        else:
            out = '%s changed from "%s" to "%s"' % (self.fieldname, self.oldvalue, self.newvalue)

        if self.related:
            for chg in self.related:
                for line in chg._str_internal(False).splitlines():
                    out += '\n  * %s' % line

        return '%s%s' % (prefix, out)

class FileChange:
    changetype_add = 'A'
    changetype_remove = 'R'
    changetype_type = 'T'
    changetype_perms = 'P'
    changetype_ownergroup = 'O'
    changetype_link = 'L'

    def __init__(self, path, changetype, oldvalue = None, newvalue = None):
        self.path = path
        self.changetype = changetype
        self.oldvalue = oldvalue
        self.newvalue = newvalue

    def _ftype_str(self, ftype):
        if ftype == '-':
            return 'file'
        elif ftype == 'd':
            return 'directory'
        elif ftype == 'l':
            return 'symlink'
        elif ftype == 'c':
            return 'char device'
        elif ftype == 'b':
            return 'block device'
        elif ftype == 'p':
            return 'fifo'
        elif ftype == 's':
            return 'socket'
        else:
            return 'unknown (%s)' % ftype

    def __str__(self):
        if self.changetype == self.changetype_add:
            return '%s was added' % self.path
        elif self.changetype == self.changetype_remove:
            return '%s was removed' % self.path
        elif self.changetype == self.changetype_type:
            return '%s changed type from %s to %s' % (self.path, self._ftype_str(self.oldvalue), self._ftype_str(self.newvalue))
        elif self.changetype == self.changetype_perms:
            return '%s changed permissions from %s to %s' % (self.path, self.oldvalue, self.newvalue)
        elif self.changetype == self.changetype_ownergroup:
            return '%s changed owner/group from %s to %s' % (self.path, self.oldvalue, self.newvalue)
        elif self.changetype == self.changetype_link:
            return '%s changed symlink target from %s to %s' % (self.path, self.oldvalue, self.newvalue)
        else:
            return '%s changed (unknown)' % self.path


def blob_to_dict(blob):
    alines = blob.data_stream.read().splitlines()
    adict = {}
    for line in alines:
        splitv = [i.strip() for i in line.split('=',1)]
        if splitv.count > 1:
            adict[splitv[0]] = splitv[1]
    return adict


def file_list_to_dict(lines):
    adict = {}
    for line in lines:
        # Leave the last few fields intact so we handle file names containing spaces
        splitv = line.split(None,4)
        # Grab the path and remove the leading .
        path = splitv[4][1:].strip()
        # Handle symlinks
        if(' -> ' in path):
            target = path.split(' -> ')[1]
            path = path.split(' -> ')[0]
            adict[path] = splitv[0:3] + [target]
        else:
            adict[path] = splitv[0:3]
    return adict


def compare_file_lists(alines, blines):
    adict = file_list_to_dict(alines)
    bdict = file_list_to_dict(blines)
    filechanges = []
    for path, splitv in adict.iteritems():
        newsplitv = bdict.pop(path, None)
        if newsplitv:
            # Check type
            oldvalue = splitv[0][0]
            newvalue = newsplitv[0][0]
            if oldvalue != newvalue:
                filechanges.append(FileChange(path, FileChange.changetype_type, oldvalue, newvalue))
            # Check permissions
            oldvalue = splitv[0][1:]
            newvalue = newsplitv[0][1:]
            if oldvalue != newvalue:
                filechanges.append(FileChange(path, FileChange.changetype_perms, oldvalue, newvalue))
            # Check owner/group
            oldvalue = '%s/%s' % (splitv[1], splitv[2])
            newvalue = '%s/%s' % (newsplitv[1], newsplitv[2])
            if oldvalue != newvalue:
                filechanges.append(FileChange(path, FileChange.changetype_ownergroup, oldvalue, newvalue))
            # Check symlink target
            if newsplitv[0][0] == 'l':
                if splitv.count > 3:
                    oldvalue = splitv[3]
                else:
                    oldvalue = None
                newvalue = newsplitv[3]
                if oldvalue != newvalue:
                    filechanges.append(FileChange(path, FileChange.changetype_link, oldvalue, newvalue))
        else:
            filechanges.append(FileChange(path, FileChange.changetype_remove))

    # Whatever is left over has been added
    for path in bdict:
        filechanges.append(FileChange(path, FileChange.changetype_add))

    return filechanges


def compare_lists(alines, blines):
    removed = list(set(alines) - set(blines))
    added = list(set(blines) - set(alines))

    filechanges = []
    for pkg in removed:
        filechanges.append(FileChange(pkg, FileChange.changetype_remove))
    for pkg in added:
        filechanges.append(FileChange(pkg, FileChange.changetype_add))

    return filechanges


def compare_dict_blobs(path, ablob, bblob, report_all):
    adict = blob_to_dict(ablob)
    bdict = blob_to_dict(bblob)

    changes = []
    keys = list(set(adict.keys()) | set(bdict.keys()))
    for key in keys:
        astr = adict.get(key, '')
        bstr = bdict.get(key, '')
        if astr != bstr:
            if (not report_all) and key in numeric_fields:
                aval = int(astr or 0)
                bval = int(bstr or 0)
                if aval != 0:
                    percentchg = ((bval - aval) / float(aval)) * 100
                else:
                    percentchg = 100
                if percentchg < monitor_numeric_threshold:
                    continue
            elif (not report_all) and key in list_fields:
                alist = astr.split()
                alist.sort()
                blist = bstr.split()
                blist.sort()
                if ' '.join(alist) == ' '.join(blist):
                    continue
            chg = ChangeRecord(path, key, astr, bstr, key in monitor_fields)
            changes.append(chg)
    return changes


def process_changes(repopath, revision1, revision2 = 'HEAD', report_all = False):
    repo = git.Repo(repopath)
    assert repo.bare == False
    commit = repo.commit(revision1)
    diff = commit.diff(revision2)

    changes = []
    for d in diff.iter_change_type('M'):
        path = os.path.dirname(d.a_blob.path)
        if path.startswith('packages/'):
            changes.extend(compare_dict_blobs(path, d.a_blob, d.b_blob, report_all))
        elif path.startswith('images/'):
            filename = os.path.basename(d.a_blob.path)
            if filename in img_monitor_files:
                if filename == 'files-in-image.txt':
                    alines = d.a_blob.data_stream.read().splitlines()
                    blines = d.b_blob.data_stream.read().splitlines()
                    filechanges = compare_file_lists(alines,blines)
                    if filechanges:
                        chg = ChangeRecord(path, filename, None, None, True)
                        chg.filechanges = filechanges
                        changes.append(chg)
                elif filename == 'installed-package-names.txt':
                    alines = d.a_blob.data_stream.read().splitlines()
                    blines = d.b_blob.data_stream.read().splitlines()
                    filechanges = compare_lists(alines,blines)
                    if filechanges:
                        chg = ChangeRecord(path, filename, None, None, True)
                        chg.filechanges = filechanges
                        changes.append(chg)
                else:
                    chg = ChangeRecord(path, filename, d.a_blob.data_stream.read(), d.b_blob.data_stream.read(), True)
                    changes.append(chg)
            elif filename == 'image-info.txt':
                changes.extend(compare_dict_blobs(path, d.a_blob, d.b_blob, report_all))

    # Link related changes
    for chg in changes:
        if chg.monitored:
            for chg2 in changes:
                # (Check dirname in the case of fields from recipe info files)
                if chg.path == chg2.path or os.path.dirname(chg.path) == chg2.path:
                    if chg2.fieldname in related_fields.get(chg.fieldname, []):
                        chg.related.append(chg2)
                    elif chg.path == chg2.path and chg.path.startswith('packages/') and chg2.fieldname in ['PE', 'PV', 'PR']:
                        chg.related.append(chg2)

    if report_all:
        return changes
    else:
        return [chg for chg in changes if chg.monitored]
