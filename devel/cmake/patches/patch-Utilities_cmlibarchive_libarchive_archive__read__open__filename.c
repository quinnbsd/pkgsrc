$NetBSD$

--- Utilities/cmlibarchive/libarchive/archive_read_open_filename.c.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibarchive/libarchive/archive_read_open_filename.c
@@ -50,7 +50,7 @@ __FBSDID("$FreeBSD: head/lib/libarchive/
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #include <sys/disk.h>
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/disklabel.h>
@@ -224,7 +224,7 @@ file_open(struct archive *a, void *clien
 	const wchar_t *wfilename = NULL;
 	int fd = -1;
 	int is_disk_like = 0;
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 	off_t mediasize = 0; /* FreeBSD-specific, so off_t okay here. */
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 	struct disklabel dl;
@@ -313,7 +313,7 @@ file_open(struct archive *a, void *clien
 		/* Regular files act like disks. */
 		is_disk_like = 1;
 	}
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 	/* FreeBSD: if it supports DIOCGMEDIASIZE ioctl, it's disk-like. */
 	else if (S_ISCHR(st.st_mode) &&
 	    ioctl(fd, DIOCGMEDIASIZE, &mediasize) == 0 &&
