$NetBSD$

--- sexyz/zmodem.c.orig	2020-11-20 09:21:06.000000000 +0000
+++ sexyz/zmodem.c
@@ -71,7 +71,7 @@
 #define IAC 255
 #if defined(__linux__)
 #include <sys/statfs.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/mount.h>
 #include <sys/param.h>
 #elif defined(__NetBSD__)
@@ -83,7 +83,7 @@
 #endif
 
 static uint32_t getfreediskspace(const char *directory, int unit) {
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 	struct statfs sfs;
 	uint32_t blocks;
 
