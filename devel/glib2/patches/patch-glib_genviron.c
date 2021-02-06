$NetBSD$

--- glib/genviron.c.orig	2020-12-17 11:47:11.459608300 +0000
+++ glib/genviron.c
@@ -329,8 +329,12 @@ g_setenv (const gchar *variable,
 /* According to the Single Unix Specification, environ is not
  * in any system header, although unistd.h often declares it.
  */
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
 #endif
+#endif
 
 /**
  * g_unsetenv:
