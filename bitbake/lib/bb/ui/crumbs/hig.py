#
# BitBake Graphical GTK User Interface
#
# Copyright (C) 2011-2012   Intel Corporation
#
# Authored by Joshua Lock <josh@linux.intel.com>
# Authored by Dongxiao Xu <dongxiao.xu@intel.com>
# Authored by Shane Wang <shane.wang@intel.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

import gtk
import gobject
import hashlib
import os
import re
import subprocess
import shlex
from bb.ui.crumbs.hobcolor import HobColors
from bb.ui.crumbs.hobwidget import hcc, hic, HobViewTable, HobInfoButton
from bb.ui.crumbs.progressbar import HobProgressBar

"""
The following are convenience classes for implementing GNOME HIG compliant
BitBake GUI's
In summary: spacing = 12px, border-width = 6px
"""

#
# CrumbsDialog
#
class CrumbsDialog(gtk.Dialog):
    """
    A GNOME HIG compliant dialog widget.
    Add buttons with gtk.Dialog.add_button or gtk.Dialog.add_buttons
    """
    def __init__(self, title="", parent=None, flags=0, buttons=None):
        super(CrumbsDialog, self).__init__(title, parent, flags, buttons)

        self.set_property("has-separator", False) # note: deprecated in 2.22

        self.set_border_width(6)
        self.vbox.set_property("spacing", 12)
        self.action_area.set_property("spacing", 12)
        self.action_area.set_property("border-width", 6)

class CrumbsMessageDialog(CrumbsDialog):
    """
    A GNOME HIG compliant dialog widget.
    Add buttons with gtk.Dialog.add_button or gtk.Dialog.add_buttons
    """
    def __init__(self, parent=None, label="", icon=gtk.STOCK_INFO):
        super(CrumbsMessageDialog, self).__init__("", parent, gtk.DIALOG_DESTROY_WITH_PARENT)
        
        self.set_border_width(6)
        self.vbox.set_property("spacing", 12)
        self.action_area.set_property("spacing", 12)
        self.action_area.set_property("border-width", 6)

        first_row = gtk.HBox(spacing=12)
        first_row.set_property("border-width", 6)
        first_row.show()
        self.vbox.add(first_row)

        self.icon = gtk.Image()
        # We have our own Info icon which should be used in preference of the stock icon
        if icon == gtk.STOCK_INFO or icon == "gtk-dialog-info":
            self.icon.set_from_file(hic.ICON_INFO_DISPLAY_FILE)
        else:
            self.icon.set_from_stock(icon, gtk.ICON_SIZE_DIALOG)
        self.icon.set_property("yalign", 0.00)
        self.icon.show()
        first_row.add(self.icon)

        self.label = gtk.Label()
        self.label.set_use_markup(True)
        self.label.set_line_wrap(True)
        self.label.set_markup(label)
        self.label.set_property("yalign", 0.00)
        self.label.show()
        first_row.add(self.label)

#
# Brought-in-by Dialog
#
class BinbDialog(CrumbsDialog):
    """
    A dialog widget to show "brought in by" info when a recipe/package is clicked.
    """

    def __init__(self, title, content, parent=None):
        super(BinbDialog, self).__init__(title, parent, gtk.DIALOG_MODAL | gtk.DIALOG_DESTROY_WITH_PARENT, ("Close", gtk.RESPONSE_CLOSE))

        self.set_position(gtk.WIN_POS_MOUSE)
        self.set_resizable(False)
        self.modify_bg(gtk.STATE_NORMAL, gtk.gdk.Color(HobColors.DARK))

        label = gtk.Label(content)
        label.set_alignment(0, 0)
        label.set_line_wrap(True)
        label.modify_fg(gtk.STATE_NORMAL, gtk.gdk.Color(HobColors.WHITE))

        self.vbox.pack_start(label, expand=True, fill=True, padding=10)
        self.vbox.show_all()

#
# AdvancedSettings Dialog
#
class AdvancedSettingDialog (CrumbsDialog):

    def gen_label_widget(self, content):
        label = gtk.Label()
        label.set_alignment(0, 0)
        label.set_markup(content)
        label.show()
        return label

    def gen_spinner_widget(self, content, lower, upper, tooltip=""):
        hbox = gtk.HBox(False, 12)
        adjust = gtk.Adjustment(value=content, lower=lower, upper=upper, step_incr=1)
        spinner = gtk.SpinButton(adjustment=adjust, climb_rate=1, digits=0)

        spinner.set_value(content)
        hbox.pack_start(spinner, expand=False, fill=False)

        info = HobInfoButton(tooltip, self)
        hbox.pack_start(info, expand=False, fill=False)

        hbox.show_all()
        return hbox, spinner

    def gen_combo_widget(self, curr_item, all_item, tooltip=""):
        hbox = gtk.HBox(False, 12)
        combo = gtk.combo_box_new_text()
        hbox.pack_start(combo, expand=False, fill=False)

        index = 0
        for item in all_item or []:
            combo.append_text(item)
            if item == curr_item:
                combo.set_active(index)
            index += 1

        info = HobInfoButton(tooltip, self)
        hbox.pack_start(info, expand=False, fill=False)

        hbox.show_all()
        return hbox, combo

    def entry_widget_select_path_cb(self, action, parent, entry):
        dialog = gtk.FileChooserDialog("", parent,
                                       gtk.FILE_CHOOSER_ACTION_SELECT_FOLDER,
                                       (gtk.STOCK_CANCEL, gtk.RESPONSE_NO,
                                        gtk.STOCK_OPEN, gtk.RESPONSE_YES))
        response = dialog.run()
        if response == gtk.RESPONSE_YES:
            path = dialog.get_filename()
            entry.set_text(path)

        dialog.destroy()

    def gen_entry_widget(self, split_model, content, parent, tooltip=""):
        hbox = gtk.HBox(False, 12)
        entry = gtk.Entry()
        entry.set_text(content)

        if split_model:
            hbox.pack_start(entry, expand=True, fill=True)
        else:
            table = gtk.Table(1, 10, True)
            hbox.pack_start(table, expand=True, fill=True)
            table.attach(entry, 0, 9, 0, 1)
            image = gtk.Image()
            image.set_from_stock(gtk.STOCK_OPEN,gtk.ICON_SIZE_BUTTON)
            open_button = gtk.Button()
            open_button.set_image(image)
            open_button.connect("clicked", self.entry_widget_select_path_cb, parent, entry)
            table.attach(open_button, 9, 10, 0, 1)

        info = HobInfoButton(tooltip, self)
        hbox.pack_start(info, expand=False, fill=False)

        hbox.show_all()
        return hbox, entry

    def pkgfmt_widget_sort_func(self, model, iter1, iter2, data):
        val1 = model.get_value(iter1, 0)
        val2 = model.get_value(iter2, 0)
        inc1 = model.get_value(iter1, 2)
        inc2 = model.get_value(iter2, 2)
        if inc1 != inc2:
            return inc2 - inc1
        else:
            return val1 - val2

    def pkgfmt_widget_tree_selection_changed_cb(self, tree_selection, button1, button2):
        (model, it) = tree_selection.get_selected()
        inc = model.get_value(it, 2)
        if inc:
            button1.set_sensitive(True)
            button2.set_sensitive(True)
        else:
            button1.set_sensitive(False)
            button2.set_sensitive(False)

    def pkgfmt_widget_up_clicked_cb(self, button, tree_selection):
        (model, it) = tree_selection.get_selected()
        if not it:
            return
        path = model.get_path(it)
        if path[0] <= 0:
            return

        pre_it = model.get_iter_first()
        if not pre_it:
            return
        else:
            while model.iter_next(pre_it) :
                if model.get_value(model.iter_next(pre_it), 1) != model.get_value(it, 1):
                    pre_it = model.iter_next(pre_it)
                else:
                    break

            cur_index = model.get_value(it, 0)
            pre_index = cur_index
            if pre_it:
                model.set(pre_it, 0, pre_index)
            cur_index = cur_index - 1
            model.set(it, 0, cur_index)

    def pkgfmt_widget_down_clicked_cb(self, button, tree_selection):
        (model, it) = tree_selection.get_selected()
        if not it:
            return
        next_it = model.iter_next(it)
        if not next_it:
            return
        cur_index = model.get_value(it, 0)
        next_index = cur_index
        model.set(next_it, 0, next_index)
        cur_index = cur_index + 1
        model.set(it, 0, cur_index)

    def pkgfmt_widget_toggle_cb(self, cell, path, model, column):
        it = model.get_iter(path)
        val = model.get_value(it, column)
        val = not val
        model.set(it, column, val)

    def gen_pkgfmt_widget(self, curr_package_format, all_package_format, tooltip=""):
        pkgfmt_hbox = gtk.HBox(False, 12)

        pkgfmt_store = gtk.ListStore(int, str, gobject.TYPE_BOOLEAN)
        for format in curr_package_format.split():
            pkgfmt_store.set(pkgfmt_store.append(), 1, format, 2, True)
        for format in all_package_format:
            if format not in curr_package_format:
                pkgfmt_store.set(pkgfmt_store.append(), 1, format, 2, False)
        pkgfmt_tree = gtk.TreeView(pkgfmt_store)
        pkgfmt_tree.set_headers_clickable(True)
        pkgfmt_tree.set_headers_visible(False)
        tree_selection = pkgfmt_tree.get_selection()
        tree_selection.set_mode(gtk.SELECTION_SINGLE)

        col = gtk.TreeViewColumn('NO')
        col.set_sort_column_id(0)
        col.set_sort_order(gtk.SORT_ASCENDING)
        col.set_clickable(False)
        col1 = gtk.TreeViewColumn('TYPE')
        col1.set_min_width(130)
        col1.set_max_width(140)
        col2 = gtk.TreeViewColumn('INCLUDED')
        col2.set_min_width(60)
        col2.set_max_width(70)
        pkgfmt_tree.append_column(col1)
        pkgfmt_tree.append_column(col2)
        cell = gtk.CellRendererText()
        cell1 = gtk.CellRendererText()
        cell1.set_property('width-chars', 10)
        cell2 = gtk.CellRendererToggle()
        cell2.set_property('activatable', True)
        cell2.connect("toggled", self.pkgfmt_widget_toggle_cb, pkgfmt_store, 2)
        col.pack_start(cell, True)
        col1.pack_start(cell1, True)
        col2.pack_end(cell2, True)
        col.set_attributes(cell, text=0)
        col1.set_attributes(cell1, text=1)
        col2.set_attributes(cell2, active=2)

        pkgfmt_store.set_sort_func(0, self.pkgfmt_widget_sort_func, None)
        pkgfmt_store.set_sort_column_id(0, gtk.SORT_ASCENDING)

        scroll = gtk.ScrolledWindow()
        scroll.set_policy(gtk.POLICY_NEVER, gtk.POLICY_AUTOMATIC)
        scroll.set_shadow_type(gtk.SHADOW_IN)
        scroll.add(pkgfmt_tree)
        scroll.set_size_request(200,60)
        pkgfmt_hbox.pack_start(scroll, False, False, 0)

        vbox = gtk.VBox(False, 6)
        pkgfmt_hbox.pack_start(vbox, False, False, 15)

        up = gtk.Button()
        image = gtk.Image()
        image.set_from_stock(gtk.STOCK_GO_UP, gtk.ICON_SIZE_MENU)
        up.set_image(image)
        up.set_size_request(50,30)
        up.connect("clicked", self.pkgfmt_widget_up_clicked_cb, tree_selection)
        vbox.pack_start(up, False, False, 5)

        down = gtk.Button()
        image = gtk.Image()
        image.set_from_stock(gtk.STOCK_GO_DOWN, gtk.ICON_SIZE_MENU)
        down.set_image(image)
        down.set_size_request(50,30)
        down.connect("clicked", self.pkgfmt_widget_down_clicked_cb, tree_selection)
        vbox.pack_start(down, False, False, 5)
        tree_selection.connect("changed", self.pkgfmt_widget_tree_selection_changed_cb, up, down)

        info = HobInfoButton(tooltip, self)
        pkgfmt_hbox.pack_start(info, expand=False, fill=False)

        pkgfmt_hbox.show_all()

        return pkgfmt_hbox, pkgfmt_store

    def editable_settings_cell_edited(self, cell, path_string, new_text, model):
        it = model.get_iter_from_string(path_string)
        column = cell.get_data("column")
        model.set(it, column, new_text)

    def editable_settings_add_item_clicked(self, button, model):
        new_item = ["##KEY##", "##VALUE##"]

        iter = model.append()
        model.set (iter,
            0, new_item[0],
            1, new_item[1],
       )

    def editable_settings_remove_item_clicked(self, button, treeview):
        selection = treeview.get_selection()
        model, iter = selection.get_selected()

        if iter:
            path = model.get_path(iter)[0]
            model.remove(iter)

    def gen_editable_settings(self, setting, tooltip=""):
        setting_hbox = gtk.HBox(False, 12)

        vbox = gtk.VBox(False, 12)
        setting_hbox.pack_start(vbox, expand=True, fill=True)

        setting_store = gtk.ListStore(gobject.TYPE_STRING, gobject.TYPE_STRING)
        for key in setting.keys():
            setting_store.set(setting_store.append(), 0, key, 1, setting[key])

        setting_tree = gtk.TreeView(setting_store)
        setting_tree.set_headers_visible(True)
        setting_tree.set_size_request(300, 100)

        col = gtk.TreeViewColumn('Key')
        col.set_min_width(100)
        col.set_max_width(150)
        col.set_resizable(True)
        col1 = gtk.TreeViewColumn('Value')
        col1.set_min_width(100)
        col1.set_max_width(150)
        col1.set_resizable(True)
        setting_tree.append_column(col)
        setting_tree.append_column(col1)
        cell = gtk.CellRendererText()
        cell.set_property('width-chars', 10)
        cell.set_property('editable', True)
        cell.set_data("column", 0)
        cell.connect("edited", self.editable_settings_cell_edited, setting_store)
        cell1 = gtk.CellRendererText()
        cell1.set_property('width-chars', 10)
        cell1.set_property('editable', True)
        cell1.set_data("column", 1)
        cell1.connect("edited", self.editable_settings_cell_edited, setting_store)
        col.pack_start(cell, True)
        col1.pack_end(cell1, True)
        col.set_attributes(cell, text=0)
        col1.set_attributes(cell1, text=1)

        scroll = gtk.ScrolledWindow()
        scroll.set_shadow_type(gtk.SHADOW_IN)
        scroll.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
        scroll.add(setting_tree)
        vbox.pack_start(scroll, expand=True, fill=True)

        # some buttons
        hbox = gtk.HBox(True, 6)
        vbox.pack_start(hbox, False, False)

        button = gtk.Button(stock=gtk.STOCK_ADD)
        button.connect("clicked", self.editable_settings_add_item_clicked, setting_store)
        hbox.pack_start(button)

        button = gtk.Button(stock=gtk.STOCK_REMOVE)
        button.connect("clicked", self.editable_settings_remove_item_clicked, setting_tree)
        hbox.pack_start(button)

        info = HobInfoButton(tooltip, self)
        setting_hbox.pack_start(info, expand=False, fill=False)

        return setting_hbox, setting_store

    def __init__(self, title, configuration, all_image_types,
            all_package_formats, all_distros, all_sdk_machines,
            max_threads, split_model, parent, flags, buttons):
        super(AdvancedSettingDialog, self).__init__(title, parent, flags, buttons)

        # class members from other objects
        # bitbake settings from Builder.Configuration
        self.configuration = configuration
        self.image_types = all_image_types
        self.all_package_formats = all_package_formats
        self.all_distros = all_distros
        self.all_sdk_machines = all_sdk_machines
        self.max_threads = max_threads
        self.split_model = split_model 

        # class members for internal use
        self.pkgfmt_store = None
        self.distro_combo = None
        self.dldir_text = None
        self.sstatedir_text = None
        self.sstatemirror_text = None
        self.bb_spinner = None
        self.pmake_spinner = None
        self.rootfs_size_spinner = None
        self.extra_size_spinner = None
        self.gplv3_checkbox = None
        self.toolchain_checkbox = None
        self.setting_store = None
        self.image_types_checkbuttons = {}

        self.variables = {}
        self.variables["PACKAGE_FORMAT"] = self.configuration.curr_package_format
        self.variables["INCOMPATIBLE_LICENSE"] = self.configuration.incompat_license
        self.variables["IMAGE_FSTYPES"] = self.configuration.image_fstypes
        for key in self.configuration.extra_setting.keys():
            self.variables[key] = self.configuration.extra_setting[key]
        self.md5 = hashlib.md5(str(sorted(self.variables.items()))).hexdigest()
        self.settings_changed = False

        # create visual elements on the dialog
        self.create_visual_elements()
        self.connect("response", self.response_cb)

    def create_visual_elements(self):
        self.nb = gtk.Notebook()
        self.nb.set_show_tabs(True)
        self.nb.append_page(self.create_image_types_page(), gtk.Label("Image types"))
        self.nb.append_page(self.create_output_page(), gtk.Label("Output"))
        self.nb.append_page(self.create_build_environment_page(), gtk.Label("Build environment"))
        self.nb.append_page(self.create_others_page(), gtk.Label("Others"))
        self.nb.set_current_page(0)
        self.vbox.pack_start(self.nb, expand=True, fill=True)
        self.vbox.pack_end(gtk.HSeparator(), expand=True, fill=True)

        self.show_all()

    def create_image_types_page(self):
        advanced_vbox = gtk.VBox(False, 6)
        advanced_vbox.set_border_width(6)

        rows = (len(self.image_types)+1)/2
        table = gtk.Table(rows + 1, 10, True)
        advanced_vbox.pack_start(table, expand=False, fill=False)

        tooltip = "Select image file system types that will be used."
        info = HobInfoButton(tooltip, self)
        label = self.gen_label_widget("<span weight=\"bold\">Select image types:</span>")
        table.attach(label, 0, 9, 0, 1)
        table.attach(info, 9, 10, 0, 1)

        i = 1
        j = 1
        for image_type in self.image_types:
            self.image_types_checkbuttons[image_type] = gtk.CheckButton(image_type)
            self.image_types_checkbuttons[image_type].set_tooltip_text("Build an %s image" % image_type)
            table.attach(self.image_types_checkbuttons[image_type], j, j + 4, i, i + 1)
            if image_type in self.configuration.image_fstypes:
                self.image_types_checkbuttons[image_type].set_active(True)
            i += 1
            if i > rows:
                i = 1
                j = j + 4

        return advanced_vbox

    def create_output_page(self):
        advanced_vbox = gtk.VBox(False, 6)
        advanced_vbox.set_border_width(6)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">Packaging Format:</span>")
        tooltip = "Select package formats that will be used. "
        tooltip += "The first format will be used for final image"
        pkgfmt_widget, self.pkgfmt_store = self.gen_pkgfmt_widget(self.configuration.curr_package_format, self.all_package_formats, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(pkgfmt_widget, expand=False, fill=False)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">Image Rootfs Size: (MB)</span>")
        tooltip = "Sets the size of your target image.\nThis is the basic size of your target image, unless your selected package size exceeds this value, or you set value to \"Image Extra Size\"."
        rootfs_size_widget, self.rootfs_size_spinner = self.gen_spinner_widget(int(self.configuration.image_rootfs_size*1.0/1024), 0, 1024, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(rootfs_size_widget, expand=False, fill=False)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">Image Extra Size: (MB)</span>")
        tooltip = "Sets the extra free space of your target image.\nDefaultly, system will reserve 30% of your image size as your free space. If your image contains zypper, it will bring in 50MB more space. The maximum free space is 1024MB."
        extra_size_widget, self.extra_size_spinner = self.gen_spinner_widget(int(self.configuration.image_extra_size*1.0/1024), 0, 1024, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(extra_size_widget, expand=False, fill=False)

        self.gplv3_checkbox = gtk.CheckButton("Exclude GPLv3 packages")
        self.gplv3_checkbox.set_tooltip_text("Check this box to prevent GPLv3 packages from being included in your image")
        if "GPLv3" in self.configuration.incompat_license.split():
            self.gplv3_checkbox.set_active(True)
        else:
            self.gplv3_checkbox.set_active(False)
        advanced_vbox.pack_start(self.gplv3_checkbox, expand=False, fill=False)

        sub_hbox = gtk.HBox(False, 6)
        advanced_vbox.pack_start(sub_hbox, expand=False, fill=False)
        self.toolchain_checkbox = gtk.CheckButton("Build Toolchain")
        self.toolchain_checkbox.set_tooltip_text("Check this box to build the related toolchain with your image")
        self.toolchain_checkbox.set_active(self.configuration.toolchain_build)
        sub_hbox.pack_start(self.toolchain_checkbox, expand=False, fill=False)

        tooltip = "This is the Host platform you would like to run the toolchain"
        sdk_machine_widget, self.sdk_machine_combo = self.gen_combo_widget(self.configuration.curr_sdk_machine, self.all_sdk_machines, tooltip)
        sub_hbox.pack_start(sdk_machine_widget, expand=False, fill=False)

        return advanced_vbox

    def create_build_environment_page(self):
        advanced_vbox = gtk.VBox(False, 6)
        advanced_vbox.set_border_width(6)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">Select Distro:</span>")
        tooltip = "This is the Yocto distribution you would like to use"
        distro_widget, self.distro_combo = self.gen_combo_widget(self.configuration.curr_distro, self.all_distros, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(distro_widget, expand=False, fill=False)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">BB_NUMBER_THREADS:</span>")
        tooltip = "Sets the number of threads that bitbake tasks can run simultaneously"
        bbthread_widget, self.bb_spinner = self.gen_spinner_widget(self.configuration.bbthread, 1, self.max_threads, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(bbthread_widget, expand=False, fill=False)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">PARALLEL_MAKE:</span>")
        tooltip = "Sets the make parallism, as known as 'make -j'"
        pmake_widget, self.pmake_spinner = self.gen_spinner_widget(self.configuration.pmake, 1, self.max_threads, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(pmake_widget, expand=False, fill=False)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">Set Download Directory:</span>")
        tooltip = "Select a folder that caches the upstream project source code"
        dldir_widget, self.dldir_text = self.gen_entry_widget(self.split_model, self.configuration.dldir, self, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(dldir_widget, expand=False, fill=False)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">Select SSTATE Directory:</span>")
        tooltip = "Select a folder that caches your prebuilt results"
        sstatedir_widget, self.sstatedir_text = self.gen_entry_widget(self.split_model, self.configuration.sstatedir, self, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(sstatedir_widget, expand=False, fill=False)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=False, fill=False)
        label = self.gen_label_widget("<span weight=\"bold\">Select SSTATE Mirror:</span>")
        tooltip = "Select the prebuilt mirror that will fasten your build speed"
        sstatemirror_widget, self.sstatemirror_text = self.gen_entry_widget(self.split_model, self.configuration.sstatemirror, self, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(sstatemirror_widget, expand=False, fill=False)

        return advanced_vbox

    def create_others_page(self):
        advanced_vbox = gtk.VBox(False, 6)
        advanced_vbox.set_border_width(6)

        sub_vbox = gtk.VBox(False, 6)
        advanced_vbox.pack_start(sub_vbox, expand=True, fill=True)
        label = self.gen_label_widget("<span weight=\"bold\">Add your own variables:</span>")
        tooltip = "This is the key/value pair for your extra settings"
        setting_widget, self.setting_store = self.gen_editable_settings(self.configuration.extra_setting, tooltip)
        sub_vbox.pack_start(label, expand=False, fill=False)
        sub_vbox.pack_start(setting_widget, expand=True, fill=True)

        return advanced_vbox

    def response_cb(self, dialog, response_id):
        self.variables = {}

        self.configuration.curr_package_format = ""
        it = self.pkgfmt_store.get_iter_first()
        while it:
            value = self.pkgfmt_store.get_value(it, 2)
            if value:
                self.configuration.curr_package_format += (self.pkgfmt_store.get_value(it, 1) + " ")
            it = self.pkgfmt_store.iter_next(it)
        self.configuration.curr_package_format = self.configuration.curr_package_format.strip()
        self.variables["PACKAGE_FORMAT"] = self.configuration.curr_package_format

        self.configuration.curr_distro = self.distro_combo.get_active_text()
        self.configuration.dldir = self.dldir_text.get_text()
        self.configuration.sstatedir = self.sstatedir_text.get_text()
        self.configuration.sstatemirror = self.sstatemirror_text.get_text()
        self.configuration.bbthread = self.bb_spinner.get_value_as_int()
        self.configuration.pmake = self.pmake_spinner.get_value_as_int()
        self.configuration.image_rootfs_size = self.rootfs_size_spinner.get_value_as_int() * 1024
        self.configuration.image_extra_size = self.extra_size_spinner.get_value_as_int() * 1024

        self.configuration.image_fstypes = []
        for image_type in self.image_types:
            if self.image_types_checkbuttons[image_type].get_active():
                self.configuration.image_fstypes.append(image_type)
        self.variables["IMAGE_FSTYPES"] = self.configuration.image_fstypes

        if self.gplv3_checkbox.get_active():
            if "GPLv3" not in self.configuration.incompat_license.split():
                self.configuration.incompat_license += " GPLv3"
        else:
            if "GPLv3" in self.configuration.incompat_license.split():
                self.configuration.incompat_license = self.configuration.incompat_license.split().remove("GPLv3")
                self.configuration.incompat_license = " ".join(self.configuration.incompat_license or [])
        self.configuration.incompat_license = self.configuration.incompat_license.strip()
        self.variables["INCOMPATIBLE_LICENSE"] = self.configuration.incompat_license

        self.configuration.toolchain_build = self.toolchain_checkbox.get_active()

        self.configuration.extra_setting = {}
        it = self.setting_store.get_iter_first()
        while it:
            key = self.setting_store.get_value(it, 0)
            value = self.setting_store.get_value(it, 1)
            self.configuration.extra_setting[key] = value
            self.variables[key] = value
            it = self.setting_store.iter_next(it)

        md5 = hashlib.md5(str(sorted(self.variables.items()))).hexdigest()
        self.settings_changed = (self.md5 != md5)

#
# DeployImageDialog
#
class DeployImageDialog (CrumbsDialog):

    __dummy_usb__ = "--select a usb drive--"

    def __init__(self, title, image_path, parent, flags, buttons):
        super(DeployImageDialog, self).__init__(title, parent, flags, buttons)

        self.image_path = image_path

        self.create_visual_elements()
        self.connect("response", self.response_cb)

    def create_visual_elements(self):
        label = gtk.Label()
        label.set_alignment(0.0, 0.5)
        markup = "<span font_desc='12'>The image to be written into usb drive:</span>"
        label.set_markup(markup)
        self.vbox.pack_start(label, expand=False, fill=False, padding=2)

        scroll = gtk.ScrolledWindow()
        scroll.set_policy(gtk.POLICY_NEVER, gtk.POLICY_AUTOMATIC)
        scroll.set_shadow_type(gtk.SHADOW_IN)
        tv = gtk.TextView()
        tv.set_editable(False)
        tv.set_wrap_mode(gtk.WRAP_WORD)
        tv.set_cursor_visible(False)
        buf = gtk.TextBuffer()
        buf.set_text(self.image_path)
        tv.set_buffer(buf)
        scroll.add(tv)
        self.vbox.pack_start(scroll, expand=True, fill=True)

        self.usb_desc = gtk.Label()
        self.usb_desc.set_alignment(0.0, 0.5)
        markup = "<span font_desc='12'>You haven't chosen any USB drive.</span>"
        self.usb_desc.set_markup(markup)

        self.usb_combo = gtk.combo_box_new_text()
        self.usb_combo.connect("changed", self.usb_combo_changed_cb)
        model = self.usb_combo.get_model()
        model.clear()
        self.usb_combo.append_text(self.__dummy_usb__)
        for usb in self.find_all_usb_devices():
            self.usb_combo.append_text("/dev/" + usb)
        self.usb_combo.set_active(0)
        self.vbox.pack_start(self.usb_combo, expand=True, fill=True)
        self.vbox.pack_start(self.usb_desc, expand=False, fill=False, padding=2)

        self.progress_bar = HobProgressBar()
        self.vbox.pack_start(self.progress_bar, expand=False, fill=False)
        separator = gtk.HSeparator()
        self.vbox.pack_start(separator, expand=False, fill=True, padding=10)

        self.vbox.show_all()
        self.progress_bar.hide()

    def popen_read(self, cmd):
        return os.popen("%s 2>/dev/null" % cmd).read().strip()

    def find_all_usb_devices(self):
        usb_devs = [ os.readlink(u)
            for u in self.popen_read('ls /dev/disk/by-id/usb*').split()
            if not re.search(r'part\d+', u) ]
        return [ '%s' % u[u.rfind('/')+1:] for u in usb_devs ]

    def get_usb_info(self, dev):
        return "%s %s" % \
            (self.popen_read('cat /sys/class/block/%s/device/vendor' % dev),
            self.popen_read('cat /sys/class/block/%s/device/model' % dev))

    def usb_combo_changed_cb(self, usb_combo):
        combo_item = self.usb_combo.get_active_text()
        if not combo_item or combo_item == self.__dummy_usb__:
            markup = "<span font_desc='12'>You haven't chosen any USB drive.</span>"
            self.usb_desc.set_markup(markup)
        else:
            markup = "<span font_desc='12'>" + self.get_usb_info(combo_item.lstrip("/dev/")) + "</span>"
            self.usb_desc.set_markup(markup)

    def response_cb(self, dialog, response_id):
        if response_id == gtk.RESPONSE_YES:
            combo_item = self.usb_combo.get_active_text()
            if combo_item and combo_item != self.__dummy_usb__:
                cmdline = "/usr/bin/xterm -e "
                cmdline += "\"sudo dd if=" + self.image_path + " of=" + combo_item + "; bash\""
                subprocess.Popen(args=shlex.split(cmdline))

    def update_progress_bar(self, title, fraction, status=True):
        self.progress_bar.update(fraction)
        self.progress_bar.set_title(title)
        self.progress_bar.set_rcstyle(status)

    def write_file(self, ifile, ofile):
        self.progress_bar.reset()
        self.progress_bar.show()

        f_from = os.open(ifile, os.O_RDONLY)
        f_to = os.open(ofile, os.O_WRONLY)

        total_size = os.stat(ifile).st_size
        written_size = 0

        while True:
            buf = os.read(f_from, 1024*1024)
            if not buf:
                break
            os.write(f_to, buf)
            written_size += 1024*1024
            self.update_progress_bar("Writing to usb:", written_size * 1.0/total_size)

        self.update_progress_bar("Writing completed:", 1.0)
        os.close(f_from)
        os.close(f_to)
        self.progress_bar.hide()
#
# LayerSelectionDialog
#
class LayerSelectionDialog (CrumbsDialog):

    def gen_label_widget(self, content):
        label = gtk.Label()
        label.set_alignment(0, 0)
        label.set_markup(content)
        label.show()
        return label

    def layer_widget_toggled_cb(self, cell, path, layer_store):
        name = layer_store[path][0]
        toggle = not layer_store[path][1]
        layer_store[path][1] = toggle

    def layer_widget_add_clicked_cb(self, action, layer_store, parent):
        dialog = gtk.FileChooserDialog("Add new layer", parent,
                                       gtk.FILE_CHOOSER_ACTION_SELECT_FOLDER,
                                       (gtk.STOCK_CANCEL, gtk.RESPONSE_NO,
                                        gtk.STOCK_OPEN, gtk.RESPONSE_YES))
        label = gtk.Label("Select the layer you wish to add")
        label.show()
        dialog.set_extra_widget(label)
        response = dialog.run()
        path = dialog.get_filename()
        dialog.destroy()

        lbl = "<b>Error</b>\nUnable to load layer <i>%s</i> because " % path
        if response == gtk.RESPONSE_YES:
            import os
            import os.path
            layers = []
            it = layer_store.get_iter_first()
            while it:
                layers.append(layer_store.get_value(it, 0))
                it = layer_store.iter_next(it)

            if not path:
                lbl += "it is an invalid path."
            elif not os.path.exists(path+"/conf/layer.conf"):
                lbl += "there is no layer.conf inside the directory."
            elif path in layers:
                lbl += "it is already in loaded layers."
            else:
                layer_store.append([path])
                return
            dialog = CrumbsMessageDialog(parent, lbl)
            dialog.add_button(gtk.STOCK_CLOSE, gtk.RESPONSE_OK)
            response = dialog.run()
            dialog.destroy()

    def layer_widget_del_clicked_cb(self, action, tree_selection, layer_store):
        model, iter = tree_selection.get_selected()
        if iter:
            layer_store.remove(iter)


    def gen_layer_widget(self, split_model, layers, layers_avail, window, tooltip=""):
        hbox = gtk.HBox(False, 6)

        layer_tv = gtk.TreeView()
        layer_tv.set_rules_hint(True)
        layer_tv.set_headers_visible(False)
        tree_selection = layer_tv.get_selection()
        tree_selection.set_mode(gtk.SELECTION_SINGLE)

        col0= gtk.TreeViewColumn('Path')
        cell0 = gtk.CellRendererText()
        cell0.set_padding(5,2)
        col0.pack_start(cell0, True)
        col0.set_attributes(cell0, text=0)
        layer_tv.append_column(col0)

        scroll = gtk.ScrolledWindow()
        scroll.set_policy(gtk.POLICY_NEVER, gtk.POLICY_AUTOMATIC)
        scroll.set_shadow_type(gtk.SHADOW_IN)
        scroll.add(layer_tv)

        table_layer = gtk.Table(2, 10, False)
        hbox.pack_start(table_layer, expand=True, fill=True)

        if split_model:
            table_layer.attach(scroll, 0, 10, 0, 2)

            layer_store = gtk.ListStore(gobject.TYPE_STRING, gobject.TYPE_BOOLEAN)
            for layer in layers:
                layer_store.set(layer_store.append(), 0, layer, 1, True)
            for layer in layers_avail:
                if layer not in layers:
                    layer_store.set(layer_store.append(), 0, layer, 1, False)

            col1 = gtk.TreeViewColumn('Included')
            layer_tv.append_column(col1)

            cell1 = gtk.CellRendererToggle()
            cell1.connect("toggled", self.layer_widget_toggled_cb, layer_store)
            col1.pack_start(cell1, True)
            col1.set_attributes(cell1, active=1)

        else:
            table_layer.attach(scroll, 0, 10, 0, 1)

            layer_store = gtk.ListStore(gobject.TYPE_STRING)
            for layer in layers:
                layer_store.set(layer_store.append(), 0, layer)

            image = gtk.Image()
            image.set_from_stock(gtk.STOCK_ADD,gtk.ICON_SIZE_MENU)
            add_button = gtk.Button()
            add_button.set_image(image)
            add_button.connect("clicked", self.layer_widget_add_clicked_cb, layer_store, window)
            table_layer.attach(add_button, 0, 5, 1, 2, gtk.EXPAND | gtk.FILL, 0, 0, 6)
            image = gtk.Image()
            image.set_from_stock(gtk.STOCK_REMOVE,gtk.ICON_SIZE_MENU)
            del_button = gtk.Button()
            del_button.set_image(image)
            del_button.connect("clicked", self.layer_widget_del_clicked_cb, tree_selection, layer_store)
            table_layer.attach(del_button, 5, 10, 1, 2, gtk.EXPAND | gtk.FILL, 0, 0, 6)
        layer_tv.set_model(layer_store)

        hbox.show_all()

        return hbox, layer_store

    def __init__(self, title, layers, all_layers, split_model,
            parent, flags, buttons):
        super(LayerSelectionDialog, self).__init__(title, parent, flags, buttons)

        # class members from other objects
        self.layers = layers
        self.all_layers = all_layers
        self.split_model = split_model
        self.layers_changed = False

        # class members for internal use
        self.layer_store = None

        # create visual elements on the dialog
        self.create_visual_elements()
        self.connect("response", self.response_cb)
                
    def create_visual_elements(self):
        hbox_top = gtk.HBox()
        self.vbox.pack_start(hbox_top, expand=False, fill=False)

        if self.split_model:
            label = self.gen_label_widget("<b>Select Layers:</b>\n(Available layers under '${COREBASE}/layers/' directory)")
        else:
            label = self.gen_label_widget("<b>Select Layers:</b>")
        hbox_top.pack_start(label, expand=False, fill=False)

        tooltip = "Layer is a collection of bb files and conf files"
        info = HobInfoButton(tooltip, self)
        hbox_top.pack_end(info, expand=False, fill=False)

        layer_widget, self.layer_store = self.gen_layer_widget(self.split_model, self.layers, self.all_layers, self, None)
        layer_widget.set_size_request(-1, 180)
        self.vbox.pack_start(layer_widget, expand=True, fill=True)

        label = self.gen_label_widget("<b>Note:</b> '<i>meta</i>' is the Core layer for Yocto images please do not remove it.")
        label.show()
        self.vbox.pack_end(label, expand=False, fill=False)

        self.show_all()

    def response_cb(self, dialog, response_id):
        model = self.layer_store
        it = model.get_iter_first()
        layers = []
        while it:
            if self.split_model:
                inc = model.get_value(it, 1)
                if inc:
                    layers.append(model.get_value(it, 0))
            else:
                layers.append(model.get_value(it, 0))
            it = model.iter_next(it)

        self.layers_changed = (self.layers != layers)
        self.layers = layers

class ImageSelectionDialog (CrumbsDialog):

    __columns__ = [{
            'col_name' : 'Image name',
            'col_id'   : 0,
            'col_style': 'text',
            'col_min'  : 400,
            'col_max'  : 400
        }, {
            'col_name' : 'Select',
            'col_id'   : 1,
            'col_style': 'radio toggle',
            'col_min'  : 160,
            'col_max'  : 160
    }]


    def __init__(self, image_folder, image_types, title, parent, flags, buttons):
        super(ImageSelectionDialog, self).__init__(title, parent, flags, buttons)
        self.connect("response", self.response_cb)

        self.image_folder = image_folder
        self.image_types  = image_types
        self.image_list = []
        self.image_names = []

        # create visual elements on the dialog
        self.create_visual_elements()

        self.image_store = gtk.ListStore(gobject.TYPE_STRING, gobject.TYPE_BOOLEAN)
        self.fill_image_store()

    def create_visual_elements(self):
        hbox = gtk.HBox(False, 6)

        self.vbox.pack_start(hbox, expand=False, fill=False)

        entry = gtk.Entry()
        entry.set_text(self.image_folder)
        table = gtk.Table(1, 10, True)
        table.set_size_request(560, -1)
        hbox.pack_start(table, expand=False, fill=False)
        table.attach(entry, 0, 9, 0, 1)
        image = gtk.Image()
        image.set_from_stock(gtk.STOCK_OPEN, gtk.ICON_SIZE_BUTTON)
        open_button = gtk.Button()
        open_button.set_image(image)
        open_button.connect("clicked", self.select_path_cb, self, entry)
        table.attach(open_button, 9, 10, 0, 1)

        self.image_table = HobViewTable(self.__columns__)
        self.image_table.set_size_request(-1, 300)
        self.image_table.connect("toggled", self.toggled_cb)
        self.vbox.pack_start(self.image_table, expand=True, fill=True)

        self.show_all()

    def toggled_cb(self, table, cell, path, columnid, tree):
        model = tree.get_model()
        if not model:
            return
        iter = model.get_iter_first()
        while iter:
            rowpath = model.get_path(iter)
            model[rowpath][columnid] = False
            iter = model.iter_next(iter)

        model[path][columnid] = True

    def select_path_cb(self, action, parent, entry):
        dialog = gtk.FileChooserDialog("", parent,
                                       gtk.FILE_CHOOSER_ACTION_SELECT_FOLDER,
                                       (gtk.STOCK_CANCEL, gtk.RESPONSE_NO,
                                        gtk.STOCK_OPEN, gtk.RESPONSE_YES))
        response = dialog.run()
        if response == gtk.RESPONSE_YES:
            path = dialog.get_filename()
            entry.set_text(path)
            self.image_folder = path
            self.fill_image_store()

        dialog.destroy()

    def fill_image_store(self):
        self.image_list = []
        self.image_store.clear()
        imageset = set()
        for root, dirs, files in os.walk(self.image_folder):
            # ignore the sub directories
            dirs[:] = []
            for f in files:
                for image_type in self.image_types:
                    for real_image_type in hcc.SUPPORTED_IMAGE_TYPES[image_type]:
                        if f.endswith('.' + real_image_type):
                            imageset.add(f.rsplit('.' + real_image_type)[0])
                            self.image_list.append(f)
        
        for image in imageset:
            self.image_store.set(self.image_store.append(), 0, image, 1, False)

        self.image_table.set_model(self.image_store)

    def response_cb(self, dialog, response_id):
        self.image_names = []
        if response_id == gtk.RESPONSE_YES:
            iter = self.image_store.get_iter_first()
            while iter:
                path = self.image_store.get_path(iter)
                if self.image_store[path][1]:
                    for f in self.image_list:
                        if f.startswith(self.image_store[path][0] + '.'):
                            self.image_names.append(f)
                    break            
                iter = self.image_store.iter_next(iter)
