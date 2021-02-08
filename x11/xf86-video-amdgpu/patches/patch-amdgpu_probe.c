$NetBSD$

--- src/amdgpu_probe.c.orig	2019-10-11 15:20:30.000000000 +0000
+++ src/amdgpu_probe.c
@@ -50,7 +50,7 @@
 #include "xf86drmMode.h"
 #include "dri.h"
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #include <xf86_OSproc.h>
 #endif
 
@@ -93,7 +93,7 @@ static Bool amdgpu_kernel_mode_enabled(S
 {
 	int ret = drmCheckModesettingSupported(busIdString);
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 	if (ret) {
 		if (xf86LoadKernelModule("amdgpukms"))
 			ret = drmCheckModesettingSupported(busIdString);
