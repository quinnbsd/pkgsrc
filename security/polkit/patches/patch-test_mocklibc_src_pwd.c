$NetBSD$

--- test/mocklibc/src/pwd.c.orig	2020-08-26 09:27:17.000000000 +0000
+++ test/mocklibc/src/pwd.c
@@ -27,6 +27,12 @@
 
 static FILE *global_stream = NULL;
 
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+static struct passwd *fgetpwent(FILE* stream) {
+  return NULL;
+}
+#endif
+
 void setpwent(void) {
   if (global_stream)
     endpwent();
