$NetBSD$

--- xdm/session.c.orig	2019-03-02 22:06:13.000000000 +0000
+++ xdm/session.c
@@ -87,6 +87,11 @@ extern int key_setnet(struct key_netstar
 #include <systemd/sd-daemon.h>
 #endif
 
+#ifdef __QuinnBSD__
+#include <sys/types.h>
+#include <login_cap.h>
+#endif
+
 #ifdef USE_SELINUX
 /* This should be run just before we exec the user session. */
 static int
