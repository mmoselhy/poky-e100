require gdb-common.inc
require gdb-cross-canadian.inc

PR = "${INC_PR}.3"

GDBPROPREFIX = "--program-prefix='${TARGET_PREFIX}'"
EXPAT = "--with-expat"

S = "${WORKDIR}/${BPN}-${PV}"
