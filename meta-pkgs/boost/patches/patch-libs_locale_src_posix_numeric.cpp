$NetBSD$

--- ./libs/locale/src/posix/numeric.cpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/src/posix/numeric.cpp
@@ -6,7 +6,7 @@
 //  http://www.boost.org/LICENSE_1_0.txt)
 //
 #define BOOST_LOCALE_SOURCE
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <xlocale.h>
 #endif
 #include <locale>
@@ -388,7 +388,7 @@ struct basic_numpunct {
     }
     basic_numpunct(locale_t lc) 
     {
-    #if defined(__APPLE__) || defined(__FreeBSD__)
+    #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
         lconv *cv = localeconv_l(lc);
         grouping = cv->grouping;
         thousands_sep = cv->thousands_sep;
