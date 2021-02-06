$NetBSD$

--- hw/xfree86/os-support/bus/xf86Sbus.h.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/os-support/bus/xf86Sbus.h
@@ -36,10 +36,12 @@
 #elif defined(SVR4)
 #include <sys/fbio.h>
 #include <sys/openpromio.h>
+#elif defined(__NetBSD__) && defined(__sparc64__)
+#include <dev/sun/fbio.h>
 #elif defined(__OpenBSD__) && defined(__sparc64__)
 /* XXX */
 #elif defined(CSRG_BASED)
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/types.h>
 #include <sys/fbio.h>
 #include <dev/ofw/openpromio.h>
