$NetBSD$

--- Utilities/cmlibuv/src/unix/core.c.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibuv/src/unix/core.c
@@ -68,13 +68,14 @@ extern char** environ;
     defined(__FreeBSD__)        || \
     defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__)         || \
-    defined(__OpenBSD__)
+    defined(__OpenBSD__)        || \
+    defined(__QuinnBSD__)
 # include <sys/sysctl.h>
 # include <sys/filio.h>
 # include <sys/wait.h>
 # include <sys/param.h>
 # include <sys/cpuset.h>
-# if defined(__FreeBSD__)
+# if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #  define uv__accept4 accept4
 # endif
 # if defined(__NetBSD__)
@@ -1032,7 +1033,7 @@ int uv__open_cloexec(const char* path, i
 
 
 int uv__dup2_cloexec(int oldfd, int newfd) {
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__linux__) || defined(__QuinnBSD__)
   int r;
 
   r = dup3(oldfd, newfd, O_CLOEXEC);
@@ -1390,7 +1391,7 @@ int uv_os_gethostname(char* buffer, size
 
 
 int uv_cpumask_size(void) {
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
   return CPU_SETSIZE;
 #else
   return UV_ENOTSUP;
