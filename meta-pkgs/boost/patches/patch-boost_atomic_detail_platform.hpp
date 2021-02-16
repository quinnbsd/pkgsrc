$NetBSD$

--- ./boost/atomic/detail/platform.hpp.orig	2020-12-03 05:01:08.000000000 +0000
+++ ./boost/atomic/detail/platform.hpp
@@ -152,7 +152,7 @@
 
 #if defined(BOOST_ATOMIC_DETAIL_HAS_FUTEX)
 #define BOOST_ATOMIC_DETAIL_WAIT_BACKEND futex
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/param.h>
 // FreeBSD prior to 7.0 had _umtx_op with a different signature
 #if defined(__FreeBSD_version) && __FreeBSD_version >= 700000
