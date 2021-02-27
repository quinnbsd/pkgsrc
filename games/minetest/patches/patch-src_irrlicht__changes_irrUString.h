$NetBSD$

--- src/irrlicht_changes/irrUString.h.orig	2021-02-23 18:50:37.000000000 +0000
+++ src/irrlicht_changes/irrUString.h
@@ -48,7 +48,7 @@
 #define __BIG_ENDIAN 1
 #elif defined(__MACH__) && defined(__APPLE__)
 #include <machine/endian.h>
-#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
