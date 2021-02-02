$NetBSD$

--- git-compat-util.h.orig	2020-12-28 03:26:32.000000000 +0000
+++ git-compat-util.h
@@ -143,7 +143,7 @@
 #elif !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__USLC__) && \
       !defined(_M_UNIX) && !defined(__sgi) && !defined(__DragonFly__) && \
       !defined(__TANDEM) && !defined(__QNX__) && !defined(__MirBSD__) && \
-      !defined(__CYGWIN__)
+      !defined(__CYGWIN__) && !defined(__QuinnBSD__)
 #define _XOPEN_SOURCE 600 /* glibc2 and AIX 5.3L need 500, OpenBSD needs 600 for S_ISLNK() */
 #define _XOPEN_SOURCE_EXTENDED 1 /* AIX 5.3L needs this */
 #endif
