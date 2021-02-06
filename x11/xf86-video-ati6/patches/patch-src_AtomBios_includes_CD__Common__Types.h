$NetBSD$

--- src/AtomBios/includes/CD_Common_Types.h.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/AtomBios/includes/CD_Common_Types.h
@@ -53,7 +53,7 @@ Revision History:
 		typedef __int32             int32_t;
 #elif defined (__linux__) || defined (__NetBSD__) \
     || defined(__sun) || defined(__OpenBSD__) \
-    || defined (__FreeBSD__) || defined(__DragonFly__) || defined(__GLIBC__)
+    || defined (__FreeBSD__) || defined(__DragonFly__) || defined(__GLIBC__) || defined(__QuinnBSD__)
 		typedef unsigned int uint32_t;
 		typedef int int32_t;
 	#else
