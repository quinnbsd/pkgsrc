$NetBSD$

--- Modules/main.c.orig	2020-12-21 16:25:24.000000000 +0000
+++ Modules/main.c
@@ -6,7 +6,7 @@
 #include "pycore_pymem.h"
 #include "pycore_pystate.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #  include <fenv.h>     /* fedisableexcept() */
 #endif
 
@@ -48,7 +48,7 @@ pymain_init(const _PyArgv *args)
      * Python requires non-stop mode.  Alas, some platforms enable FP
      * exceptions by default.  Here we disable them.
      */
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
     fedisableexcept(FE_OVERFLOW);
 #endif
 
