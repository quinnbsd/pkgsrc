$NetBSD$

--- src/lj_alloc.c.orig	2017-05-01 18:11:00.000000000 +0000
+++ src/lj_alloc.c
@@ -194,7 +194,7 @@ static LJ_AINLINE void *CALL_MMAP(size_t
   return ptr;
 }
 
-#elif LJ_TARGET_OSX || LJ_TARGET_PS4 || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__sun__) || LJ_TARGET_CYGWIN
+#elif LJ_TARGET_OSX || LJ_TARGET_PS4 || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__sun__) || LJ_TARGET_CYGWIN || defined(__QuinnBSD__)
 
 /* OSX and FreeBSD mmap() use a naive first-fit linear search.
 ** That's perfect for us. Except that -pagezero_size must be set for OSX,
@@ -210,7 +210,7 @@ static LJ_AINLINE void *CALL_MMAP(size_t
 #endif
 #define MMAP_REGION_END		((uintptr_t)0x80000000)
 
-#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !LJ_TARGET_PS4
+#if (defined(__FreeBSD__) || || defined(__QuinnBSD__) || defined(__FreeBSD_kernel__)) && !LJ_TARGET_PS4
 #include <sys/resource.h>
 #endif
 
@@ -220,7 +220,7 @@ static LJ_AINLINE void *CALL_MMAP(size_t
   /* Hint for next allocation. Doesn't need to be thread-safe. */
   static uintptr_t alloc_hint = MMAP_REGION_START;
   int retry = 0;
-#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !LJ_TARGET_PS4
+#if (defined(__FreeBSD__) || defined(__QuinnBSD__) || defined(__FreeBSD_kernel__)) && !LJ_TARGET_PS4
   static int rlimit_modified = 0;
   if (LJ_UNLIKELY(rlimit_modified == 0)) {
     struct rlimit rlim;
