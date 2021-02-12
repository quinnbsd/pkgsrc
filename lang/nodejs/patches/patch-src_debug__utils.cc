$NetBSD$

--- src/debug_utils.cc.orig	2021-01-04 13:59:34.000000000 +0000
+++ src/debug_utils.cc
@@ -32,7 +32,7 @@
 
 #if defined(__linux__) || defined(__sun) || \
     defined(__FreeBSD__) || defined(__OpenBSD__) || \
-    defined(__DragonFly__)
+    defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <link.h>
 #endif
 
@@ -372,7 +372,7 @@ void PrintLibuvHandleInformation(uv_loop
 std::vector<std::string> NativeSymbolDebuggingContext::GetLoadedLibraries() {
   std::vector<std::string> list;
 #if defined(__linux__) || defined(__FreeBSD__) || \
-    defined(__OpenBSD__) || defined(__DragonFly__)
+    defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
   dl_iterate_phdr(
       [](struct dl_phdr_info* info, size_t size, void* data) {
         auto list = static_cast<std::vector<std::string>*>(data);
