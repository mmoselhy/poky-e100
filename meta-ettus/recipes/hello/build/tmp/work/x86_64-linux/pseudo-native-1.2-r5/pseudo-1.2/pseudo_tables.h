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
/* standard ranges/values/keys */

/* This file is generated and should not be modified.  See the maketables
 * script if you want to modify this. */

/* NULL, strcmp */
#include <string.h>
/* tables for msg_type */

typedef enum {
	PSEUDO_MSG_UNKNOWN = -1,
	PSEUDO_MSG_NONE = 0,
	PSEUDO_MSG_PING,
	PSEUDO_MSG_SHUTDOWN,
	PSEUDO_MSG_OP,
	PSEUDO_MSG_ACK,
	PSEUDO_MSG_NAK,
	PSEUDO_MSG_MAX
} pseudo_msg_type_t;
extern const char *pseudo_msg_type_name(pseudo_msg_type_t);
extern pseudo_msg_type_t pseudo_msg_type_id(const char *);


/* tables for op */

typedef enum {
	OP_UNKNOWN = -1,
	OP_NONE = 0,
	OP_CHDIR,
	OP_CHMOD,
	OP_CHOWN,
	OP_CHROOT,
	OP_CLOSE,
	OP_CREAT,
	OP_DUP,
	OP_FCHMOD,
	OP_FCHOWN,
	OP_FSTAT,
	OP_LINK,
	OP_MKDIR,
	OP_MKNOD,
	OP_OPEN,
	OP_RENAME,
	OP_STAT,
	OP_UNLINK,
	OP_SYMLINK,
	OP_EXEC,
	OP_MAY_UNLINK,
	OP_DID_UNLINK,
	OP_CANCEL_UNLINK,
	OP_MAX
} pseudo_op_t;
extern const char *pseudo_op_name(pseudo_op_t);
extern pseudo_op_t pseudo_op_id(const char *);


/* tables for query_field */
/* Note:  These are later used as bitwise masks into a value,
 * currently an unsigned long; if the number of these gets up
 * near 32, that may take rethinking.  The first thing to
 * go would probably be something special to do for FTYPE and
 * PERM because they aren't "real" database fields -- both
 * of them actually imply MODE. */

typedef enum {
	PSQF_UNKNOWN = -1,
	PSQF_NONE = 0,
	PSQF_ACCESS,
	PSQF_CLIENT,
	PSQF_DEV,
	PSQF_FD,
	PSQF_FTYPE,
	PSQF_GID,
	PSQF_ID,
	PSQF_INODE,
	PSQF_MODE,
	PSQF_OP,
	PSQF_ORDER,
	PSQF_PATH,
	PSQF_PERM,
	PSQF_PROGRAM,
	PSQF_RESULT,
	PSQF_SEVERITY,
	PSQF_STAMP,
	PSQF_TAG,
	PSQF_TEXT,
	PSQF_TYPE,
	PSQF_UID,
	PSQF_MAX
} pseudo_query_field_t;
extern const char *pseudo_query_field_name(pseudo_query_field_t);
extern pseudo_query_field_t pseudo_query_field_id(const char *);


/* tables for query_type */

typedef enum {
	PSQT_UNKNOWN = -1,
	PSQT_NONE = 0,
	PSQT_EXACT,
	PSQT_LESS,
	PSQT_GREATER,
	PSQT_BITAND,
	PSQT_NOTEQUAL,
	PSQT_LIKE,
	PSQT_NOTLIKE,
	PSQT_SQLPAT,
	PSQT_MAX
} pseudo_query_type_t;
extern const char *pseudo_query_type_name(pseudo_query_type_t);
extern pseudo_query_type_t pseudo_query_type_id(const char *);
extern const char *pseudo_query_type_sql(pseudo_query_type_t id);

/* tables for res */

typedef enum {
	RESULT_UNKNOWN = -1,
	RESULT_NONE = 0,
	RESULT_SUCCEED,
	RESULT_FAIL,
	RESULT_ERROR,
	RESULT_MAX
} pseudo_res_t;
extern const char *pseudo_res_name(pseudo_res_t);
extern pseudo_res_t pseudo_res_id(const char *);


/* tables for sev */

typedef enum {
	SEVERITY_UNKNOWN = -1,
	SEVERITY_NONE = 0,
	SEVERITY_DEBUG,
	SEVERITY_INFO,
	SEVERITY_WARN,
	SEVERITY_ERROR,
	SEVERITY_CRITICAL,
	SEVERITY_MAX
} pseudo_sev_t;
extern const char *pseudo_sev_name(pseudo_sev_t);
extern pseudo_sev_t pseudo_sev_id(const char *);


