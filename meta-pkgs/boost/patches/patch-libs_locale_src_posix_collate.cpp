$NetBSD$

--- ./libs/locale/src/posix/collate.cpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/src/posix/collate.cpp
@@ -6,7 +6,7 @@
 //  http://www.boost.org/LICENSE_1_0.txt)
 //
 #define BOOST_LOCALE_SOURCE
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <xlocale.h>
 #endif
 #include <locale>
