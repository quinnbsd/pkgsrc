$NetBSD$

--- linux_raid.c.orig	2007-12-27 01:03:43.000000000 +0000
+++ linux_raid.c
@@ -22,9 +22,9 @@
 #include <string.h>
 #include <errno.h>
 #include <ctype.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__MirBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #include <sys/endian.h>
-#else
+#elif !defined(__APPLE__) && !defined(__sun)
 #include <byteswap.h>
 #endif /* __FreeBSD__ */
 
