$NetBSD$

--- Modules/python.c.orig	2020-04-19 21:13:39.000000000 +0000
+++ Modules/python.c
@@ -2,7 +2,7 @@
 
 #include "Python.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <fenv.h>
 #endif
 
@@ -14,7 +14,7 @@ main(int argc, char **argv)
 	 * Python requires non-stop mode.  Alas, some platforms enable FP
 	 * exceptions by default.  Here we disable them.
 	 */
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 	fedisableexcept(FE_OVERFLOW);
 #endif
 	return Py_Main(argc, argv);
