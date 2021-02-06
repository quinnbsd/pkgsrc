$NetBSD$

--- backend/usb-unix.c.orig	2020-11-27 14:25:26.000000000 +0000
+++ backend/usb-unix.c
@@ -57,7 +57,7 @@ print_device(const char *uri,		/* I - De
 
   do
   {
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
    /*
     * *BSD's ulpt driver currently does not support the
     * back-channel, incorrectly returns data ready on a select(),
@@ -271,7 +271,7 @@ list_devices(void)
       close(fd);
     }
   }
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
   int   i;                      /* Looping var */
   char  device[255];            /* Device filename */
 
