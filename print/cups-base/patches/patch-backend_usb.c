$NetBSD$

--- backend/usb.c.orig	2020-11-27 14:25:26.000000000 +0000
+++ backend/usb.c
@@ -46,7 +46,7 @@ int	print_device(const char *uri, const
 #  include "usb-libusb.c"
 #elif defined(__APPLE__)
 #  include "usb-darwin.c"
-#elif defined(__linux) || defined(__sun) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#elif defined(__linux) || defined(__sun) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #  include "usb-unix.c"
 #else
 /*
