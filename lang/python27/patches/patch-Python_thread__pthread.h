$NetBSD$

--- Python/thread_pthread.h.orig	2020-04-19 21:13:39.000000000 +0000
+++ Python/thread_pthread.h
@@ -19,7 +19,7 @@
 #define THREAD_STACK_SIZE       0       /* use default stack size */
 #endif
 
-#if (defined(__APPLE__) || defined(__FreeBSD__)) && defined(THREAD_STACK_SIZE) && THREAD_STACK_SIZE == 0
+#if (defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(THREAD_STACK_SIZE) && THREAD_STACK_SIZE == 0
    /* The default stack size for new threads on OSX is small enough that
     * we'll get hard crashes instead of 'maximum recursion depth exceeded'
     * exceptions.
@@ -46,6 +46,9 @@
    we need to add 0 to make it work there as well. */
 #if (_POSIX_SEMAPHORES+0) == -1
 #define HAVE_BROKEN_POSIX_SEMAPHORES
+#elif defined(__NetBSD__)
+/* XXX accesses to closed file descriptors, needs debugging */
+#define HAVE_BROKEN_POSIX_SEMAPHORES
 #else
 #include <semaphore.h>
 #include <errno.h>
