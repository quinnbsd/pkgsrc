$NetBSD$

--- lib/irrlicht/source/Irrlicht/os.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/os.cpp
@@ -22,7 +22,7 @@
 	#include <libkern/OSByteOrder.h>
 	#define bswap_16(X) OSReadSwapInt16(&X,0)
 	#define bswap_32(X) OSReadSwapInt32(&X,0)
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#elif defined(__QuinnBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 	#include <sys/endian.h>
 	#define bswap_16(X) bswap16(X)
 	#define bswap_32(X) bswap32(X)
