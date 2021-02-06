$NetBSD$

--- hw/xfree86/os-support/bsd/bsd_init.c.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/os-support/bsd/bsd_init.c
@@ -158,17 +158,19 @@ xf86OpenConsole()
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
     int result;
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
     struct utsname uts;
 #endif
     vtmode_t vtmode;
 #endif
 
     if (serverGeneration == 1) {
+#if 0
         /* check if we are run with euid==0 */
         if (geteuid() != 0) {
             FatalError("xf86OpenConsole: Server must be suid root");
         }
+#endif
 
         if (!KeepTty) {
             /*
@@ -229,7 +231,7 @@ xf86OpenConsole()
              * switching anymore. Here we check for FreeBSD 3.1 and up.
              * Add cases for other *BSD that behave the same.
              */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
             uname(&uts);
             i = atof(uts.release) * 100;
             if (i >= 310)
