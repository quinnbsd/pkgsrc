$NetBSD$

--- hw/xfree86/os-support/xf86_OSlib.h.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/os-support/xf86_OSlib.h
@@ -231,7 +231,7 @@ extern _X_HIDDEN char xf86SolarisFbDev[P
 /* Kernel of *BSD                                                         */
 /**************************************************************************/
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
- defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+ defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 #include <sys/param.h>
 #if defined(__FreeBSD_version) && !defined(__FreeBSD_kernel_version)
@@ -240,8 +240,8 @@ extern _X_HIDDEN char xf86SolarisFbDev[P
 
 #ifdef SYSCONS_SUPPORT
 #define COMPAT_SYSCONS
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
-#if defined(__DragonFly__)  || (__FreeBSD_kernel_version >= 410000)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+#if defined(__DragonFly__)  || (__FreeBSD_kernel_version >= 410000) || defined(__QuinnBSD__)
 #include <sys/consio.h>
 #include <sys/kbio.h>
 #else
@@ -254,7 +254,7 @@ extern _X_HIDDEN char xf86SolarisFbDev[P
 #if defined(PCVT_SUPPORT) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 #if !defined(SYSCONS_SUPPORT)
       /* no syscons, so include pcvt specific header file */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #include <machine/pcvt_ioctl.h>
 #else
 #include <sys/pcvt_ioctl.h>
@@ -271,7 +271,7 @@ struct pcvtid {
 #include <dev/wscons/wsconsio.h>
 #include <dev/wscons/wsdisplay_usl_io.h>
 #endif                          /* WSCONS_SUPPORT */
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <sys/mouse.h>
 #endif
     /* Include these definitions in case ioctl_pc.h didn't get included */
