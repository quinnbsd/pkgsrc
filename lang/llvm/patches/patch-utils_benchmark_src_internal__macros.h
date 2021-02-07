$NetBSD$

--- utils/benchmark/src/internal_macros.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ utils/benchmark/src/internal_macros.h
@@ -47,7 +47,7 @@
       #define BENCHMARK_OS_IOS 1
     #endif
   #endif
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
   #define BENCHMARK_OS_FREEBSD 1
 #elif defined(__NetBSD__)
   #define BENCHMARK_OS_NETBSD 1
