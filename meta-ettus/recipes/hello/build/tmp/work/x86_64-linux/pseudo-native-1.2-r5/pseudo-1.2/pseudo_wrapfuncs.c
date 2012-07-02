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
/* wrapper functions. generated automatically. */

/* IF YOU ARE SEEING COMPILER ERRORS IN THIS FILE:
 * If you are seeing a whole lot of errors, make sure you aren't actually
 * trying to compile pseudo_wrapfuncs.c directly.  This file is #included
 * from pseudo_wrappers.c, which has a lot of needed include files and
 * static declarations.
 */

/* This file is generated and should not be modified.  See the makewrappers
 * script if you want to modify this. */

static int (*real___fxstat)(int ver, int fd, struct stat *buf) = NULL;



int
__fxstat(int ver, int fd, struct stat *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___fxstat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__fxstat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___fxstat)(ver, fd, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: __fxstat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___fxstat)(ver, fd, buf);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___fxstat(ver, fd, buf);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __fxstat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __fxstat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___fxstat(int ver, int fd, struct stat *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/__fxstat.c"

	return rc;
}



static int (*real___fxstat64)(int ver, int fd, struct stat64 *buf) = NULL;



int
__fxstat64(int ver, int fd, struct stat64 *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___fxstat64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__fxstat64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___fxstat64)(ver, fd, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: __fxstat64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___fxstat64)(ver, fd, buf);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___fxstat64(ver, fd, buf);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __fxstat64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __fxstat64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___fxstat64(int ver, int fd, struct stat64 *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/__fxstat64.c"

	return rc;
}



static int (*real___fxstatat)(int ver, int dirfd, const char *path, struct stat *buf, int flags) = NULL;



int
__fxstatat(int ver, int dirfd, const char *path, struct stat *buf, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___fxstatat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__fxstatat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___fxstatat)(ver, dirfd, path, buf, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: __fxstatat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___fxstatat)(ver, dirfd, path, buf, flags);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, flags);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___fxstatat(ver, dirfd, path, buf, flags);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __fxstatat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __fxstatat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___fxstatat(int ver, int dirfd, const char *path, struct stat *buf, int flags) {
	int rc = -1;
	
	

#include "ports/linux/guts/__fxstatat.c"

	return rc;
}



static int (*real___fxstatat64)(int ver, int dirfd, const char *path, struct stat64 *buf, int flags) = NULL;



int
__fxstatat64(int ver, int dirfd, const char *path, struct stat64 *buf, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___fxstatat64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__fxstatat64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___fxstatat64)(ver, dirfd, path, buf, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: __fxstatat64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___fxstatat64)(ver, dirfd, path, buf, flags);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, flags);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___fxstatat64(ver, dirfd, path, buf, flags);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __fxstatat64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __fxstatat64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___fxstatat64(int ver, int dirfd, const char *path, struct stat64 *buf, int flags) {
	int rc = -1;
	
	

#include "ports/linux/guts/__fxstatat64.c"

	return rc;
}



static int (*real___lxstat)(int ver, const char *path, struct stat *buf) = NULL;



int
__lxstat(int ver, const char *path, struct stat *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___lxstat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__lxstat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___lxstat)(ver, path, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: __lxstat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___lxstat)(ver, path, buf);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___lxstat(ver, path, buf);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __lxstat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __lxstat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___lxstat(int ver, const char *path, struct stat *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/__lxstat.c"

	return rc;
}



static int (*real___lxstat64)(int ver, const char *path, struct stat64 *buf) = NULL;



int
__lxstat64(int ver, const char *path, struct stat64 *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___lxstat64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__lxstat64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___lxstat64)(ver, path, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: __lxstat64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___lxstat64)(ver, path, buf);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___lxstat64(ver, path, buf);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __lxstat64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __lxstat64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___lxstat64(int ver, const char *path, struct stat64 *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/__lxstat64.c"

	return rc;
}



static int (*real___openat64_2)(int dirfd, const char *path, int flags) = NULL;



int
__openat64_2(int dirfd, const char *path, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___openat64_2) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__openat64_2");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___openat64_2)(dirfd, path, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: __openat64_2\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___openat64_2)(dirfd, path, flags);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___openat64_2(dirfd, path, flags);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __openat64_2 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __openat64_2 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___openat64_2(int dirfd, const char *path, int flags) {
	int rc = -1;
	
	

#include "ports/linux/guts/__openat64_2.c"

	return rc;
}



static int (*real___openat_2)(int dirfd, const char *path, int flags) = NULL;



int
__openat_2(int dirfd, const char *path, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___openat_2) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__openat_2");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___openat_2)(dirfd, path, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: __openat_2\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___openat_2)(dirfd, path, flags);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, flags);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___openat_2(dirfd, path, flags);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __openat_2 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __openat_2 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___openat_2(int dirfd, const char *path, int flags) {
	int rc = -1;
	
	

#include "ports/linux/guts/__openat_2.c"

	return rc;
}



static int (*real___xmknod)(int ver, const char *path, mode_t mode, dev_t *dev) = NULL;



int
__xmknod(int ver, const char *path, mode_t mode, dev_t *dev) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___xmknod) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__xmknod");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___xmknod)(ver, path, mode, dev);
		
		return rc;
	}

	pseudo_debug(4, "called: __xmknod\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___xmknod)(ver, path, mode, dev);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___xmknod(ver, path, mode, dev);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __xmknod (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __xmknod (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___xmknod(int ver, const char *path, mode_t mode, dev_t *dev) {
	int rc = -1;
	
	

#include "ports/linux/guts/__xmknod.c"

	return rc;
}



static int (*real___xmknodat)(int ver, int dirfd, const char *path, mode_t mode, dev_t *dev) = NULL;



int
__xmknodat(int ver, int dirfd, const char *path, mode_t mode, dev_t *dev) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___xmknodat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__xmknodat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___xmknodat)(ver, dirfd, path, mode, dev);
		
		return rc;
	}

	pseudo_debug(4, "called: __xmknodat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___xmknodat)(ver, dirfd, path, mode, dev);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___xmknodat(ver, dirfd, path, mode, dev);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __xmknodat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __xmknodat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___xmknodat(int ver, int dirfd, const char *path, mode_t mode, dev_t *dev) {
	int rc = -1;
	
	

#include "ports/linux/guts/__xmknodat.c"

	return rc;
}



static int (*real___xstat)(int ver, const char *path, struct stat *buf) = NULL;



int
__xstat(int ver, const char *path, struct stat *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___xstat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__xstat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___xstat)(ver, path, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: __xstat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___xstat)(ver, path, buf);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___xstat(ver, path, buf);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __xstat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __xstat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___xstat(int ver, const char *path, struct stat *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/__xstat.c"

	return rc;
}



static int (*real___xstat64)(int ver, const char *path, struct stat64 *buf) = NULL;



int
__xstat64(int ver, const char *path, struct stat64 *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real___xstat64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("__xstat64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real___xstat64)(ver, path, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: __xstat64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real___xstat64)(ver, path, buf);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap___xstat64(ver, path, buf);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: __xstat64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: __xstat64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap___xstat64(int ver, const char *path, struct stat64 *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/__xstat64.c"

	return rc;
}



static int (*real_access)(const char *path, int mode) = NULL;



int
access(const char *path, int mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_access) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("access");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_access)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: access\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_access)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_access(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: access (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: access (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_access(const char *path, int mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/access.c"

	return rc;
}



static int (*real_acct)(const char *path) = NULL;



int
acct(const char *path) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_acct) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("acct");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_acct)(path);
		
		return rc;
	}

	pseudo_debug(4, "called: acct\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_acct)(path);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_acct(path);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: acct (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: acct (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_acct(const char *path) {
	int rc = -1;
	
	

#include "ports/unix/guts/acct.c"

	return rc;
}



static char * (*real_canonicalize_file_name)(const char *filename) = NULL;



char *
canonicalize_file_name(const char *filename) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_canonicalize_file_name) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("canonicalize_file_name");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_canonicalize_file_name)(filename);
		
		return rc;
	}

	pseudo_debug(4, "called: canonicalize_file_name\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_canonicalize_file_name)(filename);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_canonicalize_file_name(filename);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: canonicalize_file_name (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: canonicalize_file_name (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_canonicalize_file_name(const char *filename) {
	char *rc = NULL;
	
	

#include "ports/linux/guts/canonicalize_file_name.c"

	return rc;
}



static int (*real_chdir)(const char *path) = NULL;



int
chdir(const char *path) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_chdir) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("chdir");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_chdir)(path);
		
		return rc;
	}

	pseudo_debug(4, "called: chdir\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_chdir)(path);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_chdir(path);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: chdir (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: chdir (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_chdir(const char *path) {
	int rc = -1;
	
	

#include "ports/unix/guts/chdir.c"

	return rc;
}



static int (*real_chmod)(const char *path, mode_t mode) = NULL;



int
chmod(const char *path, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_chmod) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("chmod");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_chmod)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: chmod\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_chmod)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_chmod(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: chmod (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: chmod (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_chmod(const char *path, mode_t mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/chmod.c"

	return rc;
}



static int (*real_chown)(const char *path, uid_t owner, gid_t group) = NULL;



int
chown(const char *path, uid_t owner, gid_t group) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_chown) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("chown");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_chown)(path, owner, group);
		
		return rc;
	}

	pseudo_debug(4, "called: chown\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_chown)(path, owner, group);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_chown(path, owner, group);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: chown (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: chown (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_chown(const char *path, uid_t owner, gid_t group) {
	int rc = -1;
	
	

#include "ports/unix/guts/chown.c"

	return rc;
}



static int (*real_chroot)(const char *path) = NULL;



int
chroot(const char *path) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_chroot) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("chroot");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_chroot)(path);
		
		return rc;
	}

	pseudo_debug(4, "called: chroot\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_chroot)(path);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_chroot(path);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: chroot (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: chroot (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_chroot(const char *path) {
	int rc = -1;
	
	

#include "ports/unix/guts/chroot.c"

	return rc;
}



static int (*real_clone)(int (*fn)(void *), void *child_stack, int flags, void *arg, ...) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
clone(int (*fn)(void *), void *child_stack, int flags, void *arg, ...) {
	sigset_t saved;
	va_list ap;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_clone) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("clone");
		return rc;
	}

	va_start(ap, arg);


	if (pseudo_disabled) {
		rc = (*real_clone)(fn, child_stack, flags, arg, ap);
		
		return rc;
	}

	pseudo_debug(4, "called: clone\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_clone)(fn, child_stack, flags, arg, ap);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_clone(fn, child_stack, flags, arg, ap);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: clone (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: clone (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_clone(int (*fn)(void *), void *child_stack, int flags, void *arg, va_list ap) {
	int rc = -1;
	
	

#include "ports/linux/newclone/guts/clone.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_close)(int fd) = NULL;



int
close(int fd) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_close) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("close");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_close)(fd);
		
		return rc;
	}

	pseudo_debug(4, "called: close\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_close)(fd);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_close(fd);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: close (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: close (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_close(int fd) {
	int rc = -1;
	
	

#include "ports/unix/guts/close.c"

	return rc;
}



static int (*real_closedir)(DIR *dirp) = NULL;



int
closedir(DIR *dirp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_closedir) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("closedir");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_closedir)(dirp);
		
		return rc;
	}

	pseudo_debug(4, "called: closedir\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_closedir)(dirp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_closedir(dirp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: closedir (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: closedir (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_closedir(DIR *dirp) {
	int rc = -1;
	
	

#include "ports/unix/guts/closedir.c"

	return rc;
}



static int (*real_creat)(const char *path, mode_t mode) = NULL;



int
creat(const char *path, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_creat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("creat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_creat)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: creat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_creat)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_creat(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: creat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: creat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_creat(const char *path, mode_t mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/creat.c"

	return rc;
}



static int (*real_creat64)(const char *path, mode_t mode) = NULL;



int
creat64(const char *path, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_creat64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("creat64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_creat64)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: creat64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_creat64)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_creat64(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: creat64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: creat64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_creat64(const char *path, mode_t mode) {
	int rc = -1;
	
	

#include "ports/linux/guts/creat64.c"

	return rc;
}



static int (*real_dup)(int fd) = NULL;



int
dup(int fd) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_dup) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("dup");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_dup)(fd);
		
		return rc;
	}

	pseudo_debug(4, "called: dup\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_dup)(fd);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_dup(fd);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: dup (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: dup (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_dup(int fd) {
	int rc = -1;
	
	

#include "ports/unix/guts/dup.c"

	return rc;
}



static int (*real_dup2)(int oldfd, int newfd) = NULL;



int
dup2(int oldfd, int newfd) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_dup2) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("dup2");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_dup2)(oldfd, newfd);
		
		return rc;
	}

	pseudo_debug(4, "called: dup2\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_dup2)(oldfd, newfd);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_dup2(oldfd, newfd);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: dup2 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: dup2 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_dup2(int oldfd, int newfd) {
	int rc = -1;
	
	

#include "ports/unix/guts/dup2.c"

	return rc;
}



static int (*real_eaccess)(const char *path, int mode) = NULL;



int
eaccess(const char *path, int mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_eaccess) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("eaccess");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_eaccess)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: eaccess\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_eaccess)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_eaccess(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: eaccess (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: eaccess (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_eaccess(const char *path, int mode) {
	int rc = -1;
	
	

#include "ports/linux/guts/eaccess.c"

	return rc;
}



static void (*real_endgrent)(void) = NULL;



void
endgrent(void) {
	sigset_t saved;
	
	

	if (!pseudo_check_wrappers() || !real_endgrent) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("endgrent");
		return;
	}

	

	if (pseudo_disabled) {
		(void) (*real_endgrent)();
		
		return;
	}

	pseudo_debug(4, "called: endgrent\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		(void) (*real_endgrent)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		(void) wrap_endgrent();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: endgrent (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: endgrent (errno: %d)\n", save_errno);
	errno = save_errno;
	return;
}

static void
wrap_endgrent(void) {
	
	
	

#include "ports/uids_generic/guts/endgrent.c"

	return;
}



static void (*real_endpwent)(void) = NULL;



void
endpwent(void) {
	sigset_t saved;
	
	

	if (!pseudo_check_wrappers() || !real_endpwent) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("endpwent");
		return;
	}

	

	if (pseudo_disabled) {
		(void) (*real_endpwent)();
		
		return;
	}

	pseudo_debug(4, "called: endpwent\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		(void) (*real_endpwent)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		(void) wrap_endpwent();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: endpwent (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: endpwent (errno: %d)\n", save_errno);
	errno = save_errno;
	return;
}

static void
wrap_endpwent(void) {
	
	
	

#include "ports/uids_generic/guts/endpwent.c"

	return;
}



static int (*real_euidaccess)(const char *path, int mode) = NULL;



int
euidaccess(const char *path, int mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_euidaccess) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("euidaccess");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_euidaccess)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: euidaccess\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_euidaccess)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_euidaccess(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: euidaccess (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: euidaccess (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_euidaccess(const char *path, int mode) {
	int rc = -1;
	
	

#include "ports/linux/guts/euidaccess.c"

	return rc;
}



static int (*real_execl)(const char *file, const char *arg, ...) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
execl(const char *file, const char *arg, ...) {
	sigset_t saved;
	va_list ap;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_execl) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("execl");
		return rc;
	}

	va_start(ap, arg);


	if (pseudo_disabled) {
		rc = (*real_execl)(file, arg, ap);
		
		return rc;
	}

	pseudo_debug(4, "called: execl\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_execl)(file, arg, ap);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_execl(file, arg, ap);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: execl (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: execl (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_execl(const char *file, const char *arg, va_list ap) {
	int rc = -1;
	
	

#include "ports/common/guts/execl.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_execle)(const char *file, const char *arg, ...) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
execle(const char *file, const char *arg, ...) {
	sigset_t saved;
	va_list ap;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_execle) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("execle");
		return rc;
	}

	va_start(ap, arg);


	if (pseudo_disabled) {
		rc = (*real_execle)(file, arg, ap);
		
		return rc;
	}

	pseudo_debug(4, "called: execle\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_execle)(file, arg, ap);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_execle(file, arg, ap);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: execle (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: execle (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_execle(const char *file, const char *arg, va_list ap) {
	int rc = -1;
	
	

#include "ports/common/guts/execle.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_execlp)(const char *file, const char *arg, ...) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
execlp(const char *file, const char *arg, ...) {
	sigset_t saved;
	va_list ap;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_execlp) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("execlp");
		return rc;
	}

	va_start(ap, arg);


	if (pseudo_disabled) {
		rc = (*real_execlp)(file, arg, ap);
		
		return rc;
	}

	pseudo_debug(4, "called: execlp\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_execlp)(file, arg, ap);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_execlp(file, arg, ap);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: execlp (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: execlp (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_execlp(const char *file, const char *arg, va_list ap) {
	int rc = -1;
	
	

#include "ports/common/guts/execlp.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_execv)(const char *file, char *const *argv) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
execv(const char *file, char *const *argv) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_execv) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("execv");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_execv)(file, argv);
		
		return rc;
	}

	pseudo_debug(4, "called: execv\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_execv)(file, argv);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_execv(file, argv);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: execv (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: execv (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_execv(const char *file, char *const *argv) {
	int rc = -1;
	
	

#include "ports/common/guts/execv.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_execve)(const char *file, char *const *argv, char *const *envp) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
execve(const char *file, char *const *argv, char *const *envp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_execve) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("execve");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_execve)(file, argv, envp);
		
		return rc;
	}

	pseudo_debug(4, "called: execve\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_execve)(file, argv, envp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_execve(file, argv, envp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: execve (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: execve (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_execve(const char *file, char *const *argv, char *const *envp) {
	int rc = -1;
	
	

#include "ports/common/guts/execve.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_execvp)(const char *file, char *const *argv) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
execvp(const char *file, char *const *argv) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_execvp) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("execvp");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_execvp)(file, argv);
		
		return rc;
	}

	pseudo_debug(4, "called: execvp\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_execvp)(file, argv);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_execvp(file, argv);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: execvp (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: execvp (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_execvp(const char *file, char *const *argv) {
	int rc = -1;
	
	

#include "ports/common/guts/execvp.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_fchdir)(int dirfd) = NULL;



int
fchdir(int dirfd) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fchdir) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fchdir");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fchdir)(dirfd);
		
		return rc;
	}

	pseudo_debug(4, "called: fchdir\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fchdir)(dirfd);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fchdir(dirfd);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fchdir (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fchdir (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fchdir(int dirfd) {
	int rc = -1;
	
	

#include "ports/unix/guts/fchdir.c"

	return rc;
}



static int (*real_fchmod)(int fd, mode_t mode) = NULL;



int
fchmod(int fd, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fchmod) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fchmod");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fchmod)(fd, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: fchmod\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fchmod)(fd, mode);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fchmod(fd, mode);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fchmod (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fchmod (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fchmod(int fd, mode_t mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/fchmod.c"

	return rc;
}



static int (*real_fchmodat)(int dirfd, const char *path, mode_t mode, int flags) = NULL;



int
fchmodat(int dirfd, const char *path, mode_t mode, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fchmodat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fchmodat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fchmodat)(dirfd, path, mode, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: fchmodat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fchmodat)(dirfd, path, mode, flags);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, flags);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fchmodat(dirfd, path, mode, flags);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fchmodat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fchmodat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fchmodat(int dirfd, const char *path, mode_t mode, int flags) {
	int rc = -1;
	
	

#include "ports/unix/guts/fchmodat.c"

	return rc;
}



static int (*real_fchown)(int fd, uid_t owner, gid_t group) = NULL;



int
fchown(int fd, uid_t owner, gid_t group) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fchown) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fchown");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fchown)(fd, owner, group);
		
		return rc;
	}

	pseudo_debug(4, "called: fchown\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fchown)(fd, owner, group);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fchown(fd, owner, group);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fchown (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fchown (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fchown(int fd, uid_t owner, gid_t group) {
	int rc = -1;
	
	

#include "ports/unix/guts/fchown.c"

	return rc;
}



static int (*real_fchownat)(int dirfd, const char *path, uid_t owner, gid_t group, int flags) = NULL;



int
fchownat(int dirfd, const char *path, uid_t owner, gid_t group, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fchownat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fchownat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fchownat)(dirfd, path, owner, group, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: fchownat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fchownat)(dirfd, path, owner, group, flags);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, flags);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fchownat(dirfd, path, owner, group, flags);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fchownat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fchownat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fchownat(int dirfd, const char *path, uid_t owner, gid_t group, int flags) {
	int rc = -1;
	
	

#include "ports/unix/guts/fchownat.c"

	return rc;
}



static int (*real_fclose)(FILE *fp) = NULL;



int
fclose(FILE *fp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fclose) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fclose");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fclose)(fp);
		
		return rc;
	}

	pseudo_debug(4, "called: fclose\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fclose)(fp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fclose(fp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fclose (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fclose (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fclose(FILE *fp) {
	int rc = -1;
	
	

#include "ports/unix/guts/fclose.c"

	return rc;
}



static int (*real_fcntl)(int fd, int cmd, ... /* struct flock *lock */) = NULL;



int
fcntl(int fd, int cmd, ... /* struct flock *lock */) {
	sigset_t saved;
	va_list ap;
	struct flock *lock;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fcntl) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fcntl");
		return rc;
	}

	va_start(ap, cmd);
	lock = va_arg(ap, struct flock *);
	va_end(ap);


	if (pseudo_disabled) {
		rc = (*real_fcntl)(fd, cmd, lock);
		
		return rc;
	}

	pseudo_debug(4, "called: fcntl\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fcntl)(fd, cmd, lock);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fcntl(fd, cmd, lock);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fcntl (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fcntl (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fcntl(int fd, int cmd, ... /* struct flock *lock */) {
	int rc = -1;
	va_list ap;
	struct flock *lock;

	va_start(ap, cmd);
	lock = va_arg(ap, struct flock *);
	va_end(ap);


#include "ports/linux/guts/fcntl.c"

	return rc;
}



static ssize_t (*real_fgetxattr)(int filedes, const char *name, void *value, size_t size) = NULL;



ssize_t
fgetxattr(int filedes, const char *name, void *value, size_t size) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_fgetxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fgetxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fgetxattr)(filedes, name, value, size);
		
		return rc;
	}

	pseudo_debug(4, "called: fgetxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fgetxattr)(filedes, name, value, size);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fgetxattr(filedes, name, value, size);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fgetxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fgetxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_fgetxattr(int filedes, const char *name, void *value, size_t size) {
	ssize_t rc = -1;
	
	

#include "ports/linux/guts/fgetxattr.c"

	return rc;
}



static ssize_t (*real_flistxattr)(int filedes, char *list, size_t size) = NULL;



ssize_t
flistxattr(int filedes, char *list, size_t size) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_flistxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("flistxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_flistxattr)(filedes, list, size);
		
		return rc;
	}

	pseudo_debug(4, "called: flistxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_flistxattr)(filedes, list, size);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_flistxattr(filedes, list, size);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: flistxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: flistxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_flistxattr(int filedes, char *list, size_t size) {
	ssize_t rc = -1;
	
	

#include "ports/linux/guts/flistxattr.c"

	return rc;
}



static FILE * (*real_fopen)(const char *path, const char *mode) = NULL;



FILE *
fopen(const char *path, const char *mode) {
	sigset_t saved;
	
	FILE *rc = NULL;

	if (!pseudo_check_wrappers() || !real_fopen) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fopen");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fopen)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: fopen\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fopen)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fopen(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fopen (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fopen (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static FILE *
wrap_fopen(const char *path, const char *mode) {
	FILE *rc = NULL;
	
	

#include "ports/unix/guts/fopen.c"

	return rc;
}



static FILE * (*real_fopen64)(const char *path, const char *mode) = NULL;



FILE *
fopen64(const char *path, const char *mode) {
	sigset_t saved;
	
	FILE *rc = NULL;

	if (!pseudo_check_wrappers() || !real_fopen64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fopen64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fopen64)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: fopen64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fopen64)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fopen64(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fopen64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fopen64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static FILE *
wrap_fopen64(const char *path, const char *mode) {
	FILE *rc = NULL;
	
	

#include "ports/linux/guts/fopen64.c"

	return rc;
}



static int (*real_fork)(void) = NULL;

/* Hand-written wrapper for this function. */
#if 0


int
fork(void) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fork) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fork");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fork)();
		
		return rc;
	}

	pseudo_debug(4, "called: fork\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fork)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fork();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fork (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fork (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fork(void) {
	int rc = -1;
	
	

#include "ports/common/guts/fork.c"

	return rc;
}

/* Hand-written wrapper for this function. */
#endif


static int (*real_fremovexattr)(int filedes, const char *name) = NULL;



int
fremovexattr(int filedes, const char *name) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fremovexattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fremovexattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fremovexattr)(filedes, name);
		
		return rc;
	}

	pseudo_debug(4, "called: fremovexattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fremovexattr)(filedes, name);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fremovexattr(filedes, name);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fremovexattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fremovexattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fremovexattr(int filedes, const char *name) {
	int rc = -1;
	
	

#include "ports/linux/guts/fremovexattr.c"

	return rc;
}



static FILE * (*real_freopen)(const char *path, const char *mode, FILE *stream) = NULL;



FILE *
freopen(const char *path, const char *mode, FILE *stream) {
	sigset_t saved;
	
	FILE *rc = NULL;

	if (!pseudo_check_wrappers() || !real_freopen) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("freopen");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_freopen)(path, mode, stream);
		
		return rc;
	}

	pseudo_debug(4, "called: freopen\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_freopen)(path, mode, stream);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_freopen(path, mode, stream);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: freopen (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: freopen (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static FILE *
wrap_freopen(const char *path, const char *mode, FILE *stream) {
	FILE *rc = NULL;
	
	

#include "ports/unix/guts/freopen.c"

	return rc;
}



static FILE * (*real_freopen64)(const char *path, const char *mode, FILE *stream) = NULL;



FILE *
freopen64(const char *path, const char *mode, FILE *stream) {
	sigset_t saved;
	
	FILE *rc = NULL;

	if (!pseudo_check_wrappers() || !real_freopen64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("freopen64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_freopen64)(path, mode, stream);
		
		return rc;
	}

	pseudo_debug(4, "called: freopen64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_freopen64)(path, mode, stream);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_freopen64(path, mode, stream);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: freopen64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: freopen64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static FILE *
wrap_freopen64(const char *path, const char *mode, FILE *stream) {
	FILE *rc = NULL;
	
	

#include "ports/linux/guts/freopen64.c"

	return rc;
}



static int (*real_fsetxattr)(int filedes, const char *name, const void *value, size_t size, int flags) = NULL;



int
fsetxattr(int filedes, const char *name, const void *value, size_t size, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fsetxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fsetxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fsetxattr)(filedes, name, value, size, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: fsetxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fsetxattr)(filedes, name, value, size, flags);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fsetxattr(filedes, name, value, size, flags);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fsetxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fsetxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fsetxattr(int filedes, const char *name, const void *value, size_t size, int flags) {
	int rc = -1;
	
	

#include "ports/linux/guts/fsetxattr.c"

	return rc;
}



static int (*real_fstat)(int fd, struct stat *buf) = pseudo_fstat;



int
fstat(int fd, struct stat *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_fstat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fstat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fstat)(fd, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: fstat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fstat)(fd, buf);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fstat(fd, buf);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fstat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fstat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_fstat(int fd, struct stat *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/fstat.c"

	return rc;
}



static FTS * (*real_fts_open)(char * const *path_argv, int options, int (*compar)(const FTSENT **, const FTSENT **)) = NULL;



FTS *
fts_open(char * const *path_argv, int options, int (*compar)(const FTSENT **, const FTSENT **)) {
	sigset_t saved;
	
	FTS *rc = NULL;

	if (!pseudo_check_wrappers() || !real_fts_open) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("fts_open");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_fts_open)(path_argv, options, compar);
		
		return rc;
	}

	pseudo_debug(4, "called: fts_open\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_fts_open)(path_argv, options, compar);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_fts_open(path_argv, options, compar);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: fts_open (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: fts_open (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static FTS *
wrap_fts_open(char * const *path_argv, int options, int (*compar)(const FTSENT **, const FTSENT **)) {
	FTS *rc = NULL;
	
	

#include "ports/unix/guts/fts_open.c"

	return rc;
}



static int (*real_ftw)(const char *path, int (*fn)(const char *, const struct stat *, int), int nopenfd) = NULL;



int
ftw(const char *path, int (*fn)(const char *, const struct stat *, int), int nopenfd) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_ftw) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("ftw");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_ftw)(path, fn, nopenfd);
		
		return rc;
	}

	pseudo_debug(4, "called: ftw\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_ftw)(path, fn, nopenfd);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_ftw(path, fn, nopenfd);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: ftw (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: ftw (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_ftw(const char *path, int (*fn)(const char *, const struct stat *, int), int nopenfd) {
	int rc = -1;
	
	

#include "ports/unix/guts/ftw.c"

	return rc;
}



static int (*real_ftw64)(const char *path, int (*fn)(const char *, const struct stat64 *, int), int nopenfd) = NULL;



int
ftw64(const char *path, int (*fn)(const char *, const struct stat64 *, int), int nopenfd) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_ftw64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("ftw64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_ftw64)(path, fn, nopenfd);
		
		return rc;
	}

	pseudo_debug(4, "called: ftw64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_ftw64)(path, fn, nopenfd);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_ftw64(path, fn, nopenfd);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: ftw64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: ftw64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_ftw64(const char *path, int (*fn)(const char *, const struct stat64 *, int), int nopenfd) {
	int rc = -1;
	
	

#include "ports/linux/guts/ftw64.c"

	return rc;
}



static char * (*real_get_current_dir_name)(void) = NULL;



char *
get_current_dir_name(void) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_get_current_dir_name) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("get_current_dir_name");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_get_current_dir_name)();
		
		return rc;
	}

	pseudo_debug(4, "called: get_current_dir_name\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_get_current_dir_name)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_get_current_dir_name();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: get_current_dir_name (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: get_current_dir_name (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_get_current_dir_name(void) {
	char *rc = NULL;
	
	

#include "ports/linux/guts/get_current_dir_name.c"

	return rc;
}



static char * (*real_getcwd)(char *buf, size_t size) = NULL;



char *
getcwd(char *buf, size_t size) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getcwd) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getcwd");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getcwd)(buf, size);
		
		return rc;
	}

	pseudo_debug(4, "called: getcwd\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getcwd)(buf, size);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getcwd(buf, size);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getcwd (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getcwd (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_getcwd(char *buf, size_t size) {
	char *rc = NULL;
	
	

#include "ports/unix/guts/getcwd.c"

	return rc;
}



static gid_t (*real_getegid)(void) = NULL;



gid_t
getegid(void) {
	sigset_t saved;
	
	gid_t rc = 0;

	if (!pseudo_check_wrappers() || !real_getegid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getegid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getegid)();
		
		return rc;
	}

	pseudo_debug(4, "called: getegid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return 0;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getegid)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getegid();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getegid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getegid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static gid_t
wrap_getegid(void) {
	gid_t rc = 0;
	
	

#include "ports/uids_generic/guts/getegid.c"

	return rc;
}



static uid_t (*real_geteuid)(void) = NULL;



uid_t
geteuid(void) {
	sigset_t saved;
	
	uid_t rc = 0;

	if (!pseudo_check_wrappers() || !real_geteuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("geteuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_geteuid)();
		
		return rc;
	}

	pseudo_debug(4, "called: geteuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return 0;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_geteuid)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_geteuid();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: geteuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: geteuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static uid_t
wrap_geteuid(void) {
	uid_t rc = 0;
	
	

#include "ports/uids_generic/guts/geteuid.c"

	return rc;
}



static gid_t (*real_getgid)(void) = NULL;



gid_t
getgid(void) {
	sigset_t saved;
	
	gid_t rc = 0;

	if (!pseudo_check_wrappers() || !real_getgid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgid)();
		
		return rc;
	}

	pseudo_debug(4, "called: getgid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return 0;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgid)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgid();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static gid_t
wrap_getgid(void) {
	gid_t rc = 0;
	
	

#include "ports/uids_generic/guts/getgid.c"

	return rc;
}



static struct group * (*real_getgrent)(void) = NULL;



struct group *
getgrent(void) {
	sigset_t saved;
	
	struct group *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getgrent) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgrent");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgrent)();
		
		return rc;
	}

	pseudo_debug(4, "called: getgrent\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgrent)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgrent();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgrent (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgrent (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static struct group *
wrap_getgrent(void) {
	struct group *rc = NULL;
	
	

#include "ports/uids_generic/guts/getgrent.c"

	return rc;
}



static int (*real_getgrent_r)(struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) = NULL;



int
getgrent_r(struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getgrent_r) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgrent_r");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgrent_r)(gbuf, buf, buflen, gbufp);
		
		return rc;
	}

	pseudo_debug(4, "called: getgrent_r\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgrent_r)(gbuf, buf, buflen, gbufp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgrent_r(gbuf, buf, buflen, gbufp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgrent_r (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgrent_r (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getgrent_r(struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) {
	int rc = -1;
	
	

#include "ports/linux/guts/getgrent_r.c"

	return rc;
}



static struct group * (*real_getgrgid)(gid_t gid) = NULL;



struct group *
getgrgid(gid_t gid) {
	sigset_t saved;
	
	struct group *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getgrgid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgrgid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgrgid)(gid);
		
		return rc;
	}

	pseudo_debug(4, "called: getgrgid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgrgid)(gid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgrgid(gid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgrgid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgrgid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static struct group *
wrap_getgrgid(gid_t gid) {
	struct group *rc = NULL;
	
	

#include "ports/uids_generic/guts/getgrgid.c"

	return rc;
}



static int (*real_getgrgid_r)(gid_t gid, struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) = NULL;



int
getgrgid_r(gid_t gid, struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getgrgid_r) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgrgid_r");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgrgid_r)(gid, gbuf, buf, buflen, gbufp);
		
		return rc;
	}

	pseudo_debug(4, "called: getgrgid_r\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgrgid_r)(gid, gbuf, buf, buflen, gbufp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgrgid_r(gid, gbuf, buf, buflen, gbufp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgrgid_r (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgrgid_r (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getgrgid_r(gid_t gid, struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/getgrgid_r.c"

	return rc;
}



static struct group * (*real_getgrnam)(const char *name) = NULL;



struct group *
getgrnam(const char *name) {
	sigset_t saved;
	
	struct group *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getgrnam) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgrnam");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgrnam)(name);
		
		return rc;
	}

	pseudo_debug(4, "called: getgrnam\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgrnam)(name);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgrnam(name);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgrnam (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgrnam (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static struct group *
wrap_getgrnam(const char *name) {
	struct group *rc = NULL;
	
	

#include "ports/uids_generic/guts/getgrnam.c"

	return rc;
}



static int (*real_getgrnam_r)(const char *name, struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) = NULL;



int
getgrnam_r(const char *name, struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getgrnam_r) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgrnam_r");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgrnam_r)(name, gbuf, buf, buflen, gbufp);
		
		return rc;
	}

	pseudo_debug(4, "called: getgrnam_r\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgrnam_r)(name, gbuf, buf, buflen, gbufp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgrnam_r(name, gbuf, buf, buflen, gbufp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgrnam_r (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgrnam_r (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getgrnam_r(const char *name, struct group *gbuf, char *buf, size_t buflen, struct group **gbufp) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/getgrnam_r.c"

	return rc;
}



static int (*real_getgrouplist)(const char *user, gid_t group, gid_t *groups, int *ngroups) = NULL;



int
getgrouplist(const char *user, gid_t group, gid_t *groups, int *ngroups) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getgrouplist) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgrouplist");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgrouplist)(user, group, groups, ngroups);
		
		return rc;
	}

	pseudo_debug(4, "called: getgrouplist\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgrouplist)(user, group, groups, ngroups);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgrouplist(user, group, groups, ngroups);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgrouplist (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgrouplist (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getgrouplist(const char *user, gid_t group, gid_t *groups, int *ngroups) {
	int rc = -1;
	
	

#include "ports/linux/guts/getgrouplist.c"

	return rc;
}



static int (*real_getgroups)(int size, gid_t *list) = NULL;



int
getgroups(int size, gid_t *list) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getgroups) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getgroups");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getgroups)(size, list);
		
		return rc;
	}

	pseudo_debug(4, "called: getgroups\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getgroups)(size, list);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getgroups(size, list);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getgroups (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getgroups (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getgroups(int size, gid_t *list) {
	int rc = -1;
	
	

#include "ports/linux/guts/getgroups.c"

	return rc;
}



static int (*real_getpw)(uid_t uid, char *buf) = NULL;



int
getpw(uid_t uid, char *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getpw) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getpw");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getpw)(uid, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: getpw\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getpw)(uid, buf);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getpw(uid, buf);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getpw (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getpw (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getpw(uid_t uid, char *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/getpw.c"

	return rc;
}



static struct passwd * (*real_getpwent)(void) = NULL;



struct passwd *
getpwent(void) {
	sigset_t saved;
	
	struct passwd *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getpwent) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getpwent");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getpwent)();
		
		return rc;
	}

	pseudo_debug(4, "called: getpwent\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getpwent)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getpwent();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getpwent (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getpwent (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static struct passwd *
wrap_getpwent(void) {
	struct passwd *rc = NULL;
	
	

#include "ports/uids_generic/guts/getpwent.c"

	return rc;
}



static int (*real_getpwent_r)(struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) = NULL;



int
getpwent_r(struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getpwent_r) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getpwent_r");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getpwent_r)(pwbuf, buf, buflen, pwbufp);
		
		return rc;
	}

	pseudo_debug(4, "called: getpwent_r\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getpwent_r)(pwbuf, buf, buflen, pwbufp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getpwent_r(pwbuf, buf, buflen, pwbufp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getpwent_r (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getpwent_r (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getpwent_r(struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) {
	int rc = -1;
	
	

#include "ports/linux/guts/getpwent_r.c"

	return rc;
}



static struct passwd * (*real_getpwnam)(const char *name) = NULL;



struct passwd *
getpwnam(const char *name) {
	sigset_t saved;
	
	struct passwd *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getpwnam) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getpwnam");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getpwnam)(name);
		
		return rc;
	}

	pseudo_debug(4, "called: getpwnam\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getpwnam)(name);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getpwnam(name);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getpwnam (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getpwnam (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static struct passwd *
wrap_getpwnam(const char *name) {
	struct passwd *rc = NULL;
	
	

#include "ports/uids_generic/guts/getpwnam.c"

	return rc;
}



static int (*real_getpwnam_r)(const char *name, struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) = NULL;



int
getpwnam_r(const char *name, struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getpwnam_r) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getpwnam_r");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getpwnam_r)(name, pwbuf, buf, buflen, pwbufp);
		
		return rc;
	}

	pseudo_debug(4, "called: getpwnam_r\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getpwnam_r)(name, pwbuf, buf, buflen, pwbufp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getpwnam_r(name, pwbuf, buf, buflen, pwbufp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getpwnam_r (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getpwnam_r (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getpwnam_r(const char *name, struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/getpwnam_r.c"

	return rc;
}



static struct passwd * (*real_getpwuid)(uid_t uid) = NULL;



struct passwd *
getpwuid(uid_t uid) {
	sigset_t saved;
	
	struct passwd *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getpwuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getpwuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getpwuid)(uid);
		
		return rc;
	}

	pseudo_debug(4, "called: getpwuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getpwuid)(uid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getpwuid(uid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getpwuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getpwuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static struct passwd *
wrap_getpwuid(uid_t uid) {
	struct passwd *rc = NULL;
	
	

#include "ports/uids_generic/guts/getpwuid.c"

	return rc;
}



static int (*real_getpwuid_r)(uid_t uid, struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) = NULL;



int
getpwuid_r(uid_t uid, struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getpwuid_r) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getpwuid_r");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getpwuid_r)(uid, pwbuf, buf, buflen, pwbufp);
		
		return rc;
	}

	pseudo_debug(4, "called: getpwuid_r\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getpwuid_r)(uid, pwbuf, buf, buflen, pwbufp);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getpwuid_r(uid, pwbuf, buf, buflen, pwbufp);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getpwuid_r (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getpwuid_r (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getpwuid_r(uid_t uid, struct passwd *pwbuf, char *buf, size_t buflen, struct passwd **pwbufp) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/getpwuid_r.c"

	return rc;
}



static int (*real_getresgid)(gid_t *rgid, gid_t *egid, gid_t *sgid) = NULL;



int
getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getresgid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getresgid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getresgid)(rgid, egid, sgid);
		
		return rc;
	}

	pseudo_debug(4, "called: getresgid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getresgid)(rgid, egid, sgid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getresgid(rgid, egid, sgid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getresgid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getresgid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) {
	int rc = -1;
	
	

#include "ports/linux/guts/getresgid.c"

	return rc;
}



static int (*real_getresuid)(uid_t *ruid, uid_t *euid, uid_t *suid) = NULL;



int
getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_getresuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getresuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getresuid)(ruid, euid, suid);
		
		return rc;
	}

	pseudo_debug(4, "called: getresuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getresuid)(ruid, euid, suid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getresuid(ruid, euid, suid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getresuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getresuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) {
	int rc = -1;
	
	

#include "ports/linux/guts/getresuid.c"

	return rc;
}



static uid_t (*real_getuid)(void) = NULL;



uid_t
getuid(void) {
	sigset_t saved;
	
	uid_t rc = 0;

	if (!pseudo_check_wrappers() || !real_getuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getuid)();
		
		return rc;
	}

	pseudo_debug(4, "called: getuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return 0;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getuid)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getuid();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static uid_t
wrap_getuid(void) {
	uid_t rc = 0;
	
	

#include "ports/uids_generic/guts/getuid.c"

	return rc;
}



static char * (*real_getwd)(char *buf) = NULL;



char *
getwd(char *buf) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_getwd) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getwd");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getwd)(buf);
		
		return rc;
	}

	pseudo_debug(4, "called: getwd\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getwd)(buf);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getwd(buf);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getwd (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getwd (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_getwd(char *buf) {
	char *rc = NULL;
	
	

#include "ports/unix/guts/getwd.c"

	return rc;
}



static ssize_t (*real_getxattr)(const char *pathname, const char *name, void *value, size_t size) = NULL;



ssize_t
getxattr(const char *pathname, const char *name, void *value, size_t size) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_getxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("getxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_getxattr)(pathname, name, value, size);
		
		return rc;
	}

	pseudo_debug(4, "called: getxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_getxattr)(pathname, name, value, size);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_getxattr(pathname, name, value, size);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: getxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: getxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_getxattr(const char *pathname, const char *name, void *value, size_t size) {
	ssize_t rc = -1;
	
	

#include "ports/linux/guts/getxattr.c"

	return rc;
}



static int (*real_glob)(const char *pattern, int flags, int (*errfunc)(const char *, int), glob_t *pglob) = NULL;



int
glob(const char *pattern, int flags, int (*errfunc)(const char *, int), glob_t *pglob) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_glob) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("glob");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_glob)(pattern, flags, errfunc, pglob);
		
		return rc;
	}

	pseudo_debug(4, "called: glob\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_glob)(pattern, flags, errfunc, pglob);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_glob(pattern, flags, errfunc, pglob);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: glob (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: glob (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_glob(const char *pattern, int flags, int (*errfunc)(const char *, int), glob_t *pglob) {
	int rc = -1;
	
	

#include "ports/unix/guts/glob.c"

	return rc;
}



static int (*real_glob64)(const char *pattern, int flags, int (*errfunc)(const char *, int), glob64_t *pglob) = NULL;



int
glob64(const char *pattern, int flags, int (*errfunc)(const char *, int), glob64_t *pglob) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_glob64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("glob64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_glob64)(pattern, flags, errfunc, pglob);
		
		return rc;
	}

	pseudo_debug(4, "called: glob64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_glob64)(pattern, flags, errfunc, pglob);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_glob64(pattern, flags, errfunc, pglob);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: glob64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: glob64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_glob64(const char *pattern, int flags, int (*errfunc)(const char *, int), glob64_t *pglob) {
	int rc = -1;
	
	

#include "ports/linux/guts/glob64.c"

	return rc;
}



static int (*real_lchown)(const char *path, uid_t owner, gid_t group) = NULL;



int
lchown(const char *path, uid_t owner, gid_t group) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_lchown) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("lchown");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_lchown)(path, owner, group);
		
		return rc;
	}

	pseudo_debug(4, "called: lchown\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_lchown)(path, owner, group);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_lchown(path, owner, group);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: lchown (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: lchown (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_lchown(const char *path, uid_t owner, gid_t group) {
	int rc = -1;
	
	

#include "ports/linux/guts/lchown.c"

	return rc;
}



static int (*real_lckpwdf)(void) = NULL;



int
lckpwdf(void) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_lckpwdf) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("lckpwdf");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_lckpwdf)();
		
		return rc;
	}

	pseudo_debug(4, "called: lckpwdf\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_lckpwdf)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_lckpwdf();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: lckpwdf (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: lckpwdf (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_lckpwdf(void) {
	int rc = -1;
	
	

#include "ports/linux/guts/lckpwdf.c"

	return rc;
}



static ssize_t (*real_lgetxattr)(const char *pathname, const char *name, void *value, size_t size) = NULL;



ssize_t
lgetxattr(const char *pathname, const char *name, void *value, size_t size) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_lgetxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("lgetxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_lgetxattr)(pathname, name, value, size);
		
		return rc;
	}

	pseudo_debug(4, "called: lgetxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_lgetxattr)(pathname, name, value, size);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_lgetxattr(pathname, name, value, size);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: lgetxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: lgetxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_lgetxattr(const char *pathname, const char *name, void *value, size_t size) {
	ssize_t rc = -1;
	
	

#include "ports/linux/guts/lgetxattr.c"

	return rc;
}



static int (*real_link)(const char *oldpath, const char *newpath) = NULL;



int
link(const char *oldpath, const char *newpath) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_link) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("link");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_link)(oldpath, newpath);
		
		return rc;
	}

	pseudo_debug(4, "called: link\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_link)(oldpath, newpath);
	} else {
		oldpath = pseudo_root_path(__func__, __LINE__, AT_FDCWD, oldpath, AT_SYMLINK_NOFOLLOW);
			newpath = pseudo_root_path(__func__, __LINE__, AT_FDCWD, newpath, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_link(oldpath, newpath);
		free((void *) oldpath);
			free((void *) newpath);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: link (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: link (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_link(const char *oldpath, const char *newpath) {
	int rc = -1;
	
	

#include "ports/unix/guts/link.c"

	return rc;
}



static ssize_t (*real_listxattr)(const char *pathname, char *list, size_t size) = NULL;



ssize_t
listxattr(const char *pathname, char *list, size_t size) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_listxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("listxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_listxattr)(pathname, list, size);
		
		return rc;
	}

	pseudo_debug(4, "called: listxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_listxattr)(pathname, list, size);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_listxattr(pathname, list, size);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: listxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: listxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_listxattr(const char *pathname, char *list, size_t size) {
	ssize_t rc = -1;
	
	

#include "ports/linux/guts/listxattr.c"

	return rc;
}



static ssize_t (*real_llistxattr)(const char *pathname, char *list, size_t size) = NULL;



ssize_t
llistxattr(const char *pathname, char *list, size_t size) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_llistxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("llistxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_llistxattr)(pathname, list, size);
		
		return rc;
	}

	pseudo_debug(4, "called: llistxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_llistxattr)(pathname, list, size);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_llistxattr(pathname, list, size);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: llistxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: llistxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_llistxattr(const char *pathname, char *list, size_t size) {
	ssize_t rc = -1;
	
	

#include "ports/linux/guts/llistxattr.c"

	return rc;
}



static int (*real_lremovexattr)(const char *pathname, const char *name) = NULL;



int
lremovexattr(const char *pathname, const char *name) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_lremovexattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("lremovexattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_lremovexattr)(pathname, name);
		
		return rc;
	}

	pseudo_debug(4, "called: lremovexattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_lremovexattr)(pathname, name);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_lremovexattr(pathname, name);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: lremovexattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: lremovexattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_lremovexattr(const char *pathname, const char *name) {
	int rc = -1;
	
	

#include "ports/linux/guts/lremovexattr.c"

	return rc;
}



static int (*real_lsetxattr)(const char *pathname, const char *name, const void *value, size_t size, int flags) = NULL;



int
lsetxattr(const char *pathname, const char *name, const void *value, size_t size, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_lsetxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("lsetxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_lsetxattr)(pathname, name, value, size, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: lsetxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_lsetxattr)(pathname, name, value, size, flags);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_lsetxattr(pathname, name, value, size, flags);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: lsetxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: lsetxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_lsetxattr(const char *pathname, const char *name, const void *value, size_t size, int flags) {
	int rc = -1;
	
	

#include "ports/linux/guts/lsetxattr.c"

	return rc;
}



static int (*real_lstat)(const char *path, struct stat *buf) = pseudo_lstat;



int
lstat(const char *path, struct stat *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_lstat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("lstat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_lstat)(path, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: lstat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_lstat)(path, buf);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_lstat(path, buf);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: lstat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: lstat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_lstat(const char *path, struct stat *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/lstat.c"

	return rc;
}



static int (*real_lutimes)(const char *path, const struct timeval *tv) = NULL;



int
lutimes(const char *path, const struct timeval *tv) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_lutimes) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("lutimes");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_lutimes)(path, tv);
		
		return rc;
	}

	pseudo_debug(4, "called: lutimes\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_lutimes)(path, tv);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_lutimes(path, tv);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: lutimes (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: lutimes (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_lutimes(const char *path, const struct timeval *tv) {
	int rc = -1;
	
	

#include "ports/unix/guts/lutimes.c"

	return rc;
}



static int (*real_mkdir)(const char *path, mode_t mode) = NULL;



int
mkdir(const char *path, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mkdir) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mkdir");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mkdir)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: mkdir\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mkdir)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mkdir(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mkdir (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mkdir (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mkdir(const char *path, mode_t mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/mkdir.c"

	return rc;
}



static int (*real_mkdirat)(int dirfd, const char *path, mode_t mode) = NULL;



int
mkdirat(int dirfd, const char *path, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mkdirat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mkdirat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mkdirat)(dirfd, path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: mkdirat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mkdirat)(dirfd, path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mkdirat(dirfd, path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mkdirat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mkdirat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mkdirat(int dirfd, const char *path, mode_t mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/mkdirat.c"

	return rc;
}



static char * (*real_mkdtemp)(char *template) = NULL;



char *
mkdtemp(char *template) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_mkdtemp) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mkdtemp");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mkdtemp)(template);
		
		return rc;
	}

	pseudo_debug(4, "called: mkdtemp\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mkdtemp)(template);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mkdtemp(template);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mkdtemp (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mkdtemp (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_mkdtemp(char *template) {
	char *rc = NULL;
	
	

#include "ports/unix/guts/mkdtemp.c"

	return rc;
}



static int (*real_mkfifo)(const char *path, mode_t mode) = NULL;



int
mkfifo(const char *path, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mkfifo) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mkfifo");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mkfifo)(path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: mkfifo\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mkfifo)(path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mkfifo(path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mkfifo (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mkfifo (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mkfifo(const char *path, mode_t mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/mkfifo.c"

	return rc;
}



static int (*real_mkfifoat)(int dirfd, const char *path, mode_t mode) = NULL;



int
mkfifoat(int dirfd, const char *path, mode_t mode) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mkfifoat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mkfifoat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mkfifoat)(dirfd, path, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: mkfifoat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mkfifoat)(dirfd, path, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mkfifoat(dirfd, path, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mkfifoat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mkfifoat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mkfifoat(int dirfd, const char *path, mode_t mode) {
	int rc = -1;
	
	

#include "ports/unix/guts/mkfifoat.c"

	return rc;
}



static int (*real_mknod)(const char *path, mode_t mode, dev_t dev) = NULL;



int
mknod(const char *path, mode_t mode, dev_t dev) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mknod) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mknod");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mknod)(path, mode, dev);
		
		return rc;
	}

	pseudo_debug(4, "called: mknod\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mknod)(path, mode, dev);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mknod(path, mode, dev);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mknod (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mknod (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mknod(const char *path, mode_t mode, dev_t dev) {
	int rc = -1;
	
	

#include "ports/unix/guts/mknod.c"

	return rc;
}



static int (*real_mknodat)(int dirfd, const char *path, mode_t mode, dev_t dev) = NULL;



int
mknodat(int dirfd, const char *path, mode_t mode, dev_t dev) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mknodat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mknodat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mknodat)(dirfd, path, mode, dev);
		
		return rc;
	}

	pseudo_debug(4, "called: mknodat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mknodat)(dirfd, path, mode, dev);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mknodat(dirfd, path, mode, dev);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mknodat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mknodat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mknodat(int dirfd, const char *path, mode_t mode, dev_t dev) {
	int rc = -1;
	
	

#include "ports/unix/guts/mknodat.c"

	return rc;
}



static int (*real_mkstemp)(char *template) = NULL;



int
mkstemp(char *template) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mkstemp) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mkstemp");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mkstemp)(template);
		
		return rc;
	}

	pseudo_debug(4, "called: mkstemp\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mkstemp)(template);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mkstemp(template);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mkstemp (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mkstemp (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mkstemp(char *template) {
	int rc = -1;
	
	

#include "ports/unix/guts/mkstemp.c"

	return rc;
}



static int (*real_mkstemp64)(char *template) = NULL;



int
mkstemp64(char *template) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_mkstemp64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mkstemp64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mkstemp64)(template);
		
		return rc;
	}

	pseudo_debug(4, "called: mkstemp64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mkstemp64)(template);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mkstemp64(template);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mkstemp64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mkstemp64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_mkstemp64(char *template) {
	int rc = -1;
	
	

#include "ports/linux/guts/mkstemp64.c"

	return rc;
}



static char * (*real_mktemp)(char *template) = NULL;



char *
mktemp(char *template) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_mktemp) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("mktemp");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_mktemp)(template);
		
		return rc;
	}

	pseudo_debug(4, "called: mktemp\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_mktemp)(template);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_mktemp(template);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: mktemp (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: mktemp (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_mktemp(char *template) {
	char *rc = NULL;
	
	

#include "ports/unix/guts/mktemp.c"

	return rc;
}



static int (*real_nftw)(const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int nopenfd, int flag) = NULL;



int
nftw(const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int nopenfd, int flag) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_nftw) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("nftw");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_nftw)(path, fn, nopenfd, flag);
		
		return rc;
	}

	pseudo_debug(4, "called: nftw\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_nftw)(path, fn, nopenfd, flag);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_nftw(path, fn, nopenfd, flag);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: nftw (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: nftw (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_nftw(const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int nopenfd, int flag) {
	int rc = -1;
	
	

#include "ports/unix/guts/nftw.c"

	return rc;
}



static int (*real_nftw64)(const char *path, int (*fn)(const char *, const struct stat64 *, int, struct FTW *), int nopenfd, int flag) = NULL;



int
nftw64(const char *path, int (*fn)(const char *, const struct stat64 *, int, struct FTW *), int nopenfd, int flag) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_nftw64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("nftw64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_nftw64)(path, fn, nopenfd, flag);
		
		return rc;
	}

	pseudo_debug(4, "called: nftw64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_nftw64)(path, fn, nopenfd, flag);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_nftw64(path, fn, nopenfd, flag);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: nftw64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: nftw64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_nftw64(const char *path, int (*fn)(const char *, const struct stat64 *, int, struct FTW *), int nopenfd, int flag) {
	int rc = -1;
	
	

#include "ports/linux/guts/nftw64.c"

	return rc;
}



static int (*real_open)(const char *path, int flags, ... /* mode_t mode */) = NULL;



int
open(const char *path, int flags, ... /* mode_t mode */) {
	sigset_t saved;
	va_list ap;
	mode_t mode;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_open) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("open");
		return rc;
	}

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


	if (pseudo_disabled) {
		rc = (*real_open)(path, flags, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: open\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_open)(path, flags, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_open(path, flags, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: open (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: open (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_open(const char *path, int flags, ... /* mode_t mode */) {
	int rc = -1;
	va_list ap;
	mode_t mode;

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


#include "ports/linux/guts/open.c"

	return rc;
}



static int (*real_open64)(const char *path, int flags, ... /* mode_t mode */) = NULL;



int
open64(const char *path, int flags, ... /* mode_t mode */) {
	sigset_t saved;
	va_list ap;
	mode_t mode;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_open64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("open64");
		return rc;
	}

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


	if (pseudo_disabled) {
		rc = (*real_open64)(path, flags, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: open64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_open64)(path, flags, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_open64(path, flags, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: open64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: open64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_open64(const char *path, int flags, ... /* mode_t mode */) {
	int rc = -1;
	va_list ap;
	mode_t mode;

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


#include "ports/linux/guts/open64.c"

	return rc;
}



static int (*real_openat)(int dirfd, const char *path, int flags, ... /* mode_t mode */) = NULL;



int
openat(int dirfd, const char *path, int flags, ... /* mode_t mode */) {
	sigset_t saved;
	va_list ap;
	mode_t mode;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_openat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("openat");
		return rc;
	}

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


	if (pseudo_disabled) {
		rc = (*real_openat)(dirfd, path, flags, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: openat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_openat)(dirfd, path, flags, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, flags);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_openat(dirfd, path, flags, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: openat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: openat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_openat(int dirfd, const char *path, int flags, ... /* mode_t mode */) {
	int rc = -1;
	va_list ap;
	mode_t mode;

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


#include "ports/linux/guts/openat.c"

	return rc;
}



static int (*real_openat64)(int dirfd, const char *path, int flags, ... /* mode_t mode */) = NULL;



int
openat64(int dirfd, const char *path, int flags, ... /* mode_t mode */) {
	sigset_t saved;
	va_list ap;
	mode_t mode;

	int rc = -1;

	if (!pseudo_check_wrappers() || !real_openat64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("openat64");
		return rc;
	}

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


	if (pseudo_disabled) {
		rc = (*real_openat64)(dirfd, path, flags, mode);
		
		return rc;
	}

	pseudo_debug(4, "called: openat64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_openat64)(dirfd, path, flags, mode);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_openat64(dirfd, path, flags, mode);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: openat64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: openat64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_openat64(int dirfd, const char *path, int flags, ... /* mode_t mode */) {
	int rc = -1;
	va_list ap;
	mode_t mode;

	va_start(ap, flags);
	mode = va_arg(ap, mode_t);
	va_end(ap);


#include "ports/linux/guts/openat64.c"

	return rc;
}



static DIR * (*real_opendir)(const char *path) = NULL;



DIR *
opendir(const char *path) {
	sigset_t saved;
	
	DIR *rc = NULL;

	if (!pseudo_check_wrappers() || !real_opendir) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("opendir");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_opendir)(path);
		
		return rc;
	}

	pseudo_debug(4, "called: opendir\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_opendir)(path);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_opendir(path);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: opendir (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: opendir (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static DIR *
wrap_opendir(const char *path) {
	DIR *rc = NULL;
	
	

#include "ports/unix/guts/opendir.c"

	return rc;
}



static long (*real_pathconf)(const char *path, int name) = NULL;



long
pathconf(const char *path, int name) {
	sigset_t saved;
	
	long rc = -1;

	if (!pseudo_check_wrappers() || !real_pathconf) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("pathconf");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_pathconf)(path, name);
		
		return rc;
	}

	pseudo_debug(4, "called: pathconf\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_pathconf)(path, name);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_pathconf(path, name);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: pathconf (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: pathconf (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static long
wrap_pathconf(const char *path, int name) {
	long rc = -1;
	
	

#include "ports/unix/guts/pathconf.c"

	return rc;
}



static ssize_t (*real_readlink)(const char *path, char *buf, size_t bufsiz) = NULL;



ssize_t
readlink(const char *path, char *buf, size_t bufsiz) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_readlink) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("readlink");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_readlink)(path, buf, bufsiz);
		
		return rc;
	}

	pseudo_debug(4, "called: readlink\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_readlink)(path, buf, bufsiz);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_readlink(path, buf, bufsiz);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: readlink (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: readlink (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_readlink(const char *path, char *buf, size_t bufsiz) {
	ssize_t rc = -1;
	
	

#include "ports/unix/guts/readlink.c"

	return rc;
}



static ssize_t (*real_readlinkat)(int dirfd, const char *path, char *buf, size_t bufsiz) = NULL;



ssize_t
readlinkat(int dirfd, const char *path, char *buf, size_t bufsiz) {
	sigset_t saved;
	
	ssize_t rc = -1;

	if (!pseudo_check_wrappers() || !real_readlinkat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("readlinkat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_readlinkat)(dirfd, path, buf, bufsiz);
		
		return rc;
	}

	pseudo_debug(4, "called: readlinkat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_readlinkat)(dirfd, path, buf, bufsiz);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_readlinkat(dirfd, path, buf, bufsiz);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: readlinkat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: readlinkat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static ssize_t
wrap_readlinkat(int dirfd, const char *path, char *buf, size_t bufsiz) {
	ssize_t rc = -1;
	
	

#include "ports/unix/guts/readlinkat.c"

	return rc;
}



static char * (*real_realpath)(const char *name, char *resolved_name) = NULL;



char *
realpath(const char *name, char *resolved_name) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_realpath) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("realpath");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_realpath)(name, resolved_name);
		
		return rc;
	}

	pseudo_debug(4, "called: realpath\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_realpath)(name, resolved_name);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_realpath(name, resolved_name);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: realpath (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: realpath (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_realpath(const char *name, char *resolved_name) {
	char *rc = NULL;
	
	

#include "ports/unix/guts/realpath.c"

	return rc;
}



static int (*real_remove)(const char *path) = NULL;



int
remove(const char *path) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_remove) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("remove");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_remove)(path);
		
		return rc;
	}

	pseudo_debug(4, "called: remove\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_remove)(path);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_remove(path);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: remove (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: remove (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_remove(const char *path) {
	int rc = -1;
	
	

#include "ports/unix/guts/remove.c"

	return rc;
}



static int (*real_removexattr)(const char *pathname, const char *name) = NULL;



int
removexattr(const char *pathname, const char *name) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_removexattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("removexattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_removexattr)(pathname, name);
		
		return rc;
	}

	pseudo_debug(4, "called: removexattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_removexattr)(pathname, name);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_removexattr(pathname, name);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: removexattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: removexattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_removexattr(const char *pathname, const char *name) {
	int rc = -1;
	
	

#include "ports/linux/guts/removexattr.c"

	return rc;
}



static int (*real_rename)(const char *oldpath, const char *newpath) = NULL;



int
rename(const char *oldpath, const char *newpath) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_rename) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("rename");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_rename)(oldpath, newpath);
		
		return rc;
	}

	pseudo_debug(4, "called: rename\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_rename)(oldpath, newpath);
	} else {
		oldpath = pseudo_root_path(__func__, __LINE__, AT_FDCWD, oldpath, AT_SYMLINK_NOFOLLOW);
			newpath = pseudo_root_path(__func__, __LINE__, AT_FDCWD, newpath, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_rename(oldpath, newpath);
		free((void *) oldpath);
			free((void *) newpath);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: rename (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: rename (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_rename(const char *oldpath, const char *newpath) {
	int rc = -1;
	
	

#include "ports/unix/guts/rename.c"

	return rc;
}



static int (*real_renameat)(int olddirfd, const char *oldpath, int newdirfd, const char *newpath) = NULL;



int
renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_renameat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("renameat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_renameat)(olddirfd, oldpath, newdirfd, newpath);
		
		return rc;
	}

	pseudo_debug(4, "called: renameat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_renameat)(olddirfd, oldpath, newdirfd, newpath);
	} else {
		oldpath = pseudo_root_path(__func__, __LINE__, olddirfd, oldpath, AT_SYMLINK_NOFOLLOW);
			newpath = pseudo_root_path(__func__, __LINE__, newdirfd, newpath, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_renameat(olddirfd, oldpath, newdirfd, newpath);
		free((void *) oldpath);
			free((void *) newpath);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: renameat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: renameat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath) {
	int rc = -1;
	
	

#include "ports/unix/guts/renameat.c"

	return rc;
}



static int (*real_rmdir)(const char *path) = NULL;



int
rmdir(const char *path) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_rmdir) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("rmdir");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_rmdir)(path);
		
		return rc;
	}

	pseudo_debug(4, "called: rmdir\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_rmdir)(path);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_rmdir(path);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: rmdir (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: rmdir (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_rmdir(const char *path) {
	int rc = -1;
	
	

#include "ports/unix/guts/rmdir.c"

	return rc;
}



static int (*real_scandir)(const char *path, struct dirent ***namelist, int (*filter)(const struct dirent *), int (*compar)()) = NULL;



int
scandir(const char *path, struct dirent ***namelist, int (*filter)(const struct dirent *), int (*compar)()) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_scandir) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("scandir");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_scandir)(path, namelist, filter, compar);
		
		return rc;
	}

	pseudo_debug(4, "called: scandir\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_scandir)(path, namelist, filter, compar);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_scandir(path, namelist, filter, compar);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: scandir (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: scandir (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_scandir(const char *path, struct dirent ***namelist, int (*filter)(const struct dirent *), int (*compar)()) {
	int rc = -1;
	
	

#include "ports/linux/guts/scandir.c"

	return rc;
}



static int (*real_scandir64)(const char *path, struct dirent64 ***namelist, int (*filter)(const struct dirent64 *), int (*compar)()) = NULL;



int
scandir64(const char *path, struct dirent64 ***namelist, int (*filter)(const struct dirent64 *), int (*compar)()) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_scandir64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("scandir64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_scandir64)(path, namelist, filter, compar);
		
		return rc;
	}

	pseudo_debug(4, "called: scandir64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_scandir64)(path, namelist, filter, compar);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_scandir64(path, namelist, filter, compar);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: scandir64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: scandir64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_scandir64(const char *path, struct dirent64 ***namelist, int (*filter)(const struct dirent64 *), int (*compar)()) {
	int rc = -1;
	
	

#include "ports/linux/guts/scandir64.c"

	return rc;
}



static int (*real_setegid)(gid_t egid) = NULL;



int
setegid(gid_t egid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setegid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setegid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setegid)(egid);
		
		return rc;
	}

	pseudo_debug(4, "called: setegid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setegid)(egid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setegid(egid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setegid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setegid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setegid(gid_t egid) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/setegid.c"

	return rc;
}



static int (*real_seteuid)(uid_t euid) = NULL;



int
seteuid(uid_t euid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_seteuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("seteuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_seteuid)(euid);
		
		return rc;
	}

	pseudo_debug(4, "called: seteuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_seteuid)(euid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_seteuid(euid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: seteuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: seteuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_seteuid(uid_t euid) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/seteuid.c"

	return rc;
}



static int (*real_setfsgid)(gid_t fsgid) = NULL;



int
setfsgid(gid_t fsgid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setfsgid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setfsgid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setfsgid)(fsgid);
		
		return rc;
	}

	pseudo_debug(4, "called: setfsgid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setfsgid)(fsgid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setfsgid(fsgid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setfsgid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setfsgid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setfsgid(gid_t fsgid) {
	int rc = -1;
	
	

#include "ports/linux/guts/setfsgid.c"

	return rc;
}



static int (*real_setfsuid)(uid_t fsuid) = NULL;



int
setfsuid(uid_t fsuid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setfsuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setfsuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setfsuid)(fsuid);
		
		return rc;
	}

	pseudo_debug(4, "called: setfsuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setfsuid)(fsuid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setfsuid(fsuid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setfsuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setfsuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setfsuid(uid_t fsuid) {
	int rc = -1;
	
	

#include "ports/linux/guts/setfsuid.c"

	return rc;
}



static int (*real_setgid)(gid_t gid) = NULL;



int
setgid(gid_t gid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setgid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setgid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setgid)(gid);
		
		return rc;
	}

	pseudo_debug(4, "called: setgid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setgid)(gid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setgid(gid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setgid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setgid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setgid(gid_t gid) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/setgid.c"

	return rc;
}



static void (*real_setgrent)(void) = NULL;



void
setgrent(void) {
	sigset_t saved;
	
	

	if (!pseudo_check_wrappers() || !real_setgrent) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setgrent");
		return;
	}

	

	if (pseudo_disabled) {
		(void) (*real_setgrent)();
		
		return;
	}

	pseudo_debug(4, "called: setgrent\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		(void) (*real_setgrent)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		(void) wrap_setgrent();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setgrent (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setgrent (errno: %d)\n", save_errno);
	errno = save_errno;
	return;
}

static void
wrap_setgrent(void) {
	
	
	

#include "ports/uids_generic/guts/setgrent.c"

	return;
}



static int (*real_setgroups)(size_t size, const gid_t *list) = NULL;



int
setgroups(size_t size, const gid_t *list) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setgroups) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setgroups");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setgroups)(size, list);
		
		return rc;
	}

	pseudo_debug(4, "called: setgroups\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setgroups)(size, list);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setgroups(size, list);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setgroups (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setgroups (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setgroups(size_t size, const gid_t *list) {
	int rc = -1;
	
	

#include "ports/linux/guts/setgroups.c"

	return rc;
}



static void (*real_setpwent)(void) = NULL;



void
setpwent(void) {
	sigset_t saved;
	
	

	if (!pseudo_check_wrappers() || !real_setpwent) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setpwent");
		return;
	}

	

	if (pseudo_disabled) {
		(void) (*real_setpwent)();
		
		return;
	}

	pseudo_debug(4, "called: setpwent\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		(void) (*real_setpwent)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		(void) wrap_setpwent();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setpwent (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setpwent (errno: %d)\n", save_errno);
	errno = save_errno;
	return;
}

static void
wrap_setpwent(void) {
	
	
	

#include "ports/uids_generic/guts/setpwent.c"

	return;
}



static int (*real_setregid)(gid_t rgid, gid_t egid) = NULL;



int
setregid(gid_t rgid, gid_t egid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setregid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setregid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setregid)(rgid, egid);
		
		return rc;
	}

	pseudo_debug(4, "called: setregid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setregid)(rgid, egid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setregid(rgid, egid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setregid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setregid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setregid(gid_t rgid, gid_t egid) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/setregid.c"

	return rc;
}



static int (*real_setresgid)(gid_t rgid, gid_t egid, gid_t sgid) = NULL;



int
setresgid(gid_t rgid, gid_t egid, gid_t sgid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setresgid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setresgid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setresgid)(rgid, egid, sgid);
		
		return rc;
	}

	pseudo_debug(4, "called: setresgid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setresgid)(rgid, egid, sgid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setresgid(rgid, egid, sgid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setresgid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setresgid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setresgid(gid_t rgid, gid_t egid, gid_t sgid) {
	int rc = -1;
	
	

#include "ports/linux/guts/setresgid.c"

	return rc;
}



static int (*real_setresuid)(uid_t ruid, uid_t euid, uid_t suid) = NULL;



int
setresuid(uid_t ruid, uid_t euid, uid_t suid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setresuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setresuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setresuid)(ruid, euid, suid);
		
		return rc;
	}

	pseudo_debug(4, "called: setresuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setresuid)(ruid, euid, suid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setresuid(ruid, euid, suid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setresuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setresuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setresuid(uid_t ruid, uid_t euid, uid_t suid) {
	int rc = -1;
	
	

#include "ports/linux/guts/setresuid.c"

	return rc;
}



static int (*real_setreuid)(uid_t ruid, uid_t euid) = NULL;



int
setreuid(uid_t ruid, uid_t euid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setreuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setreuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setreuid)(ruid, euid);
		
		return rc;
	}

	pseudo_debug(4, "called: setreuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setreuid)(ruid, euid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setreuid(ruid, euid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setreuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setreuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setreuid(uid_t ruid, uid_t euid) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/setreuid.c"

	return rc;
}



static int (*real_setuid)(uid_t uid) = NULL;



int
setuid(uid_t uid) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setuid) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setuid");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setuid)(uid);
		
		return rc;
	}

	pseudo_debug(4, "called: setuid\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setuid)(uid);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setuid(uid);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setuid (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setuid (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setuid(uid_t uid) {
	int rc = -1;
	
	

#include "ports/uids_generic/guts/setuid.c"

	return rc;
}



static int (*real_setxattr)(const char *pathname, const char *name, const void *value, size_t size, int flags) = NULL;



int
setxattr(const char *pathname, const char *name, const void *value, size_t size, int flags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_setxattr) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("setxattr");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_setxattr)(pathname, name, value, size, flags);
		
		return rc;
	}

	pseudo_debug(4, "called: setxattr\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_setxattr)(pathname, name, value, size, flags);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_setxattr(pathname, name, value, size, flags);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: setxattr (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: setxattr (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_setxattr(const char *pathname, const char *name, const void *value, size_t size, int flags) {
	int rc = -1;
	
	

#include "ports/linux/guts/setxattr.c"

	return rc;
}



static int (*real_stat)(const char *path, struct stat *buf) = pseudo_stat;



int
stat(const char *path, struct stat *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_stat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("stat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_stat)(path, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: stat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_stat)(path, buf);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_stat(path, buf);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: stat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: stat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_stat(const char *path, struct stat *buf) {
	int rc = -1;
	
	

#include "ports/linux/guts/stat.c"

	return rc;
}



static int (*real_symlink)(const char *oldname, const char *newpath) = NULL;



int
symlink(const char *oldname, const char *newpath) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_symlink) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("symlink");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_symlink)(oldname, newpath);
		
		return rc;
	}

	pseudo_debug(4, "called: symlink\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_symlink)(oldname, newpath);
	} else {
		newpath = pseudo_root_path(__func__, __LINE__, AT_FDCWD, newpath, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_symlink(oldname, newpath);
		free((void *) newpath);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: symlink (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: symlink (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_symlink(const char *oldname, const char *newpath) {
	int rc = -1;
	
	

#include "ports/unix/guts/symlink.c"

	return rc;
}



static int (*real_symlinkat)(const char *oldname, int dirfd, const char *newpath) = NULL;



int
symlinkat(const char *oldname, int dirfd, const char *newpath) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_symlinkat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("symlinkat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_symlinkat)(oldname, dirfd, newpath);
		
		return rc;
	}

	pseudo_debug(4, "called: symlinkat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_symlinkat)(oldname, dirfd, newpath);
	} else {
		newpath = pseudo_root_path(__func__, __LINE__, dirfd, newpath, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_symlinkat(oldname, dirfd, newpath);
		free((void *) newpath);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: symlinkat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: symlinkat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_symlinkat(const char *oldname, int dirfd, const char *newpath) {
	int rc = -1;
	
	

#include "ports/unix/guts/symlinkat.c"

	return rc;
}



static int (*real_system)(const char *command) = NULL;



int
system(const char *command) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_system) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("system");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_system)(command);
		
		return rc;
	}

	pseudo_debug(4, "called: system\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_system)(command);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_system(command);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: system (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: system (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_system(const char *command) {
	int rc = -1;
	
	

#include "ports/unix/guts/system.c"

	return rc;
}



static char * (*real_tempnam)(const char *template, const char *pfx) = NULL;



char *
tempnam(const char *template, const char *pfx) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_tempnam) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("tempnam");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_tempnam)(template, pfx);
		
		return rc;
	}

	pseudo_debug(4, "called: tempnam\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_tempnam)(template, pfx);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_tempnam(template, pfx);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: tempnam (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: tempnam (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_tempnam(const char *template, const char *pfx) {
	char *rc = NULL;
	
	

#include "ports/unix/guts/tempnam.c"

	return rc;
}



static char * (*real_tmpnam)(char *s) = NULL;



char *
tmpnam(char *s) {
	sigset_t saved;
	
	char *rc = NULL;

	if (!pseudo_check_wrappers() || !real_tmpnam) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("tmpnam");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_tmpnam)(s);
		
		return rc;
	}

	pseudo_debug(4, "called: tmpnam\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return NULL;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_tmpnam)(s);
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_tmpnam(s);
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: tmpnam (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: tmpnam (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static char *
wrap_tmpnam(char *s) {
	char *rc = NULL;
	
	

#include "ports/unix/guts/tmpnam.c"

	return rc;
}



static int (*real_truncate)(const char *path, off_t length) = NULL;



int
truncate(const char *path, off_t length) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_truncate) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("truncate");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_truncate)(path, length);
		
		return rc;
	}

	pseudo_debug(4, "called: truncate\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_truncate)(path, length);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_truncate(path, length);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: truncate (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: truncate (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_truncate(const char *path, off_t length) {
	int rc = -1;
	
	

#include "ports/unix/guts/truncate.c"

	return rc;
}



static int (*real_truncate64)(const char *path, off64_t length) = NULL;



int
truncate64(const char *path, off64_t length) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_truncate64) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("truncate64");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_truncate64)(path, length);
		
		return rc;
	}

	pseudo_debug(4, "called: truncate64\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_truncate64)(path, length);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_truncate64(path, length);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: truncate64 (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: truncate64 (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_truncate64(const char *path, off64_t length) {
	int rc = -1;
	
	

#include "ports/linux/guts/truncate64.c"

	return rc;
}



static int (*real_ulckpwdf)(void) = NULL;



int
ulckpwdf(void) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_ulckpwdf) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("ulckpwdf");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_ulckpwdf)();
		
		return rc;
	}

	pseudo_debug(4, "called: ulckpwdf\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_ulckpwdf)();
	} else {
		
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_ulckpwdf();
		
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: ulckpwdf (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: ulckpwdf (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_ulckpwdf(void) {
	int rc = -1;
	
	

#include "ports/linux/guts/ulckpwdf.c"

	return rc;
}



static int (*real_unlink)(const char *path) = NULL;



int
unlink(const char *path) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_unlink) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("unlink");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_unlink)(path);
		
		return rc;
	}

	pseudo_debug(4, "called: unlink\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_unlink)(path);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_unlink(path);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: unlink (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: unlink (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_unlink(const char *path) {
	int rc = -1;
	
	

#include "ports/unix/guts/unlink.c"

	return rc;
}



static int (*real_unlinkat)(int dirfd, const char *path, int rflags) = NULL;



int
unlinkat(int dirfd, const char *path, int rflags) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_unlinkat) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("unlinkat");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_unlinkat)(dirfd, path, rflags);
		
		return rc;
	}

	pseudo_debug(4, "called: unlinkat\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_unlinkat)(dirfd, path, rflags);
	} else {
		path = pseudo_root_path(__func__, __LINE__, dirfd, path, AT_SYMLINK_NOFOLLOW);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_unlinkat(dirfd, path, rflags);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: unlinkat (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: unlinkat (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_unlinkat(int dirfd, const char *path, int rflags) {
	int rc = -1;
	
	

#include "ports/unix/guts/unlinkat.c"

	return rc;
}



static int (*real_utime)(const char *path, const struct utimbuf *buf) = NULL;



int
utime(const char *path, const struct utimbuf *buf) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_utime) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("utime");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_utime)(path, buf);
		
		return rc;
	}

	pseudo_debug(4, "called: utime\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_utime)(path, buf);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_utime(path, buf);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: utime (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: utime (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_utime(const char *path, const struct utimbuf *buf) {
	int rc = -1;
	
	

#include "ports/unix/guts/utime.c"

	return rc;
}



static int (*real_utimes)(const char *path, const struct timeval *times) = NULL;



int
utimes(const char *path, const struct timeval *times) {
	sigset_t saved;
	
	int rc = -1;

	if (!pseudo_check_wrappers() || !real_utimes) {
		/* rc was initialized to the "failure" value */
		pseudo_enosys("utimes");
		return rc;
	}

	

	if (pseudo_disabled) {
		rc = (*real_utimes)(path, times);
		
		return rc;
	}

	pseudo_debug(4, "called: utimes\n");
	pseudo_sigblock(&saved);
	if (pseudo_getlock()) {
		errno = EBUSY;
		sigprocmask(SIG_SETMASK, &saved, NULL);
		return -1;
	}

	int save_errno;
	if (antimagic > 0) {
		/* call the real syscall */
		rc = (*real_utimes)(path, times);
	} else {
		path = pseudo_root_path(__func__, __LINE__, AT_FDCWD, path, 0);
		/* exec*() use this to restore the sig mask */
		pseudo_saved_sigmask = saved;
		rc = wrap_utimes(path, times);
		free((void *) path);
	}
	
	save_errno = errno;
	pseudo_droplock();
	sigprocmask(SIG_SETMASK, &saved, NULL);
#if 0
/* This can cause hangs on some recentish systems which use locale
 * stuff for strerror...
 */
	pseudo_debug(4, "completed: utimes (maybe: %s)\n", strerror(save_errno));
#endif
	pseudo_debug(4, "completed: utimes (errno: %d)\n", save_errno);
	errno = save_errno;
	return rc;
}

static int
wrap_utimes(const char *path, const struct timeval *times) {
	int rc = -1;
	
	

#include "ports/unix/guts/utimes.c"

	return rc;
}


