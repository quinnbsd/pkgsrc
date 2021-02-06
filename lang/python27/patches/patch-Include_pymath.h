$NetBSD$

--- Include/pymath.h.orig	2020-04-19 21:13:39.000000000 +0000
+++ Include/pymath.h
@@ -203,7 +203,7 @@ PyAPI_FUNC(void) _Py_set_387controlword(
  * According to Tim's checkin, the FreeBSD systems use isinf() to work
  * around a FPE bug on that platform.
  */
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #define Py_OVERFLOWED(X) isinf(X)
 #else
 #define Py_OVERFLOWED(X) ((X) != 0.0 && (errno == ERANGE ||    \
