$NetBSD$

--- include/SDL_platform.h.orig	2020-12-21 17:44:36.000000000 +0000
+++ include/SDL_platform.h
@@ -44,7 +44,7 @@
 #undef __DREAMCAST__
 #define __DREAMCAST__   1
 #endif
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #undef __FREEBSD__
 #define __FREEBSD__ 1
 #endif
