$NetBSD$

--- Python/thread_pthread.h.orig	2020-12-21 16:25:24.000000000 +0000
+++ Python/thread_pthread.h
@@ -14,7 +14,7 @@
 
 #if defined(__linux__)
 #   include <sys/syscall.h>     /* syscall(SYS_gettid) */
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #   include <pthread_np.h>      /* pthread_getthreadid_np() */
 #elif defined(__OpenBSD__)
 #   include <unistd.h>          /* getthrid() */
@@ -43,7 +43,7 @@
 /* Note: This matches the value of -Wl,-stack_size in configure.ac */
 #define THREAD_STACK_SIZE       0x1000000
 #endif
-#if defined(__FreeBSD__) && defined(THREAD_STACK_SIZE) && THREAD_STACK_SIZE == 0
+#if (defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(THREAD_STACK_SIZE) && THREAD_STACK_SIZE == 0
 #undef  THREAD_STACK_SIZE
 #define THREAD_STACK_SIZE       0x400000
 #endif
@@ -67,6 +67,9 @@
    we need to add 0 to make it work there as well. */
 #if (_POSIX_SEMAPHORES+0) == -1
 #define HAVE_BROKEN_POSIX_SEMAPHORES
+#elif defined(__NetBSD__)
+/* XXX accesses to closed file descriptors, needs debugging */
+#define HAVE_BROKEN_POSIX_SEMAPHORES
 #else
 #include <semaphore.h>
 #include <errno.h>
@@ -331,7 +334,7 @@ PyThread_get_thread_native_id(void)
 #elif defined(__linux__)
     pid_t native_id;
     native_id = syscall(SYS_gettid);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     int native_id;
     native_id = pthread_getthreadid_np();
 #elif defined(__OpenBSD__)
