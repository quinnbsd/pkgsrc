$NetBSD$

--- src/util/u_process.c.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/util/u_process.c
@@ -92,7 +92,7 @@ __getProgramName()
 #    if defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 106000100)
 #        define GET_PROGRAM_NAME() getprogname()
 #    endif
-#elif defined(__DragonFly__)
+#elif defined(__DragonFly__) || defined(__QuinnBSD__)
 #    define GET_PROGRAM_NAME() getprogname()
 #elif defined(__APPLE__)
 #    define GET_PROGRAM_NAME() getprogname()
