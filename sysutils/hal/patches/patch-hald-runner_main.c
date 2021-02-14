$NetBSD$

--- ./hald-runner/main.c.orig	2008-08-10 13:50:10.000000000 +0000
+++ ./hald-runner/main.c
@@ -67,8 +67,10 @@ parse_environment(run_request *r, DBusMe
 		goto malformed;
 	dbus_message_iter_recurse(iter, &sub_iter);
 	/* Add default path for the programs we start */
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) 
 	tmpstr = g_strdup_printf("PATH=/sbin:/usr/sbin:/bin:/usr/bin:/usr/local/sbin:/usr/X11R6/sbin:/bin:/usr/bin:/usr/local/bin:/usr/X11R6/bin:%s", getenv("PATH"));
+#elif defined(__QuinnBSD__)
+	tmpstr = g_strdup_printf("PATH=/sbin:/usr/sbin:/bin:/usr/bin:/usr/pkg/sbin:/usr/pkg/bin:%s", getenv("PATH"));
 #else
 	tmpstr = g_strdup_printf("PATH=/sbin:/usr/sbin:/bin:/usr/bin:%s", getenv("PATH"));
 #endif
