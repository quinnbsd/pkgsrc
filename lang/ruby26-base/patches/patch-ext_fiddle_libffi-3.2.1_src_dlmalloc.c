$NetBSD$

--- ./ext/fiddle/libffi-3.2.1/src/dlmalloc.c.orig	2014-11-08 12:47:24.000000000 +0000
+++ ./ext/fiddle/libffi-3.2.1/src/dlmalloc.c
@@ -1195,7 +1195,7 @@ int mspace_mallopt(int, int);
 #ifndef LACKS_UNISTD_H
 #include <unistd.h>     /* for sbrk */
 #else /* LACKS_UNISTD_H */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__QuinnBSD__)
 extern void*     sbrk(ptrdiff_t);
 #endif /* FreeBSD etc */
 #endif /* LACKS_UNISTD_H */
