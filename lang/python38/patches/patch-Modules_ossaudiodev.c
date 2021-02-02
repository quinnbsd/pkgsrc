$NetBSD$

--- Modules/ossaudiodev.c.orig	2020-12-21 16:25:24.000000000 +0000
+++ Modules/ossaudiodev.c
@@ -43,7 +43,7 @@
 typedef unsigned long uint32_t;
 #endif
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 
 # ifndef SNDCTL_DSP_CHANNELS
 #  define SNDCTL_DSP_CHANNELS SOUND_PCM_WRITE_CHANNELS
