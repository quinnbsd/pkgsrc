$NetBSD$

--- main.c.orig	2020-10-12 18:37:02.000000000 +0000
+++ main.c
@@ -383,7 +383,7 @@ extern struct utmp *getutid __((struct u
 #include <util.h>		/* openpty() */
 #endif
 
-#if defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <libutil.h>		/* openpty() */
 #endif
 
@@ -2872,7 +2872,7 @@ main(int argc, char *argv[]ENVP_ARG)
     }
 }
 
-#if defined(__osf__) || (defined(__GLIBC__) && !defined(USE_USG_PTYS)) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__osf__) || (defined(__GLIBC__) && !defined(USE_USG_PTYS)) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
 #define USE_OPENPTY 1
 static int opened_tty = -1;
 #endif
