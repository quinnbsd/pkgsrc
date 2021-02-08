$NetBSD$

--- libnsfb/src/plot.h.orig	2020-05-24 21:35:21.000000000 +0000
+++ libnsfb/src/plot.h
@@ -35,7 +35,7 @@
     #if __DARWIN_BYTE_ORDER == __DARWIN_BIG_ENDIAN
         #define NSFB_BE_BYTE_ORDER
     #endif
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     /* freebsd has the include somewhere different */
     #include <machine/endian.h>
     #if defined(_BYTE_ORDER)
