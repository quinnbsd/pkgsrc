$NetBSD$

--- Include/pyport.h.orig	2020-12-21 16:25:24.000000000 +0000
+++ Include/pyport.h
@@ -331,7 +331,7 @@ extern "C" {
  *    This isn't reliable.  See Py_OVERFLOWED comments.
  *    X is evaluated more than once.
  */
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || (defined(__hpux) && defined(__ia64))
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__) || (defined(__hpux) && defined(__ia64))
 #define _Py_SET_EDOM_FOR_NAN(X) if (isnan(X)) errno = EDOM;
 #else
 #define _Py_SET_EDOM_FOR_NAN(X) ;
