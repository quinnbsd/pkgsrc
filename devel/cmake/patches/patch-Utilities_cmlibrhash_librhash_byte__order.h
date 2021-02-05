$NetBSD$

--- Utilities/cmlibrhash/librhash/byte_order.h.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibrhash/librhash/byte_order.h
@@ -10,7 +10,7 @@
 #endif
 #endif
 
-#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__) || defined(__QuinnBSD__)
 # include <sys/types.h>
 #elif defined (__NetBSD__) || defined(__OpenBSD__)
 # include <sys/param.h>
