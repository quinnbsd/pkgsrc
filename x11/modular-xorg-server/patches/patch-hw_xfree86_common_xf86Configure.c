$NetBSD$

--- hw/xfree86/common/xf86Configure.c.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/common/xf86Configure.c
@@ -58,7 +58,7 @@ xf86MonPtr ConfiguredMonitor;
 Bool xf86DoConfigurePass1 = TRUE;
 static Bool foundMouse = FALSE;
 
-#if   defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if   defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 static const char *DFLT_MOUSE_DEV = "/dev/sysmouse";
 static const char *DFLT_MOUSE_PROTO = "auto";
 #elif defined(__linux__)
