$NetBSD$

--- ./boost/thread/detail/platform.hpp.orig	2020-12-03 05:02:33.000000000 +0000
+++ ./boost/thread/detail/platform.hpp
@@ -20,7 +20,7 @@
 #if defined(linux) || defined(__linux) || defined(__linux__)
 #  define BOOST_THREAD_LINUX
 //#  define BOOST_THREAD_WAIT_BUG boost::posix_time::microseconds(100000)
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #  define BOOST_THREAD_BSD
 #elif defined(sun) || defined(__sun)
 #  define BOOST_THREAD_SOLARIS
