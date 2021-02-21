$NetBSD$

--- src/stdlib/SDL_malloc.c.orig	2012-01-19 06:30:06.000000000 +0000
+++ src/stdlib/SDL_malloc.c
@@ -1230,7 +1230,7 @@ int mspace_mallopt(int, int);
 #ifndef LACKS_UNISTD_H
 #include <unistd.h>     /* for sbrk */
 #else /* LACKS_UNISTD_H */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__QuinnBSD__)
 extern void*     sbrk(ptrdiff_t);
 #endif /* FreeBSD etc */
 #endif /* LACKS_UNISTD_H */
