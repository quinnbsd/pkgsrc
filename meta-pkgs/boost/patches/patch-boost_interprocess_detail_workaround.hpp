$NetBSD$

--- ./boost/interprocess/detail/workaround.hpp.orig	2020-12-03 05:01:42.000000000 +0000
+++ ./boost/interprocess/detail/workaround.hpp
@@ -77,7 +77,7 @@
          #define BOOST_INTERPROCESS_FILESYSTEM_BASED_POSIX_SHARED_MEMORY
       //Some systems have "jailed" environments where shm usage is restricted at runtime
       //and temporary file based shm is possible in those executions.
-      #elif defined(__FreeBSD__)
+      #elif defined(__FreeBSD__) || defined(__QuinnBSD__)
          #define BOOST_INTERPROCESS_RUNTIME_FILESYSTEM_BASED_POSIX_SHARED_MEMORY
       #endif
    #endif
@@ -94,7 +94,7 @@
    //////////////////////////////////////////////////////
    #if ( defined(_POSIX_SEMAPHORES) && ((_POSIX_SEMAPHORES + 0) > 0) ) ||\
        ( defined(__FreeBSD__) && (__FreeBSD__ >= 4)) || \
-         defined(__APPLE__)
+         defined(__APPLE__) || defined(__QuinnBSD__)
       #define BOOST_INTERPROCESS_POSIX_NAMED_SEMAPHORES
       //MacOsX declares _POSIX_SEMAPHORES but sem_init returns ENOSYS
       #if !defined(__APPLE__)
@@ -122,7 +122,7 @@
    //////////////////////////////////////////////////////
    // Detect BSD derivatives to detect sysctl
    //////////////////////////////////////////////////////
-   #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+   #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
       #define BOOST_INTERPROCESS_BSD_DERIVATIVE
       //Some *BSD systems (OpenBSD & NetBSD) need sys/param.h before sys/sysctl.h, whereas
       //others (FreeBSD & Darwin) need sys/types.h
