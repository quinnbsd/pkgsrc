$NetBSD$

--- src/dlmalloc.c.orig	2019-10-31 14:49:54.000000000 +0000
+++ src/dlmalloc.c
@@ -1200,7 +1200,7 @@ int mspace_mallopt(int, int);
 #ifndef LACKS_UNISTD_H
 #include <unistd.h>     /* for sbrk */
 #else /* LACKS_UNISTD_H */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__QuinnBSD__)
 extern void*     sbrk(ptrdiff_t);
 #endif /* FreeBSD etc */
 #endif /* LACKS_UNISTD_H */
