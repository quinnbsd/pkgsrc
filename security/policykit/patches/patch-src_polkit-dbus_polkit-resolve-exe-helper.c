$NetBSD$

--- src/polkit-dbus/polkit-resolve-exe-helper.c.orig	2008-05-30 21:24:44.000000000 +0000
+++ src/polkit-dbus/polkit-resolve-exe-helper.c
@@ -40,7 +40,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#ifdef HAVE_FREEBSD
+#if defined(HAVE_FREEBSD) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #include <sys/param.h>
 #endif
 #include <security/pam_appl.h>
