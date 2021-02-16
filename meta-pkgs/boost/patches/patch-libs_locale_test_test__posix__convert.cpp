$NetBSD$

--- ./libs/locale/test/test_posix_convert.cpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/test/test_posix_convert.cpp
@@ -59,7 +59,7 @@ void test_char()
         std::cout << "Testing " << name << std::endl;
         std::locale l=gen(name);
         test_one<CharType>(l,"Hello World","hello world","HELLO WORLD");
-        #if defined(__APPLE__) || defined(__FreeBSD__)
+        #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
         if(sizeof(CharType)!=1)
         #endif
             test_one<CharType>(l,"Façade","façade","FAÇADE");
