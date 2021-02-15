$NetBSD$

--- src/etpan/nntp-thread.c.orig	2020-10-19 10:37:56.000000000 +0000
+++ src/etpan/nntp-thread.c
@@ -29,7 +29,7 @@
 #include "news.h"
 #include <sys/types.h>
 #include <sys/stat.h>
-#if (defined(__DragonFly__) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__CYGWIN__))
+#if (defined(__DragonFly__) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__CYGWIN__) || defined(__QuinnBSD__))
 #include <sys/socket.h>
 #endif
 #include <fcntl.h>
@@ -241,7 +241,7 @@ void nntp_main_done(gboolean have_connec
 {
 	nntp_disconnect_all(have_connectivity);
 	etpan_thread_manager_stop(thread_manager);
-#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 	return;
 #endif
 	etpan_thread_manager_join(thread_manager);
