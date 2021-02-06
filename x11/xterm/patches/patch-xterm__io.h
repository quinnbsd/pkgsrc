$NetBSD$

--- xterm_io.h.orig	2020-01-18 18:48:19.000000000 +0000
+++ xterm_io.h
@@ -57,7 +57,7 @@
 #define USE_SYSV_TERMIO
 #endif
 
-#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__INTERIX) || defined(__APPLE__) || defined(__UNIXWARE__) || defined(__hpux)
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__INTERIX) || defined(__APPLE__) || defined(__UNIXWARE__) || defined(__hpux) || defined(__QuinnBSD__)
 #ifndef USE_POSIX_TERMIOS
 #define USE_POSIX_TERMIOS
 #endif
