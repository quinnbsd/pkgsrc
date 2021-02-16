$NetBSD$

--- ./libs/locale/test/test_posix_tools.hpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/test/test_posix_tools.hpp
@@ -12,7 +12,7 @@
 #include <locale.h>
 #include <string>
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <xlocale.h>
 #endif
 
