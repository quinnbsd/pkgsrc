$NetBSD$

--- ./boost/interprocess/mapped_region.hpp.orig	2020-12-03 05:01:42.000000000 +0000
+++ ./boost/interprocess/mapped_region.hpp
@@ -41,7 +41,7 @@
 
 //A lot of UNIXes have destructive semantics for MADV_DONTNEED, so
 //we need to be careful to allow it.
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
 #define BOOST_INTERPROCESS_MADV_DONTNEED_HAS_NONDESTRUCTIVE_SEMANTICS
 #endif
 
