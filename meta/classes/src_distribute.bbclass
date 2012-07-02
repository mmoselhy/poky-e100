SRC_DISTRIBUTECOMMAND[func] = "1"
python do_distribute_sources () {
	l = bb.data.createCopy(d)
	bb.data.update_data(l)

	sources_dir = d.getVar('SRC_DISTRIBUTEDIR', True)
	src_uri = d.getVar('SRC_URI', True).split()
	fetcher = bb.fetch2.Fetch(src_uri, d)
	ud = fetcher.ud

	licenses = d.getVar('LICENSE', True).replace('&', '|')
	licenses = licenses.replace('(', '').replace(')', '')
	clean_licenses = ""
	for x in licenses.split():
		if x.strip() == '' or x == 'CLOSED':
			continue

		if x != "|":
			clean_licenses += x

	for license in clean_licenses.split('|'):
		for url in ud.values():
			cmd = d.getVar('SRC_DISTRIBUTECOMMAND', True)
			if not cmd:
				raise bb.build.FuncFailed("Unable to distribute sources, SRC_DISTRIBUTECOMMAND not defined")
			url.setup_localpath(d)
			d.setVar('SRC', url.localpath)
			if url.type == 'file':
				if url.basename == '*':
					import os.path
					dest_dir = os.path.basename(os.path.dirname(os.path.abspath(url.localpath)))
					d.setVar('DEST', "%s_%s/" % (d.getVar('PF', True), dest_dir))
				else:
					d.setVar('DEST', "%s_%s" % (d.getVar('PF', True), url.basename))
			else:
				d.setVar('DEST', '')

			d.setVar('SRC_DISTRIBUTEDIR', "%s/%s" % (sources_dir, license))
			bb.build.exec_func('SRC_DISTRIBUTECOMMAND', d)
}

addtask distribute_sources before do_build after do_fetch

addtask distribute_sources_all after do_distribute_sources
do_distribute_sources_all[recrdeptask] = "do_distribute_sources"
do_distribute_sources_all[nostamp] = "1"
do_distribute_sources_all () {
	:
}
