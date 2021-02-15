$NetBSD$

--- src/plugins/pgpcore/pgp_viewer.c.orig	2020-10-19 10:37:56.000000000 +0000
+++ src/plugins/pgpcore/pgp_viewer.c
@@ -33,7 +33,7 @@
 #  include <pthread.h>
 #  include <windows.h>
 #endif
-#if (defined(__DragonFly__) || defined(SOLARIS) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__OpenBSD__))
+#if (defined(__DragonFly__) || defined(SOLARIS) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__QuinnBSD__))
 #  include <sys/signal.h>
 #endif
 
