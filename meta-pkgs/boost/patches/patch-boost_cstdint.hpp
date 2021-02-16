$NetBSD$

--- ./boost/cstdint.hpp.orig	2020-12-03 05:01:13.000000000 +0000
+++ ./boost/cstdint.hpp
@@ -65,7 +65,7 @@
       // this is triggered with GCC, because it defines __cplusplus < 199707L
 #     define BOOST_NO_INT64_T
 #   endif
-# elif defined(__FreeBSD__) || defined(__IBMCPP__) || defined(_AIX)
+# elif defined(__FreeBSD__) || defined(__IBMCPP__) || defined(_AIX) || defined(__QuinnBSD__)
 #   include <inttypes.h>
 # else
 #   include <stdint.h>
@@ -381,7 +381,7 @@ namespace boost
 #if (defined(BOOST_WINDOWS) && !defined(_WIN32_WCE)) \
     || (defined(_XOPEN_UNIX) && (_XOPEN_UNIX+0 > 0) && !defined(__UCLIBC__)) \
     || defined(__CYGWIN__) || defined(__VXWORKS__) \
-    || defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) \
+    || defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__) || defined(__QuinnBSD__)  \
     || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || (defined(sun) && !defined(BOOST_HAS_STDINT_H)) || defined(INTPTR_MAX)
 
 namespace boost {
