$NetBSD$

--- ./libs/math/test/test_gamma_hooks.hpp.orig	2020-12-03 05:01:55.000000000 +0000
+++ ./libs/math/test/test_gamma_hooks.hpp
@@ -77,7 +77,7 @@ inline long double gamma_p(long double x
 #ifdef TEST_NATIVE
 #include <math.h>
 namespace other{
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 // no float version:
 inline float tgamma(float x)
 { return ::tgamma(x); }
@@ -89,14 +89,14 @@ inline double tgamma(double x)
 { return ::tgamma(x); }
 inline long double tgamma(long double x)
 { 
-#if defined(__CYGWIN__) || defined(__FreeBSD__)
+#if defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
    // no long double versions:
    return ::tgamma(x);
 #else
    return ::tgammal(x);
 #endif
 }
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 inline float lgamma(float x)
 { return ::lgamma(x); }
 #else
@@ -107,7 +107,7 @@ inline double lgamma(double x)
 { return ::lgamma(x); }
 inline long double lgamma(long double x)
 { 
-#if defined(__CYGWIN__) || defined(__FreeBSD__) 
+#if defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
    // no long double versions:
    return ::lgamma(x); 
 #else
