$NetBSD$

--- netsurf/content/handlers/javascript/duktape/duk_config.h.orig	2020-05-24 21:35:23.000000000 +0000
+++ netsurf/content/handlers/javascript/duktape/duk_config.h
@@ -74,7 +74,7 @@
 #endif
 
 /* FreeBSD */
-#if defined(__FreeBSD__) || defined(__FreeBSD)
+#if defined(__FreeBSD__) || defined(__FreeBSD) || defined(__QuinnBSD__) || defined(__QuinnBSD)
 #define DUK_F_FREEBSD
 #endif
 
