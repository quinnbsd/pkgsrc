$NetBSD$

--- src/chartype.h.orig	2019-10-25 20:12:05.000000000 +0000
+++ src/chartype.h
@@ -38,6 +38,7 @@
 	!(defined(__APPLE__) && defined(__MACH__)) && \
 	!defined(__OpenBSD__) && \
 	!defined(__FreeBSD__) && \
+	!defined(__QuinnBSD__) && \
 	!defined(__DragonFly__)
 #ifndef __STDC_ISO_10646__
 /* In many places it is assumed that the first 127 code points are ASCII
