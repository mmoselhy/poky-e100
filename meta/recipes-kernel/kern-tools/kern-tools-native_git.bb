DESCRIPTION = "Scripts and utilities for managing Yocto branched kernels."
LICENSE = "GPL"
LIC_FILES_CHKSUM = "file://git/tools/kgit;beginline=5;endline=9;md5=e2bf4415f3d843f43d2e22b0d91a6fee"

DEPENDS = "git-native guilt-native"

SRCREV = "91c2b184be90d6654996887203efdd7f1727a19a"
PR = "r12"
PV = "0.1+git${SRCPV}"

inherit native

SRC_URI = "git://git.yoctoproject.org/yocto-kernel-tools.git;protocol=git"
S = "${WORKDIR}"

do_compile() { 
	:
}

do_install() {
	cd ${S}/git
	make DESTDIR=${D}${bindir} install
}
