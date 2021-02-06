$NetBSD$

--- Modules/linuxaudiodev.c.orig	2020-04-19 21:13:39.000000000 +0000
+++ Modules/linuxaudiodev.c
@@ -32,7 +32,7 @@
 typedef unsigned long uint32_t;
 #endif
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <machine/soundcard.h>
 
 #ifndef SNDCTL_DSP_CHANNELS
