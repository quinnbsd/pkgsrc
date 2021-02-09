$NetBSD$

--- ncurses/base/lib_mouse.c.orig	2020-02-02 23:34:34.000000000 +0000
+++ ncurses/base/lib_mouse.c
@@ -113,7 +113,7 @@ make an error
 #undef buttons			/* symbol conflict in consio.h */
 #undef mouse_info		/* symbol conflict in consio.h */
 #include <osreldate.h>
-#if defined(__DragonFly_version) || (defined(__FreeBSD__) && (__FreeBSD_version >= 400017))
+#if defined(__DragonFly_version) || ((defined(__FreeBSD__) || defined(__QuinnBSD__)) && (__FreeBSD_version >= 400017))
 #include <sys/consio.h>
 #include <sys/fbio.h>
 #else
