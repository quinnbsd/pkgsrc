$NetBSD$

--- ./boost/wave/token_ids.hpp.orig	2020-12-03 05:02:42.000000000 +0000
+++ ./boost/wave/token_ids.hpp
@@ -27,7 +27,7 @@
 #if !defined(BOOST_WAVE_TOKEN_IDS_DEFINED)
 #define BOOST_WAVE_TOKEN_IDS_DEFINED
 
-#if (defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)) && defined (T_DIVIDE)
+#if (defined (__FreeBSD__) || defined(__QuinnBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)) && defined (T_DIVIDE)
 #undef T_DIVIDE
 #endif
 
