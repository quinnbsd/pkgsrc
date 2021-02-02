$NetBSD$

--- Modules/nismodule.c.orig	2020-12-21 16:25:24.000000000 +0000
+++ Modules/nismodule.c
@@ -85,7 +85,7 @@ nis_mapname (char *map, int *pfix)
     return map;
 }
 
-#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 typedef int (*foreachfunc)(unsigned long, char *, int, char *, int, void *);
 #else
 typedef int (*foreachfunc)(int, char *, int, char *, int, char *);
