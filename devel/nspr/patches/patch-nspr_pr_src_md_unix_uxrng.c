$NetBSD$

--- nspr/pr/src/md/unix/uxrng.c.orig	2020-09-17 15:01:34.000000000 +0000
+++ nspr/pr/src/md/unix/uxrng.c
@@ -64,7 +64,7 @@ GetHighResClock(void *buf, size_t maxbyt
 
 #elif (defined(LINUX) || defined(FREEBSD) || defined(__FreeBSD_kernel__) \
     || defined(NETBSD) || defined(__NetBSD_kernel__) || defined(OPENBSD) \
-    || defined(__GNU__))
+    || defined(__GNU__)) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
