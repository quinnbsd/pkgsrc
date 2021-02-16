$NetBSD$

--- ./boost/predef/os/bsd/free.h.orig	2020-12-03 05:02:11.000000000 +0000
+++ ./boost/predef/os/bsd/free.h
@@ -28,7 +28,7 @@ http://en.wikipedia.org/wiki/Freebsd[Fre
 #define BOOST_OS_BSD_FREE BOOST_VERSION_NUMBER_NOT_AVAILABLE
 
 #if !defined(BOOST_PREDEF_DETAIL_OS_DETECTED) && ( \
-    defined(__FreeBSD__) \
+    defined(__FreeBSD__) || defined(__QuinnBSD__)\
     )
 #   ifndef BOOST_OS_BSD_AVAILABLE
 #       define BOOST_OS_BSD BOOST_VERSION_NUMBER_AVAILABLE
