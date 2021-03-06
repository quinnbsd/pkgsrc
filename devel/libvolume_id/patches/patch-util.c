$NetBSD$

--- util.c.orig	2009-03-02 18:17:35.000000000 +0000
+++ util.c
@@ -28,9 +28,13 @@
 #include "libvolume_id.h"
 #include "util.h"
 
-#ifdef __FreeBSD__
+#if defined(__OpenBSD__)
+#define __POSIX_VISIBLE	200809
+#endif
+
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__) || defined(__MirBSD__) || defined(__QuinnBSD__)
 #include <sys/param.h>
-#if __FreeBSD_version < 800067
+#if __FreeBSD_version < 800067 && __DragonFly_version < 200202 && __NetBSD_Version__ < 599001100 && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ < 1070
 static size_t strnlen (const char *s, size_t maxlen)
 {
 	size_t i;
