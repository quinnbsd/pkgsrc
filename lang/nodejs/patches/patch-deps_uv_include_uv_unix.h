$NetBSD$

--- deps/uv/include/uv/unix.h.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/include/uv/unix.h
@@ -59,6 +59,7 @@
 # include "uv/darwin.h"
 #elif defined(__DragonFly__)       || \
       defined(__FreeBSD__)         || \
+      defined(__QuinnBSD__)        || \
       defined(__FreeBSD_kernel__)  || \
       defined(__OpenBSD__)         || \
       defined(__NetBSD__)
