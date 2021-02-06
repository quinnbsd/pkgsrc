$NetBSD$

--- pkgs/sqlite3.34.0/compat/sqlite3/sqlite3.c.orig	2020-12-21 21:29:30.000000000 +0000
+++ pkgs/sqlite3.34.0/compat/sqlite3/sqlite3.c
@@ -14603,7 +14603,8 @@ typedef INT16_TYPE LogEst;
   || (defined(__APPLE__) && defined(__MACH__)) \
   || defined(__sun) \
   || defined(__FreeBSD__) \
-  || defined(__DragonFly__)
+  || defined(__DragonFly__) \
+  || defined(__QuinnBSD__)
 #   define SQLITE_MAX_MMAP_SIZE 0x7fff0000  /* 2147418112 */
 # else
 #   define SQLITE_MAX_MMAP_SIZE 0
