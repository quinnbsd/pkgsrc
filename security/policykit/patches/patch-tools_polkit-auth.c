$NetBSD$

--- tools/polkit-auth.c.orig	2008-05-30 21:24:44.000000000 +0000
+++ tools/polkit-auth.c
@@ -37,7 +37,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
-#if defined(HAVE_SOLARIS) || defined(HAVE_FREEBSD)
+#if defined(HAVE_SOLARIS) || defined(HAVE_FREEBSD) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #include <sys/wait.h>
 #endif
 #include <pwd.h>
