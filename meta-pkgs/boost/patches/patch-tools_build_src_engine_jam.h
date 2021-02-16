$NetBSD$

--- ./tools/build/src/engine/jam.h.orig	2020-12-03 05:02:49.000000000 +0000
+++ ./tools/build/src/engine/jam.h
@@ -177,7 +177,7 @@
     #define OSMINOR "OS=CYGWIN"
     #define OS_CYGWIN
 #endif
-#if defined(__FreeBSD__) && !defined(__DragonFly__)
+#if (defined(__FreeBSD__) || defined(__QuinnBSD__)) && !defined(__DragonFly__)
     #define OSMINOR "OS=FREEBSD"
     #define OS_FREEBSD
 #endif
