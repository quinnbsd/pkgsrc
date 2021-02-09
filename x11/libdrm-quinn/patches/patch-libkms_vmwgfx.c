$NetBSD$

--- libkms/vmwgfx.c.orig	2021-01-11 18:15:27.378030300 +0000
+++ libkms/vmwgfx.c
@@ -25,7 +25,9 @@
  *
  **************************************************************************/
 
-
+#if defined(__QuinnBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#define _WANT_KERNEL_ERRNO
+#endif
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
