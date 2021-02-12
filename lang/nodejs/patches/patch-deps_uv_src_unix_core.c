$NetBSD$

--- deps/uv/src/unix/core.c.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/src/unix/core.c
@@ -67,7 +67,7 @@ extern char** environ;
     defined(__FreeBSD__)        || \
     defined(__FreeBSD_kernel__) || \
     defined(__NetBSD__)         || \
-    defined(__OpenBSD__)
+    defined(__OpenBSD__) || defined(__QuinnBSD__)
 # include <sys/sysctl.h>
 # include <sys/filio.h>
 # include <sys/wait.h>
