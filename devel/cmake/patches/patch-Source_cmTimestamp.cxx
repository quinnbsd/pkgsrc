$NetBSD$

--- Source/cmTimestamp.cxx.orig	2021-01-28 15:28:45.000000000 +0000
+++ Source/cmTimestamp.cxx
@@ -6,7 +6,7 @@
 #  define _POSIX_C_SOURCE 200809L
 #endif
 #if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) ||    \
-  defined(__QNX__)
+  defined(__QNX__) || defined(__QuinnBSD__)
 // For isascii
 #  define _XOPEN_SOURCE 700
 #endif
