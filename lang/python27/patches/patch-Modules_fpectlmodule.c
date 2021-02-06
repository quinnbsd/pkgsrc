$NetBSD$

--- Modules/fpectlmodule.c.orig	2020-04-19 21:13:39.000000000 +0000
+++ Modules/fpectlmodule.c
@@ -68,7 +68,7 @@ extern "C" {
 #include "Python.h"
 #include <signal.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #  include <ieeefp.h>
 #elif defined(__VMS)
 #define __NEW_STARLET
@@ -218,7 +218,7 @@ static void fpe_reset(Sigfunc *handler)
     PyOS_setsig(SIGFPE, handler);
 
 /*-- FreeBSD ----------------------------------------------------------------*/
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     fpresetsticky(fpgetsticky());
     fpsetmask(FP_X_INV | FP_X_DZ | FP_X_OFL);
     PyOS_setsig(SIGFPE, handler);
@@ -258,7 +258,7 @@ static void fpe_reset(Sigfunc *handler)
 
 static PyObject *turnoff_sigfpe(PyObject *self,PyObject *args)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
     fpresetsticky(fpgetsticky());
     fpsetmask(0);
 #elif defined(__VMS)
