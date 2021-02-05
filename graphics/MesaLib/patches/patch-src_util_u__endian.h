$NetBSD$

--- src/util/u_endian.h.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/util/u_endian.h
@@ -61,7 +61,7 @@
 #endif
 
 #elif defined(__OpenBSD__) || defined(__NetBSD__) || \
-      defined(__FreeBSD__) || defined(__DragonFly__)
+      defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <sys/types.h>
 #include <machine/endian.h>
 
