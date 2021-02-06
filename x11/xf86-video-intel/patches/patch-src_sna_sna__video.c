$NetBSD$

--- src/sna/sna_video.c.orig	2020-05-15 16:56:58.000000000 +0000
+++ src/sna/sna_video.c
@@ -59,7 +59,7 @@
 #include "intel_options.h"
 
 #include <xf86xv.h>
-#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 #include <sys/types.h>
 #include <sys/endian.h>
 #ifdef __OpenBSD__
@@ -67,6 +67,9 @@
 #else
 #define bswap_32 bswap32
 #endif
+#elif defined(__sun)
+#include <sys/byteorder.h>
+#define bswap_32 BSWAP_32
 #else
 #include <byteswap.h>
 #endif
