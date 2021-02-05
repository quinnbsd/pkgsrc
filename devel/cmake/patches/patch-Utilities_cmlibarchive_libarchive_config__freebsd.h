$NetBSD$

--- Utilities/cmlibarchive/libarchive/config_freebsd.h.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibarchive/libarchive/config_freebsd.h
@@ -28,7 +28,7 @@
 #include <osreldate.h>
 
 /* FreeBSD 5.0 and later has ACL and extattr support. */
-#if __FreeBSD__ > 4
+#if __FreeBSD__ > 4 || defined(__QuinnBSD__)
 #define ARCHIVE_ACL_FREEBSD 1
 #define HAVE_ACL_GET_PERM_NP 1
 #define HAVE_ARC4RANDOM_BUF 1
@@ -39,7 +39,7 @@
 #define HAVE_STRUCT_XVFSCONF 1
 #define HAVE_SYS_ACL_H 1
 #define HAVE_SYS_EXTATTR_H 1
-#if __FreeBSD__ > 7
+#if __FreeBSD__ > 7 || defined(__QuinnBSD__)
 /* FreeBSD 8.0 and later has NFSv4 ACL support */
 #define ARCHIVE_ACL_FREEBSD_NFS4 1
 #define HAVE_ACL_GET_LINK_NP 1
@@ -239,7 +239,7 @@
 #endif
 
 /* FreeBSD 4 and earlier lack intmax_t/uintmax_t */
-#if __FreeBSD__ < 5
+#if __FreeBSD__ < 5 && !defined(__QuinnBSD__)
 #define intmax_t int64_t
 #define uintmax_t uint64_t
 #endif
