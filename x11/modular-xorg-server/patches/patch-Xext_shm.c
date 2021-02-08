$NetBSD$

--- Xext/shm.c.orig	2020-12-01 16:32:25.000000000 +0000
+++ Xext/shm.c
@@ -155,7 +155,7 @@ static ShmFuncs fbFuncs = { fbShmCreateP
     } \
 }
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 static Bool badSysCall = FALSE;
 
