$NetBSD$

--- ./libs/type_traits/test/promote_basic_test.cpp.orig	2020-12-03 05:02:36.000000000 +0000
+++ ./libs/type_traits/test/promote_basic_test.cpp
@@ -67,7 +67,7 @@ int main()
     || (defined __APPLE__)\
     || (defined(__OpenBSD__) && defined(__GNUC__))\
     || (defined(__NetBSD__) && defined(__GNUC__))\
-    || (defined(__FreeBSD__) && defined(__GNUC__))\
+    || ((defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(__GNUC__))\
     || (defined(__DragonFly__) && defined(__GNUC__))\
     || (defined(__hpux) && defined(__GNUC__) && (__GNUC__ == 3) && !defined(__SGI_STL_PORT))
     // No WCHAR_MIN and WCHAR_MAX, wchar_t has the same range as int.
