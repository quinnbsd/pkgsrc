$NetBSD$

--- Utilities/cmlibarchive/libarchive/archive_getdate.c.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibarchive/libarchive/archive_getdate.c
@@ -30,7 +30,7 @@
 #ifndef CM_GET_DATE
 #include "archive_platform.h"
 #endif
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/cdefs.h>
 __FBSDID("$FreeBSD$");
 #endif
