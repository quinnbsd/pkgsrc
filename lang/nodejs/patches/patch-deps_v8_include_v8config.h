$NetBSD$

--- deps/v8/include/v8config.h.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/v8/include/v8config.h
@@ -96,7 +96,7 @@
 #elif defined(_AIX)
 #define V8_OS_POSIX 1
 #define V8_OS_AIX 1
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 # define V8_OS_BSD 1
 # define V8_OS_FREEBSD 1
 # define V8_OS_POSIX 1
