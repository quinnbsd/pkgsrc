$NetBSD$

--- Utilities/cmlibuv/include/uv/errno.h.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibuv/include/uv/errno.h
@@ -415,7 +415,8 @@
       defined(__FreeBSD__) || \
       defined(__FreeBSD_kernel__) || \
       defined(__NetBSD__) || \
-      defined(__OpenBSD__)
+      defined(__OpenBSD__) || \
+      defined(__QuinnBSD__)
 # define UV__EHOSTDOWN (-64)
 #else
 # define UV__EHOSTDOWN (-4031)
