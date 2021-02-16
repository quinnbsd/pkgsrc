$NetBSD$

--- boost/config/detail/select_platform_config.hpp.orig	2021-02-16 09:40:25.065852000 +0000
+++ boost/config/detail/select_platform_config.hpp
@@ -17,7 +17,7 @@
 // linux, also other platforms (Hurd etc) that use GLIBC, should these really have their own config headers though?
 #  define BOOST_PLATFORM_CONFIG "boost/config/platform/linux.hpp"
 
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 // BSD:
 #  define BOOST_PLATFORM_CONFIG "boost/config/platform/bsd.hpp"
 
