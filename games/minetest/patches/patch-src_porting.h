$NetBSD$

--- src/porting.h.orig	2021-02-23 18:50:37.000000000 +0000
+++ src/porting.h
@@ -94,7 +94,7 @@ with this program; if not, write to the
 	defined(__OpenBSD__) || defined(__DragonFly__) || \
 	defined(__APPLE__)   ||                           \
 	defined(__sun)       || defined(sun)           || \
-	defined(__QNX__)     || defined(__QNXNTO__)
+	defined(__QNX__)     || defined(__QNXNTO__) || defined(__QuinnBSD__)
 	#define HAVE_STRLCPY
 #endif
 
@@ -289,7 +289,7 @@ inline const char *getPlatformName()
 #elif defined(_WIN32) || defined(_WIN64)
 	"Windows"
 #elif defined(__DragonFly__) || defined(__FreeBSD__) || \
-		defined(__NetBSD__) || defined(__OpenBSD__)
+		defined(__NetBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 	"BSD"
 #elif defined(__APPLE__) && defined(__MACH__)
 	#if TARGET_OS_MAC
