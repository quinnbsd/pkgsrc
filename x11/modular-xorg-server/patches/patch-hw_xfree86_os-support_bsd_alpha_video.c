$NetBSD$

--- hw/xfree86/os-support/bsd/alpha_video.c.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/os-support/bsd/alpha_video.c
@@ -173,7 +173,7 @@ xf86OSInitVidMem(VidMemInfoPtr pVidMem)
     pVidMem->initialised = TRUE;
 }
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 
 extern int ioperm(unsigned long from, unsigned long num, int on);
 
