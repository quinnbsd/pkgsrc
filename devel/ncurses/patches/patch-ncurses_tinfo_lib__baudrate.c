$NetBSD$

--- ncurses/tinfo/lib_baudrate.c.orig	2020-02-02 23:34:34.000000000 +0000
+++ ncurses/tinfo/lib_baudrate.c
@@ -40,7 +40,7 @@
 
 #include <curses.priv.h>
 #include <termcap.h>		/* ospeed */
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #include <sys/param.h>
 #endif
 
@@ -134,7 +134,7 @@ static struct speed const speeds[] =
     DATA(57600),
 #endif
     /* ifdef to prevent overflow when OLD_TTY is not available */
-#if !(NCURSES_OSPEED_COMPAT && defined(__FreeBSD__) && (__FreeBSD_version > 700000))
+#if !(NCURSES_OSPEED_COMPAT && (defined(__FreeBSD__) || defined(__QuinnBSD__)) && (__FreeBSD_version > 700000))
 #ifdef B76800
     DATA(76800),
 #endif
