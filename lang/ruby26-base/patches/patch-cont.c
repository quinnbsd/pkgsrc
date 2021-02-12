$NetBSD$

--- ./cont.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./cont.c
@@ -868,7 +868,7 @@ fiber_entry(void *arg)
  * if MAP_STACK is passed.
  * http://www.FreeBSD.org/cgi/query-pr.cgi?pr=158755
  */
-#if defined(MAP_STACK) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__)
+#if defined(MAP_STACK) && !defined(__FreeBSD__) && !defined(__FreeBSD_kernel__) && !defined(__QuinnBSD__)
 #define FIBER_STACK_FLAGS (MAP_PRIVATE | MAP_ANON | MAP_STACK)
 #else
 #define FIBER_STACK_FLAGS (MAP_PRIVATE | MAP_ANON)
