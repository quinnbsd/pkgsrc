$NetBSD$

--- ./Source/ThirdParty/ANGLE/src/common/platform.h.orig	2020-08-12 09:17:53.000000000 +0000
+++ ./Source/ThirdParty/ANGLE/src/common/platform.h
@@ -28,7 +28,7 @@
 #    define ANGLE_PLATFORM_POSIX 1
 #elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) ||              \
     defined(__DragonFly__) || defined(__sun) || defined(__GLIBC__) || defined(__GNU__) || \
-    defined(__QNX__) || defined(__Fuchsia__) || defined(__HAIKU__)
+    defined(__QNX__) || defined(__Fuchsia__) || defined(__HAIKU__) || defined(__QuinnBSD__)
 #    define ANGLE_PLATFORM_POSIX 1
 #else
 #    error Unsupported platform.
