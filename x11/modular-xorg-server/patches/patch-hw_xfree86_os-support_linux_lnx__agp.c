$NetBSD$

--- hw/xfree86/os-support/linux/lnx_agp.c.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/os-support/linux/lnx_agp.c
@@ -20,7 +20,7 @@
 #if defined(__linux__)
 #include <asm/ioctl.h>
 #include <linux/agpgart.h>
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <sys/ioctl.h>
 #include <sys/agpio.h>
 #endif
