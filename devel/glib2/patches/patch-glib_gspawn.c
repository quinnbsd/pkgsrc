$NetBSD$

--- glib/gspawn.c.orig	2020-12-17 11:47:11.474608400 +0000
+++ glib/gspawn.c
@@ -86,8 +86,12 @@
 #ifdef HAVE__NSGETENVIRON
 #define environ (*_NSGetEnviron())
 #else
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
+extern __attribute__((__weak__)) char **environ;
+#else
 extern char **environ;
 #endif
+#endif
 
 #ifndef O_CLOEXEC
 #define O_CLOEXEC 0
@@ -1273,7 +1277,7 @@ safe_fdwalk (int (*cb)(void *data, int f
   if (getrlimit (RLIMIT_NOFILE, &rl) == 0 && rl.rlim_max != RLIM_INFINITY)
     open_max = rl.rlim_max;
 #endif
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
   /* Use sysconf() function provided by the system if it is known to be
    * async-signal safe.
    *
@@ -1303,7 +1307,7 @@ safe_fdwalk (int (*cb)(void *data, int f
 static void
 safe_closefrom (int lowfd)
 {
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
   /* Use closefrom function provided by the system if it is known to be
    * async-signal safe.
    *
