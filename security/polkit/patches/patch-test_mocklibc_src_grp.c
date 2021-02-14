$NetBSD$

--- test/mocklibc/src/grp.c.orig	2020-08-26 09:27:17.000000000 +0000
+++ test/mocklibc/src/grp.c
@@ -27,6 +27,13 @@
 
 static FILE *global_stream = NULL;
 
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+static struct group *fgetgrent(FILE *stream) {
+  return NULL;
+}
+#endif
+
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 void setgrent(void) {
   if (global_stream)
     endgrent();
@@ -37,6 +44,7 @@ void setgrent(void) {
 
   global_stream = fopen(path, "r");
 }
+#endif
 
 struct group *getgrent(void) {
   if (!global_stream)
