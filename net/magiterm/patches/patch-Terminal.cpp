$NetBSD$

--- Terminal.cpp.orig	2020-11-20 09:21:06.000000000 +0000
+++ Terminal.cpp
@@ -13,7 +13,7 @@
 #include <pty.h>
 #include <utmp.h>
 #else
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <termios.h>
