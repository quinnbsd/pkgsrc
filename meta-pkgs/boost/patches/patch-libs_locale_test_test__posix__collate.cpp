$NetBSD$

--- ./libs/locale/test/test_posix_collate.cpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/test/test_posix_collate.cpp
@@ -74,7 +74,7 @@ void test_char()
     std::string name;
 
 
-    #if !defined(__APPLE__) && !defined(__FreeBSD__)
+    #if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__QuinnBSD__)
     std::string names[] = { "en_US.UTF-8", "en_US.ISO8859-1" };
     for(unsigned i=0;i<sizeof(names)/sizeof(names[0]);i++) {
         if(have_locale(names[i])) {
