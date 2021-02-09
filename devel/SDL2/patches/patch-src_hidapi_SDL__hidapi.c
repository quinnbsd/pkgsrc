$NetBSD$

--- src/hidapi/SDL_hidapi.c.orig	2020-12-21 17:44:36.000000000 +0000
+++ src/hidapi/SDL_hidapi.c
@@ -303,7 +303,7 @@ static struct
 #define make_path                       LIBUSB_make_path
 #define read_thread                     LIBUSB_read_thread
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 /* this is awkwardly inlined, so we need to re-implement it here
  * so we can override the libusb_control_transfer call */
 static int
