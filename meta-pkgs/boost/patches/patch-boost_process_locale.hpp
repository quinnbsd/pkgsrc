$NetBSD$

--- ./boost/process/locale.hpp.orig	2020-12-03 05:02:13.000000000 +0000
+++ ./boost/process/locale.hpp
@@ -12,7 +12,7 @@
 #if defined(BOOST_WINDOWS_API)
 #include <boost/process/detail/windows/locale.hpp>
 # elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) \
-|| defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__)
+|| defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__) || defined(__QuinnBSD__)
 #include <codecvt>
 #endif
 
@@ -72,7 +72,7 @@ inline std::locale default_locale()
     std::locale global_loc = std::locale();
     return std::locale(global_loc, new boost::process::detail::windows::windows_file_codecvt);
 # elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) \
-|| defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__)
+|| defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__HAIKU__) || defined(__QuinnBSD__)
     std::locale global_loc = std::locale();
     return std::locale(global_loc, new std::codecvt_utf8<wchar_t>);
 # else  // Other POSIX
