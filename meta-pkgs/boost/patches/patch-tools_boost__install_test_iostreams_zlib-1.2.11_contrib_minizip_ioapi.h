$NetBSD$

--- ./tools/boost_install/test/iostreams/zlib-1.2.11/contrib/minizip/ioapi.h.orig	2020-12-03 05:02:46.000000000 +0000
+++ ./tools/boost_install/test/iostreams/zlib-1.2.11/contrib/minizip/ioapi.h
@@ -50,7 +50,7 @@
 #define ftello64 ftell
 #define fseeko64 fseek
 #else
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #define fopen64 fopen
 #define ftello64 ftello
 #define fseeko64 fseeko
