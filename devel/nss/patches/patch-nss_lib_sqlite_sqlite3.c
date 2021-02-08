$NetBSD$

--- nss/lib/sqlite/sqlite3.c.orig	2021-01-22 17:08:28.000000000 +0000
+++ nss/lib/sqlite/sqlite3.c
@@ -14081,7 +14081,8 @@ typedef INT16_TYPE LogEst;
   || (defined(__APPLE__) && defined(__MACH__)) \
   || defined(__sun) \
   || defined(__FreeBSD__) \
-  || defined(__DragonFly__)
+  || defined(__DragonFly__) \
+  || defined(__QuinnBSD__)
 #   define SQLITE_MAX_MMAP_SIZE 0x7fff0000  /* 2147418112 */
 # else
 #   define SQLITE_MAX_MMAP_SIZE 0
