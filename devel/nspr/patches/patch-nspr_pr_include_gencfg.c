$NetBSD$

--- nspr/pr/include/gencfg.c.orig	2020-09-17 15:01:34.000000000 +0000
+++ nspr/pr/include/gencfg.c
@@ -18,7 +18,7 @@ error - HPUX is not defined
 #endif
 
 #if defined(__alpha)
-#if !(defined(_WIN32)) && !(defined(__linux)) && !(defined(__FreeBSD__))
+#if !(defined(_WIN32)) && !(defined(__linux)) && !(defined(__FreeBSD__) && !(defined(__QuinnBSD__))
 error - None of _WIN32, __linux, or __FreeBSD__ is defined
 #endif
 #endif
