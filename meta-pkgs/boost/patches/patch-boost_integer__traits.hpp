$NetBSD$

--- ./boost/integer_traits.hpp.orig	2020-12-03 05:01:41.000000000 +0000
+++ ./boost/integer_traits.hpp
@@ -110,7 +110,7 @@ class integer_traits<wchar_t>
     || (defined __APPLE__)\
     || (defined(__OpenBSD__) && defined(__GNUC__))\
     || (defined(__NetBSD__) && defined(__GNUC__))\
-    || (defined(__FreeBSD__) && defined(__GNUC__))\
+    || ((defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(__GNUC__))\
     || (defined(__DragonFly__) && defined(__GNUC__))\
     || (defined(__hpux) && defined(__GNUC__) && (__GNUC__ == 3) && !defined(__SGI_STL_PORT))
     // No WCHAR_MIN and WCHAR_MAX, wchar_t has the same range as int.
