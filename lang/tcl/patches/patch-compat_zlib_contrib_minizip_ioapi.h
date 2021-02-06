$NetBSD$

--- compat/zlib/contrib/minizip/ioapi.h.orig	2020-07-06 20:41:07.000000000 +0000
+++ compat/zlib/contrib/minizip/ioapi.h
@@ -50,7 +50,7 @@
 #define ftello64 ftell
 #define fseeko64 fseek
 #else
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
