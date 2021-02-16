$NetBSD$

--- ./libs/filesystem/src/path.cpp.orig	2020-12-03 05:01:22.000000000 +0000
+++ ./libs/filesystem/src/path.cpp
@@ -32,7 +32,7 @@
 # include "windows_file_codecvt.hpp"
 # include <windows.h>
 #elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) \
- || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__)
+ || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__) || defined(__QuinnBSD__)
 # include <boost/filesystem/detail/utf8_codecvt_facet.hpp>
 #endif
 
@@ -864,7 +864,7 @@ namespace
     std::locale global_loc = std::locale();
     return std::locale(global_loc, new windows_file_codecvt);
 # elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) \
-  || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__)
+  || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__) || defined(__QuinnBSD__)
     // "All BSD system functions expect their string parameters to be in UTF-8 encoding
     // and nothing else." See
     // http://developer.apple.com/mac/library/documentation/MacOSX/Conceptual/BPInternational/Articles/FileEncodings.html
