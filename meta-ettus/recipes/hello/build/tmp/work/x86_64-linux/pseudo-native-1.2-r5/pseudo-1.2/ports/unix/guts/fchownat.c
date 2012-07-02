/* 
 * Copyright (c) 2008-2010 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * static int
 * wrap_fchownat(int dirfd, const char *path, uid_t owner, gid_t group, int flags) {
 *	int rc = -1;
 */
 	pseudo_msg_t *msg;
	struct stat buf;
	int save_errno;
	int doing_link = 0;

#ifdef PSEUDO_NO_REAL_AT_FUNCTIONS
	if (dirfd != AT_FDCWD) {
		errno = ENOSYS;
		return -1;
	}
	if (flags & AT_SYMLINK_NOFOLLOW) {
		rc = real_lstat(path, &buf);
	} else {
		rc = real_stat(path, &buf);
	}
#else
	rc = real___fxstatat(_STAT_VER, dirfd, path, &buf, flags);
#endif
	if (rc == -1) {
		return rc;
	}
	/* pseudo won't track the ownership, here */
	if (S_ISLNK(buf.st_mode)) {
		doing_link = 1;
	}
	save_errno = errno;

	if (owner == (uid_t) -1 || group == (gid_t) -1) {
		msg = pseudo_client_op_plain(OP_STAT, 0, -1, -1, path, &buf);
		/* copy in any existing values... */
		if (msg) {
			if (msg->result == RESULT_SUCCEED) {
				pseudo_stat_msg_plain(&buf, msg);
			} else {
				pseudo_debug(2, "chownat to %d:%d on %d/%s, ino %llu, new file.\n",
					owner, group, dirfd, path,
					(unsigned long long) buf.st_ino);
			}
		}
	}
	/* now override with arguments */
	if (owner != (uid_t) -1) {
		buf.st_uid = owner;
	}
	if (group != (gid_t) -1) {
		buf.st_gid = group;
	}
	msg = pseudo_client_op_plain(OP_CHOWN, 0, -1, dirfd, path, &buf);
	if (msg && msg->result != RESULT_SUCCEED) {
		errno = EPERM;
		rc = -1;
	} else {
		/* just pretend we worked */
		rc = 0;
	}

/*	return rc;
 * }
 */
