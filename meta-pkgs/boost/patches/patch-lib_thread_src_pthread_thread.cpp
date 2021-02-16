$NetBSD$

--- ./libs/thread/src/pthread/thread.cpp.orig	2020-12-03 05:02:33.000000000 +0000
+++ ./libs/thread/src/pthread/thread.cpp
@@ -22,7 +22,7 @@
 
 #ifdef __GLIBC__
 #include <sys/sysinfo.h>
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #elif defined BOOST_HAS_UNISTD_H
@@ -488,7 +488,7 @@ namespace boost
     {
 #if defined(PTW32_VERSION) || defined(__hpux)
         return pthread_num_processors_np();
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
         int count;
         size_t size=sizeof(count);
         return sysctlbyname("hw.ncpu",&count,&size,NULL,0)?0:count;
