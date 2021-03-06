$NetBSD$

--- Modules/nismodule.c.orig	2020-04-19 21:13:39.000000000 +0000
+++ Modules/nismodule.c
@@ -89,7 +89,7 @@ nis_mapname (char *map, int *pfix)
     return map;
 }
 
-#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 typedef int (*foreachfunc)(unsigned long, char *, int, char *, int, void *);
 #else
 typedef int (*foreachfunc)(int, char *, int, char *, int, char *);
