$NetBSD$

--- nspr/pr/include/md/_pth.h.orig	2020-09-17 15:01:34.000000000 +0000
+++ nspr/pr/include/md/_pth.h
@@ -86,10 +86,10 @@
  */
 #if defined(AIX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-    || defined(HPUX) || defined(FREEBSD) \
+    || defined(HPUX) || defined(FREEBSD) || defined(__DragonFly__) \
     || defined(NETBSD) || defined(OPENBSD) || defined(BSDI) \
     || defined(NTO) || defined(DARWIN) \
-    || defined(UNIXWARE) || defined(RISCOS)
+    || defined(UNIXWARE) || defined(RISCOS) || defined(__QuinnBSD__)
 #define _PT_PTHREAD_INVALIDATE_THR_HANDLE(t)  (t) = 0
 #define _PT_PTHREAD_THR_HANDLE_IS_INVALID(t)  (t) == 0
 #define _PT_PTHREAD_COPY_THR_HANDLE(st, dt)   (dt) = (st)
@@ -115,8 +115,8 @@
 #if (defined(AIX) && !defined(AIX4_3_PLUS)) \
     || defined(LINUX) || defined(__GNU__)|| defined(__GLIBC__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
-    || defined(BSDI) || defined(UNIXWARE) \
-    || defined(DARWIN)
+    || defined(BSDI) || defined(UNIXWARE) || defined(__DragonFly__) \
+    || defined(DARWIN) || defined(__QuinnBSD__)
 #define PT_NO_SIGTIMEDWAIT
 #endif
 
@@ -133,7 +133,7 @@
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-    || defined(FREEBSD)
+    || defined(FREEBSD) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(NTO)
@@ -177,7 +177,7 @@ extern int (*_PT_aix_yield_fcn)();
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(BSDI) || defined(NTO) || defined(DARWIN) \
-    || defined(UNIXWARE) || defined(RISCOS)
+    || defined(UNIXWARE) || defined(RISCOS) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #define _PT_PTHREAD_YIELD()             sched_yield()
 #else
 #error "Need to define _PT_PTHREAD_YIELD for this platform"
