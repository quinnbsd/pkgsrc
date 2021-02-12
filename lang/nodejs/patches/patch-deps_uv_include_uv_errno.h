$NetBSD$

--- deps/uv/include/uv/errno.h.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/include/uv/errno.h
@@ -415,7 +415,7 @@
       defined(__FreeBSD__) || \
       defined(__FreeBSD_kernel__) || \
       defined(__NetBSD__) || \
-      defined(__OpenBSD__)
+      defined(__OpenBSD__) || defined(__QuinnBSD__)
 # define UV__EHOSTDOWN (-64)
 #else
 # define UV__EHOSTDOWN (-4031)
