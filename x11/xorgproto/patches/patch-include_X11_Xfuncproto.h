$NetBSD$

--- include/X11/Xfuncproto.h.orig	2020-04-14 15:29:25.000000000 +0000
+++ include/X11/Xfuncproto.h
@@ -49,7 +49,7 @@ in this Software without prior written a
 
 /* Function prototype configuration (see configure for more info) */
 #if !defined(NARROWPROTO) && \
-    (defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
+    (defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__))
 #define NARROWPROTO
 #endif
 #ifndef FUNCPROTO
