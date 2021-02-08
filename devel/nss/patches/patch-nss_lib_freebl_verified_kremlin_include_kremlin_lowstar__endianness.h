$NetBSD$

--- nss/lib/freebl/verified/kremlin/include/kremlin/lowstar_endianness.h.orig	2021-01-22 17:08:28.000000000 +0000
+++ nss/lib/freebl/verified/kremlin/include/kremlin/lowstar_endianness.h
@@ -52,7 +52,7 @@
 #define be32toh(x) BE_32(x)
 
 /* ... for the BSDs */
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <sys/endian.h>
 #elif defined(__OpenBSD__)
 #include <endian.h>
