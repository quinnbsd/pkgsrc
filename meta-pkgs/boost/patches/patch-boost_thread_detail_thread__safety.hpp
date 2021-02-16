$NetBSD$

--- ./boost/thread/detail/thread_safety.hpp.orig	2020-12-03 05:02:33.000000000 +0000
+++ ./boost/thread/detail/thread_safety.hpp
@@ -80,7 +80,7 @@
 #define BOOST_THREAD_NO_THREAD_SAFETY_ANALYSIS \
   BOOST_THREAD_ANNOTATION_ATTRIBUTE__(no_thread_safety_analysis)
 
-#if defined(__clang__) && (!defined(SWIG)) && defined(__FreeBSD__)
+#if defined(__clang__) && (!defined(SWIG)) && (defined(__FreeBSD__) || defined(__QuinnBSD__))
 #if __has_attribute(no_thread_safety_analysis)
 #define BOOST_THREAD_DISABLE_THREAD_SAFETY_ANALYSIS __attribute__((no_thread_safety_analysis))
 #else
