SUMMARY = "name server information handler"
DESCRIPTION = "Resolvconf is a framework for keeping track of the system's \
information about currently available nameservers. It sets \
itself up as the intermediary between programs that supply \
nameserver information and programs that need nameserver \
information."
SECTION = "console/network"
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=c93c0550bd3173f4504b2cbd8991e50b"
AUTHOR = "Thomas Hood"
HOMEPAGE = "http://packages.debian.org/resolvconf"
RDEPENDS_${PN} = "bash"
PR = "r0"

SRC_URI = "${DEBIAN_MIRROR}/main/r/resolvconf/resolvconf_${PV}.tar.gz"

SRC_URI[md5sum] = "4a62b7ce617518a5567c9e8c47fa7a41"
SRC_URI[sha256sum] = "5299a5d7a44b8e09fca31fe246aa199cd6938195e597762c1cc97c1f9d93ad38"

inherit allarch

do_compile () {
	:
}

do_install () {
	install -d ${D}${sysconfdir} ${D}${base_sbindir} ${D}${localstatedir}/volatile/run/resolvconf/interface
	install -d ${D}${mandir}/man8 ${D}${docdir}/${P}
	cp -pPR etc/* ${D}${sysconfdir}/
	chown -R root:root ${D}${sysconfdir}/
	install -m 0755 bin/resolvconf ${D}${base_sbindir}/
	install -m 0644 README ${D}${docdir}/${P}/
	install -m 0644 man/resolvconf.8 ${D}${mandir}/man8/
}
