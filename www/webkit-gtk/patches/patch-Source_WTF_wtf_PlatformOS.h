$NetBSD$

--- ./Source/WTF/wtf/PlatformOS.h.orig	2020-08-12 09:17:54.000000000 +0000
+++ ./Source/WTF/wtf/PlatformOS.h
@@ -85,7 +85,7 @@
 #endif
 
 /* OS(FREEBSD) - FreeBSD */
-#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #define WTF_OS_FREEBSD 1
 #endif
 
@@ -114,6 +114,11 @@
 #define WTF_OS_OPENBSD 1
 #endif
 
+/* OS(SOLARIS) - Solaris and derivatives */
+#ifdef __sun
+#define WTF_OS_SOLARIS 1
+#endif
+
 /* OS(WINDOWS) - Any version of Windows */
 #if defined(WIN32) || defined(_WIN32)
 #define WTF_OS_WINDOWS 1
@@ -129,6 +134,7 @@
     || OS(LINUX)            \
     || OS(NETBSD)           \
     || OS(OPENBSD)          \
+    || OS(SOLARIS)          \
     || defined(unix)        \
     || defined(__unix)      \
     || defined(__unix__)
