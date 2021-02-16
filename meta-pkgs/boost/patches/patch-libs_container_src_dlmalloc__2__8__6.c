$NetBSD$

--- ./libs/container/src/dlmalloc_2_8_6.c.orig	2020-12-03 05:01:14.000000000 +0000
+++ ./libs/container/src/dlmalloc_2_8_6.c
@@ -1483,7 +1483,7 @@ DLMALLOC_EXPORT int mspace_mallopt(int,
 #ifndef LACKS_UNISTD_H
 #include <unistd.h>     /* for sbrk, sysconf */
 #else /* LACKS_UNISTD_H */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__QuinnBSD__)
 extern void*     sbrk(ptrdiff_t);
 #endif /* FreeBSD etc */
 #endif /* LACKS_UNISTD_H */
