$NetBSD$

--- ./libs/locale/src/icu/time_zone.cpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/src/icu/time_zone.cpp
@@ -19,7 +19,7 @@
 //
 
 #if U_ICU_VERSION_MAJOR_NUM == 4 && (U_ICU_VERSION_MINOR_NUM * 100 + U_ICU_VERSION_PATCHLEVEL_NUM) <= 402
-# if defined(__linux) || defined(__FreeBSD__) || defined(__APPLE__)
+# if defined(__linux) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
 #   define BOOST_LOCALE_WORKAROUND_ICU_BUG
 # endif
 #endif
