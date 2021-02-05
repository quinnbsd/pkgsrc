$NetBSD$

--- Source/cmStandardLexer.h.orig	2021-01-28 15:28:45.000000000 +0000
+++ Source/cmStandardLexer.h
@@ -14,7 +14,7 @@
 /* C sources: for fileno and strdup */
 #  define _XOPEN_SOURCE 600
 #endif
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 /* For isascii */
 #  define _XOPEN_SOURCE 700
 #endif
