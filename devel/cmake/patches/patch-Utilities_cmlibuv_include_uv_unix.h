$NetBSD$

--- Utilities/cmlibuv/include/uv/unix.h.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibuv/include/uv/unix.h
@@ -68,7 +68,8 @@
       defined(__FreeBSD__)         || \
       defined(__FreeBSD_kernel__)  || \
       defined(__OpenBSD__)         || \
-      defined(__NetBSD__)
+      defined(__NetBSD__)          || \
+      defined(__QuinnBSD__)
 # include "bsd.h"
 #elif defined(__CYGWIN__) || \
       defined(__MSYS__)   || \
