$NetBSD$

--- Include/pyport.h.orig	2020-04-19 21:13:39.000000000 +0000
+++ Include/pyport.h
@@ -467,7 +467,7 @@ extern "C" {
  *    This isn't reliable.  See Py_OVERFLOWED comments.
  *    X is evaluated more than once.
  */
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || (defined(__hpux) && defined(__ia64))
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__) || (defined(__hpux) && defined(__ia64))
 #define _Py_SET_EDOM_FOR_NAN(X) if (isnan(X)) errno = EDOM;
 #else
 #define _Py_SET_EDOM_FOR_NAN(X) ;
@@ -640,11 +640,6 @@ Please be conservative with adding new o
 in platform-specific #ifdefs.
 **************************************************************************/
 
-#ifdef SOLARIS
-/* Unchecked */
-extern int gethostname(char *, int);
-#endif
-
 #ifdef __BEOS__
 /* Unchecked */
 /* It's in the libs, but not the headers... - [cjh] */
