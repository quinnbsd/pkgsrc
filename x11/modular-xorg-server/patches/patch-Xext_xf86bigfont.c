$NetBSD$

--- Xext/xf86bigfont.c.orig	2020-12-01 16:32:25.000000000 +0000
+++ Xext/xf86bigfont.c
@@ -87,7 +87,7 @@ static unsigned int pagesize;
 
 static Bool badSysCall = FALSE;
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 static void
 SigSysHandler(int signo)
