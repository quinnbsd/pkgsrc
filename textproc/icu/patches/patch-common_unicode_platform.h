$NetBSD$

--- common/unicode/platform.h.orig	2020-12-17 19:34:38.000000000 +0000
+++ common/unicode/platform.h
@@ -173,8 +173,8 @@
 #   else
 #       define U_PLATFORM U_PF_DARWIN
 #   endif
-#elif defined(BSD) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__MirBSD__)
-#   if defined(__FreeBSD__)
+#elif defined(BSD) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__MirBSD__) || defined(__QuinnBSD__)
+#   if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #       include <sys/endian.h>
 #   endif
 #   define U_PLATFORM U_PF_BSD
