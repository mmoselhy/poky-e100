#
# Makefile.in/Makefile, build rules for pseudo
#
# Copyright (c) 2008-2010 Wind River Systems, Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the Lesser GNU General Public License version 2.1 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the Lesser GNU General Public License for more details.
#
# You should have received a copy of the Lesser GNU General Public License
# version 2.1 along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
#

# configuration flags
PREFIX=/media/OE/poky/meta-ettus/recipes/hello/build/tmp/sysroots/x86_64-linux/usr
LIBDIR=/media/OE/poky/meta-ettus/recipes/hello/build/tmp/sysroots/x86_64-linux/usr/lib/pseudo/lib64
SUFFIX=
SQLITE=/media/OE/poky/meta-ettus/recipes/hello/build/tmp/sysroots/x86_64-linux/usr
BITS=64
MARK64=64
RPATH=-Wl,-R$(SQLITE)/lib
VERSION=1.2

LIB=lib/pseudo/lib64
BIN=bin
LOCALSTATE=var/pseudo
BINDIR=$(PREFIX)/$(BIN)
LOCALSTATEDIR=$(PREFIX)/$(LOCALSTATE)

CFLAGS_BASE=-pipe -std=gnu99 -Wall -W -Wextra
CFLAGS_CODE=-fPIC -D_LARGEFILE64_SOURCE -D_ATFILE_SOURCE
ifneq ($(BITS),)
    CFLAGS_CODE += -m$(BITS)
endif
CFLAGS_DEFS=-DPSEUDO_PREFIX='"$(PREFIX)"' -DPSEUDO_SUFFIX='"$(SUFFIX)"' -DPSEUDO_BINDIR='"$(BIN)"' -DPSEUDO_LIBDIR='"$(LIB)"' -DPSEUDO_LOCALSTATEDIR='"$(LOCALSTATE)"' -DPSEUDO_VERSION='"$(VERSION)"'
CFLAGS_DEBUG=-O2 -g
CFLAGS_SQL=-L$(SQLITE)/lib -I$(SQLITE)/include $(RPATH)
CFLAGS_PSEUDO=$(CFLAGS_BASE) $(CFLAGS_CODE) $(CFLAGS_DEFS) \
	$(CFLAGS_DEBUG) $(CFLAGS_SQL)

GLOB_PATTERN=guts/*.c
GUTS=$(filter-out "$(GLOB_PATTERN)",$(wildcard $(GLOB_PATTERN)))

SOURCES=$(wildcard *.c)
OBJS=$(subst .c,.o,$(SOURCES))

SHOBJS=pseudo_tables.o pseudo_util.o
DBOBJS=pseudo_db.o
WRAPOBJS=pseudo_wrappers.o

# needed for anything that links with pseduo_client.o, pretty much
CLIENT_LDFLAGS=-ldl -lpthread
DB_LDFLAGS=$(SQLITE)/lib/libsqlite3.a -lpthread

PSEUDO=$(BIN)/pseudo
PSEUDODB=$(BIN)/pseudodb
PSEUDOLOG=$(BIN)/pseudolog
LIBPSEUDO=$(LIB)/libpseudo.so

TEMPLATES=templates/guts templates/wrapfuncs.c templates/wrapfuncs.h templates/wrapper_table
TABLES=table_templates/pseudo_tables.c table_templates/pseudo_tables.h

all: $(LIBPSEUDO) $(PSEUDO) $(PSEUDODB) $(PSEUDOLOG)

test: all $(BIN) $(LIB) $(LOCALSTATE)
	@./run_tests.sh -v

install-lib: $(LIBPSEUDO)
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $(LIBPSEUDO) $(DESTDIR)$(LIBDIR)
	$(if $(SUFFIX),cp $(LIBPSEUDO) $(DESTDIR)$(LIBDIR)/libpseudo$(SUFFIX).so,:)

install-bin: $(PSEUDO) $(PSEUDODB) $(PSEUDOLOG)
	mkdir -p $(DESTDIR)$(BINDIR)
	cp $(PSEUDO) $(PSEUDODB) $(PSEUDOLOG) $(DESTDIR)$(BINDIR)

install-data:
	mkdir -p $(DESTDIR)$(LOCALSTATEDIR)

install: all install-lib install-bin install-data

$(BIN) $(LIB) $(LOCALSTATE):
	mkdir -p $@

pseudo: $(PSEUDO)

$(PSEUDO): $(BIN) pseudo.o $(SHOBJS) $(DBOBJS) pseudo_client.o pseudo_server.o pseudo_ipc.o
	$(CC) $(CFLAGS) $(CFLAGS_PSEUDO) -o $(PSEUDO) \
		pseudo.o pseudo_server.o pseudo_client.o pseudo_ipc.o \
		$(DBOBJS) $(SHOBJS) $(DB_LDFLAGS) $(CLIENT_LDFLAGS)

pseudolog: $(PSEUDOLOG)

$(PSEUDOLOG): $(BIN) pseudolog.o $(SHOBJS) $(DBOBJS) pseudo_client.o pseudo_ipc.o
	$(CC) $(CFLAGS) $(CFLAGS_PSEUDO) -o $(PSEUDOLOG) pseudolog.o pseudo_client.o pseudo_ipc.o \
		$(DBOBJS) $(SHOBJS) $(DB_LDFLAGS) $(CLIENT_LDFLAGS)

pseudodb: $(PSEUDODB)

$(PSEUDODB): $(BIN) pseudodb.o $(SHOBJS) $(DBOBJS) pseudo_ipc.o
	$(CC) $(CFLAGS) $(CFLAGS_PSEUDO) -o $(PSEUDODB) pseudodb.o \
		$(DBOBJS) $(SHOBJS) pseudo_ipc.o $(DB_LDFLAGS) $(CLIENT_LDFLAGS)

libpseudo: $(LIBPSEUDO)

$(LIBPSEUDO): $(LIB) $(WRAPOBJS) pseudo_client.o pseudo_ipc.o $(SHOBJS)
	$(CC) $(CFLAGS) $(CFLAGS_PSEUDO) -shared -o $(LIBPSEUDO) \
		pseudo_client.o pseudo_ipc.o \
		$(WRAPOBJS) $(SHOBJS) $(CLIENT_LDFLAGS)

# *everything* now relies on stuff that's generated in the
# wrapper process.
%.o: %.c pseudo_wrapfuncs.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $(CFLAGS_PSEUDO) $<

$(OBJS): pseudo_tables.h

pseudo_client.o pseudo_server.o pseudo_ipc.o: pseudo_ipc.h

pseudo_client.o: pseudo_client.h

pseudo_server.o: pseudo_server.h

tables: enums/*.in maketables templatefile.py $(TABLES)
	./maketables enums/*.in

wrappers: makewrappers templatefile.py $(TEMPLATES) ports/*/wrapfuncs.in
	./makewrappers

.SECONDARY: tables wrappers

pseudo_wrapfuncs.c pseudo_wrapfuncs.h: wrappers

pseudo_tables.c pseudo_tables.h: tables

pseudo_tables.o: pseudo_tables.c
	$(CC) $(CFLAGS) $(CFLAGS_PSEUDO) -c -o pseudo_tables.o pseudo_tables.c

# no-strict-aliasing is needed for the function pointer trickery.
pseudo_wrappers.o: $(GUTS) pseudo_wrappers.c pseudo_wrapfuncs.c pseudo_wrapfuncs.h pseudo_tables.h
	$(CC) -fno-strict-aliasing $(CFLAGS) $(CFLAGS_PSEUDO) -D_GNU_SOURCE -c -o pseudo_wrappers.o pseudo_wrappers.c

offsets32:
	$(CC) -m32 -o offsets32 offsets.c

offsets64:
	$(CC) -m64 -o offsets64 offsets.c

clean:
	rm -f *.o *.so $(PSEUDO) $(PSEUDODB) $(PSEUDOLOG) \
		pseudo_wrapfuncs.h pseudo_wrapfuncs.c \
		pseudo_wrapper_table.c \
		pseudo_tables.c pseudo_tables.h \
		pseudo_ports.h port_wrappers.c \
		offsets32 offsets64

distclean: clean
	rm -f Makefile
	rm -rf ./$(BIN) ./$(LIB) ./$(LOCALSTATE)
	@echo "WARNING: Makefile has been removed.  You must reconfigure to do anything else."

nuke: distclean
	case "$(PREFIX)" in "`pwd`"/*) rm -rf "$(PREFIX)";; esac
	@echo "WARNING: Removed $(PREFIX)."

tarball:
	@test -d .git || ( echo >&2 "Tarball can only be made from git tree."; exit 1)
	rm -rf pseudo-$(VERSION)
	mkdir -p pseudo-$(VERSION)
	( parent=$(PWD); \
	  cd pseudo-$(VERSION) && \
	  git clone $$parent && \
	  mv pseudo/* . && \
	  rm -rf pseudo/.git* && \
	  rmdir pseudo \
	)
	tar czf pseudo-$(VERSION).tgz pseudo-$(VERSION)
