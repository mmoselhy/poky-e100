require gst-plugins.inc

LICENSE = "GPLv2+ & LGPLv2+ & LGPLv2.1+ "
LIC_FILES_CHKSUM = "file://COPYING;md5=0636e73ff0215e8d672dc4c32c317bb3 \
                    file://gst/tta/filters.h;beginline=12;endline=29;md5=629b0c7a665d155a6677778f4460ec06 \
                    file://COPYING.LIB;md5=55ca817ccb7d5b5b66355690e9abc605 \
                    file://gst/tta/crc32.h;beginline=12;endline=29;md5=71a904d99ce7ae0c1cf129891b98145c"

DEPENDS += "gst-plugins-base libmusicbrainz tremor librsvg"

PR = "r3"

inherit gettext

EXTRA_OECONF += "--disable-examples --disable-experimental --disable-sdl --disable-cdaudio --disable-directfb \
                 --with-plugins=musicbrainz,wavpack,ivorbis,mpegvideoparse --disable-vdpau --disable-apexsink"

ARM_INSTRUCTION_SET = "arm"

do_configure_prepend() {
	# This m4 file contains nastiness which conflicts with libtool 2.2.2
	rm ${S}/m4/lib-link.m4 || true
}

SRC_URI[md5sum] = "9a2acee1f386f71247003d0d7090fb1c"
SRC_URI[sha256sum] = "d8f7102f43ffea076646427115ffdccb3975954f1e9367bd304f7ee01e12070c"
