$NetBSD$

--- Source/cmLoadCommandCommand.cxx.orig	2021-01-28 15:28:45.000000000 +0000
+++ Source/cmLoadCommandCommand.cxx
@@ -5,7 +5,7 @@
 // POSIX APIs are needed
 #  define _POSIX_C_SOURCE 200809L
 #endif
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 // For isascii
 #  define _XOPEN_SOURCE 700
 #endif
