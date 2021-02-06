$NetBSD$

--- dix/Xserver.d.orig	2020-12-01 16:32:25.000000000 +0000
+++ dix/Xserver.d
@@ -27,7 +27,7 @@
 #define string char *
 #define pid_t uint32_t
 #define zoneid_t uint32_t
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #define zoneid_t id_t
 #else
 #include <sys/types.h>
