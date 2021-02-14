$NetBSD$

--- src/window.c.orig	2020-12-12 13:32:03.000000000 +0000
+++ src/window.c
@@ -43,7 +43,7 @@
 #ifdef __APPLE__
 #include <libkern/OSByteOrder.h>
 #define le32toh(x) OSSwapLittleToHostInt32(x)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/endian.h>
 #else
 #include <endian.h>
