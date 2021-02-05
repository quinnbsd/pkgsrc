$NetBSD$

--- m4/ax_pthread.m4.orig	2020-09-25 00:34:43.000000000 +0000
+++ m4/ax_pthread.m4
@@ -152,7 +152,7 @@ ax_pthread_flags="pthreads none -Kthread
 
 case $host_os in
 
-        freebsd*)
+        freebsd* | quinnbsd*)
 
         # -kthread: FreeBSD kernel threads (preferred to -pthread since SMP-able)
         # lthread: LinuxThreads port on FreeBSD (also preferred to -pthread)
