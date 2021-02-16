$NetBSD$

--- ./libs/locale/src/util/numeric.hpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/src/util/numeric.hpp
@@ -190,7 +190,7 @@ private:
     {
         std::string tz = ios_info::get(ios).time_zone();
         std::tm tm;
-        #if defined(__linux) || defined(__FreeBSD__) || defined(__APPLE__) 
+        #if defined(__linux) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
         std::vector<char> tmp_buf(tz.c_str(),tz.c_str()+tz.size()+1);
         #endif
         if(tz.empty()) {
@@ -211,7 +211,7 @@ private:
             gmtime_r(&time,&tm);
             #endif
             
-            #if defined(__linux) || defined(__FreeBSD__) || defined(__APPLE__) 
+            #if defined(__linux) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
             // These have extra fields to specify timezone
             if(gmtoff!=0) {
                 // bsd and apple want tm_zone be non-const
