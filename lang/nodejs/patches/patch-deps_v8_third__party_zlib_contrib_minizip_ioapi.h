$NetBSD$

--- deps/v8/third_party/zlib/contrib/minizip/ioapi.h.orig	2021-01-04 13:59:34.000000000 +0000
+++ deps/v8/third_party/zlib/contrib/minizip/ioapi.h
@@ -50,7 +50,7 @@
 #define ftello64 ftell
 #define fseeko64 fseek
 #else
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
