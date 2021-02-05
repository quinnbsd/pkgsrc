$NetBSD$

--- include/uv/unix.h.orig	2020-09-25 00:34:43.000000000 +0000
+++ include/uv/unix.h
@@ -61,7 +61,7 @@
       defined(__FreeBSD__)         || \
       defined(__FreeBSD_kernel__)  || \
       defined(__OpenBSD__)         || \
-      defined(__NetBSD__)
+      defined(__NetBSD__) || defined(__QuinnBSD__)
 # include "uv/bsd.h"
 #elif defined(__CYGWIN__) || \
       defined(__MSYS__)   || \
