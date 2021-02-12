$NetBSD$

--- ./Source/bmalloc/bmalloc/BPlatform.h.orig	2020-08-12 09:17:57.000000000 +0000
+++ ./Source/bmalloc/bmalloc/BPlatform.h
@@ -48,10 +48,18 @@
 #define BOS_LINUX 1
 #endif
 
-#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#ifdef __sun
+#define BOS_SOLARIS 1
+#endif
+
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #define BOS_FREEBSD 1
 #endif
 
+#if defined(__NetBSD__)
+#define BOS_NETBSD 1
+#endif
+
 #if defined(WIN32) || defined(_WIN32)
 #define BOS_WINDOWS 1
 #endif
