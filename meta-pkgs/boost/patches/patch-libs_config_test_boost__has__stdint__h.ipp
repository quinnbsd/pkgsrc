$NetBSD$

--- ./libs/config/test/boost_has_stdint_h.ipp.orig	2020-12-03 05:01:13.000000000 +0000
+++ ./libs/config/test/boost_has_stdint_h.ipp
@@ -15,7 +15,7 @@
 //                 presence; thus the default is not present, conforming
 //                 to the current C++ standard).
 
-# if defined(__hpux) || defined(__FreeBSD__) || defined(__IBMCPP__)
+# if defined(__hpux) || defined(__FreeBSD__) || defined(__IBMCPP__) || defined(__QuinnBSD__)
 #   include <inttypes.h>
 # else
 #   include <stdint.h>
