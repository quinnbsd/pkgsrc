$NetBSD$

--- Source/cmAffinity.cxx.orig	2021-01-28 15:28:45.000000000 +0000
+++ Source/cmAffinity.cxx
@@ -8,13 +8,13 @@
 #  ifdef _WIN32
 #    define CM_HAVE_CPU_AFFINITY
 #    include <windows.h>
-#  elif defined(__linux__) || defined(__FreeBSD__)
+#  elif defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 #    define CM_HAVE_CPU_AFFINITY
 #    include <pthread.h>
 #    include <sched.h>
 // On some platforms CPU_ZERO needs memset but sched.h forgets string.h
 #    include <cstring> // IWYU pragma: keep
-#    if defined(__FreeBSD__)
+#    if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #      include <pthread_np.h>
 
 #      include <sys/cpuset.h>
