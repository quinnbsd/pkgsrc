$NetBSD$

--- cfg.cpp.orig	2020-09-15 04:00:52.000000000 +0000
+++ cfg.cpp
@@ -29,19 +29,19 @@ Cfg::Cfg()
 	: currentSession(-1)
 {
 	/* Configuration options */
-	options.insert(option("default_path","/bin:/usr/bin:/usr/local/bin"));
-	options.insert(option("default_xserver","/usr/bin/X"));
+	options.insert(option("default_path","/bin:/usr/bin:/usr/pkg/bin"));
+	options.insert(option("default_xserver","/usr/pkg/bin/X"));
 	options.insert(option("xserver_arguments",""));
 	options.insert(option("numlock",""));
 	options.insert(option("daemon",""));
-	options.insert(option("xauth_path","/usr/bin/xauth"));
-	options.insert(option("login_cmd","exec /bin/bash -login ~/.xinitrc %session"));
+	options.insert(option("xauth_path","/usr/pkg/bin/xauth"));
+	options.insert(option("login_cmd","exec /usr/pkg/bin/bash -login ~/.xinitrc %session"));
 	options.insert(option("halt_cmd","/sbin/shutdown -h now"));
 	options.insert(option("reboot_cmd","/sbin/shutdown -r now"));
 	options.insert(option("suspend_cmd",""));
 	options.insert(option("sessionstart_cmd",""));
 	options.insert(option("sessionstop_cmd",""));
-	options.insert(option("console_cmd","/usr/bin/xterm -C -fg white -bg black +sb -g %dx%d+%d+%d -fn %dx%d -T ""Console login"" -e /bin/sh -c ""/bin/cat /etc/issue; exec /bin/login"""));
+	options.insert(option("console_cmd","/usr/pkg/bin/xterm -C -fg white -bg black +sb -g %dx%d+%d+%d -fn %dx%d -T ""Console login"" -e /bin/sh -c ""/bin/cat /etc/issue; exec /bin/login"""));
 	options.insert(option("screenshot_cmd","import -window root /mlogind.png"));
 	options.insert(option("welcome_msg","Welcome to %host"));
 	options.insert(option("session_msg","Session:"));
