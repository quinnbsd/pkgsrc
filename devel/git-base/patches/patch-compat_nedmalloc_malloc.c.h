$NetBSD$

--- compat/nedmalloc/malloc.c.h.orig	2020-12-28 03:26:32.000000000 +0000
+++ compat/nedmalloc/malloc.c.h
@@ -1326,7 +1326,7 @@ int mspace_mallopt(int, int);
 #ifndef LACKS_UNISTD_H
 #include <unistd.h>     /* for sbrk, sysconf */
 #else /* LACKS_UNISTD_H */
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__QuinnBSD__)
 extern void*     sbrk(ptrdiff_t);
 #endif /* FreeBSD etc */
 #endif /* LACKS_UNISTD_H */
@@ -1740,7 +1740,7 @@ static FORCEINLINE int pthread_acquire_l
 #if defined (__SVR4) && defined (__sun) /* solaris */
 	thr_yield();
 #else
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
 	sched_yield();
 #else  /* no-op yield on unknown systems */
 	;
