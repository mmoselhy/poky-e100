/*
 * Copyright (c) 2008-2010 Wind River Systems, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License version 2.1 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * version 2.1 along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
 *
 */
/* #defines for port-specific hackery */
#define PSEUDO_PORT_COMMON 1
/* no portdefs for common */
#define PSEUDO_PORT_LINUX 1
#include "ports/linux/portdefs.h"
#define PSEUDO_PORT_UNIX 1
/* no portdefs for unix */
#define PSEUDO_PORT_UIDS_GENERIC 1
/* no portdefs for uids_generic */
#define PSEUDO_PORT_LINUX_NEWCLONE 1
/* no portdefs for linux/newclone */
