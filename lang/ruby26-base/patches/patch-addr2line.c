$NetBSD$

--- ./addr2line.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./addr2line.c
@@ -2039,7 +2039,7 @@ fail:
 #endif
 
 #define HAVE_MAIN_EXE_PATH
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 # include <sys/sysctl.h>
 #endif
 /* ssize_t main_exe_path(void)
@@ -2057,7 +2057,7 @@ main_exe_path(void)
     binary_filename[len] = 0;
     return len;
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 static ssize_t
 main_exe_path(void)
 {
