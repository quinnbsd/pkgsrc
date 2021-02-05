$NetBSD$

--- Utilities/cmcurl/include/curl/curl.h.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmcurl/include/curl/curl.h
@@ -49,7 +49,7 @@
 #include <stdio.h>
 #include <limits.h>
 
-#if defined(__FreeBSD__) && (__FreeBSD__ >= 2)
+#if (defined(__FreeBSD__) && (__FreeBSD__ >= 2)) || defined(__QuinnBSD__)
 /* Needed for __FreeBSD_version symbol definition */
 #include <osreldate.h>
 #endif
