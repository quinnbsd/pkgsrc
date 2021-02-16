$NetBSD$

--- ./libs/locale/test/test_std_collate.cpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/test/test_std_collate.cpp
@@ -74,7 +74,7 @@ void test_char()
 
     std::string name;
 
-    #if defined(_LIBCPP_VERSION) && (defined(__APPLE__) || defined(__FreeBSD__))
+    #if defined(_LIBCPP_VERSION) && (defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__))
     std::cout << "- Collation is broken on this OS's standard C++ library, skipping" << std::endl;
     #else
     std::string names[] = { "en_US.UTF-8", "en_US.ISO8859-1" };
