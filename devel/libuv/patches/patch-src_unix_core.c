$NetBSD$

--- src/unix/core.c.orig	2020-09-25 00:34:43.000000000 +0000
+++ src/unix/core.c
@@ -67,11 +67,11 @@ extern char** environ;
     defined(__FreeBSD__)        || \
     defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__)         || \
-    defined(__OpenBSD__)
+    defined(__OpenBSD__) || defined(__QuinnBSD__)
 # include <sys/sysctl.h>
 # include <sys/filio.h>
 # include <sys/wait.h>
-# if defined(__FreeBSD__)
+# if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #  define uv__accept4 accept4
 # endif
 # if defined(__NetBSD__)
@@ -1029,7 +1029,7 @@ int uv__open_cloexec(const char* path, i
 
 
 int uv__dup2_cloexec(int oldfd, int newfd) {
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__linux__) || defined(__QuinnBSD__)
   int r;
 
   r = dup3(oldfd, newfd, O_CLOEXEC);
