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
/* Tables matching enums to strings */

/* This file is generated and should not be modified.  See the maketables
 * script if you want to modify this. */

#include "pseudo_tables.h"

/* tables for msg_type */

static const char *msg_type_id_to_name[] = {
	"none",
	"ping",
	"shutdown",
	"op",
	"ack",
	"nak",
	NULL
};


/* functions for msg_type */
extern const char *
pseudo_msg_type_name(pseudo_msg_type_t id) {
	if (id < 0 || id >= PSEUDO_MSG_MAX)
		return "unknown";
	return msg_type_id_to_name[id];
}

extern pseudo_msg_type_t
pseudo_msg_type_id(const char *name) {
	int id;

	if (!name)
		return -1;

	for (id = 0; id < PSEUDO_MSG_MAX; ++id)
		if (!strcmp(msg_type_id_to_name[id], name))
			return id;

	return -1;
}


/* tables for op */

static const char *op_id_to_name[] = {
	"none",
	"chdir",
	"chmod",
	"chown",
	"chroot",
	"close",
	"creat",
	"dup",
	"fchmod",
	"fchown",
	"fstat",
	"link",
	"mkdir",
	"mknod",
	"open",
	"rename",
	"stat",
	"unlink",
	"symlink",
	"exec",
	"may-unlink",
	"did-unlink",
	"cancel-unlink",
	NULL
};


/* functions for op */
extern const char *
pseudo_op_name(pseudo_op_t id) {
	if (id < 0 || id >= OP_MAX)
		return "unknown";
	return op_id_to_name[id];
}

extern pseudo_op_t
pseudo_op_id(const char *name) {
	int id;

	if (!name)
		return -1;

	for (id = 0; id < OP_MAX; ++id)
		if (!strcmp(op_id_to_name[id], name))
			return id;

	return -1;
}


/* tables for query_field */

static const char *query_field_id_to_name[] = {
	"none",
	"access",
	"client",
	"dev",
	"fd",
	"ftype",
	"gid",
	"id",
	"inode",
	"mode",
	"op",
	"order",
	"path",
	"perm",
	"program",
	"result",
	"severity",
	"stamp",
	"tag",
	"text",
	"type",
	"uid",
	NULL
};


/* functions for query_field */
extern const char *
pseudo_query_field_name(pseudo_query_field_t id) {
	if (id < 0 || id >= PSQF_MAX)
		return "unknown";
	return query_field_id_to_name[id];
}

extern pseudo_query_field_t
pseudo_query_field_id(const char *name) {
	int id;

	if (!name)
		return -1;

	for (id = 0; id < PSQF_MAX; ++id)
		if (!strcmp(query_field_id_to_name[id], name))
			return id;

	return -1;
}


/* tables for query_type */

static const char *query_type_id_to_name[] = {
	"none",
	"exact",
	"less",
	"greater",
	"bitand",
	"notequal",
	"like",
	"notlike",
	"sqlpat",
	NULL
};
static const char *query_type_id_to_sql[] = {
	"LITTLE BOBBY TABLES",
	"=",
	"<",
	">",
	"&",
	"!=",
	"LIKE",
	"NOT LIKE",
	"LIKE",
	NULL
};

/* functions for query_type */
extern const char *
pseudo_query_type_name(pseudo_query_type_t id) {
	if (id < 0 || id >= PSQT_MAX)
		return "unknown";
	return query_type_id_to_name[id];
}

extern pseudo_query_type_t
pseudo_query_type_id(const char *name) {
	int id;

	if (!name)
		return -1;

	for (id = 0; id < PSQT_MAX; ++id)
		if (!strcmp(query_type_id_to_name[id], name))
			return id;

	return -1;
}
extern const char *
pseudo_query_type_sql(pseudo_query_type_t id) {
	if (id < 0 || id >= PSQT_MAX)
		return "LITTLE BOBBY TABLES";
	return query_type_id_to_sql[id];
}

/* tables for res */

static const char *res_id_to_name[] = {
	"none",
	"succeed",
	"fail",
	"error",
	NULL
};


/* functions for res */
extern const char *
pseudo_res_name(pseudo_res_t id) {
	if (id < 0 || id >= RESULT_MAX)
		return "unknown";
	return res_id_to_name[id];
}

extern pseudo_res_t
pseudo_res_id(const char *name) {
	int id;

	if (!name)
		return -1;

	for (id = 0; id < RESULT_MAX; ++id)
		if (!strcmp(res_id_to_name[id], name))
			return id;

	return -1;
}


/* tables for sev */

static const char *sev_id_to_name[] = {
	"none",
	"debug",
	"info",
	"warn",
	"error",
	"critical",
	NULL
};


/* functions for sev */
extern const char *
pseudo_sev_name(pseudo_sev_t id) {
	if (id < 0 || id >= SEVERITY_MAX)
		return "unknown";
	return sev_id_to_name[id];
}

extern pseudo_sev_t
pseudo_sev_id(const char *name) {
	int id;

	if (!name)
		return -1;

	for (id = 0; id < SEVERITY_MAX; ++id)
		if (!strcmp(sev_id_to_name[id], name))
			return id;

	return -1;
}


