/* 
 * Copyright (c) 2010 Wind River Systems; see
 * guts/COPYRIGHT for information.
 *
 * static int
 * wrap_ftw64(const char *path, int (*fn)(const char *, const struct stat64 *, int), int nopenfd) {
 *	int rc = -1;
 */

	rc = real_ftw64(path, fn, nopenfd);

/*	return rc;
 * }
 */
