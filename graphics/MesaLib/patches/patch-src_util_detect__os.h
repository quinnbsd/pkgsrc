$NetBSD$

--- src/util/detect_os.h.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/util/detect_os.h
@@ -28,7 +28,7 @@
 #define DETECT_OS_ANDROID 1
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #define DETECT_OS_FREEBSD 1
 #define DETECT_OS_BSD 1
 #define DETECT_OS_UNIX 1
