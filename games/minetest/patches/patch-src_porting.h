$NetBSD$

--- src/porting.h.orig	2020-07-09 20:04:20.000000000 +0000
+++ src/porting.h
@@ -92,7 +92,7 @@ with this program; if not, write to the
 // too small.
 #if defined(__FreeBSD__) || defined(__NetBSD__)    || \
 	defined(__OpenBSD__) || defined(__DragonFly__) || \
-	defined(__APPLE__)   ||                           \
+	defined(__APPLE__)   || defined(__QuinnBSD__)  || \
 	defined(__sun)       || defined(sun)           || \
 	defined(__QNX__)     || defined(__QNXNTO__)
 	#define HAVE_STRLCPY
@@ -289,7 +289,7 @@ inline const char *getPlatformName()
 #elif defined(_WIN32) || defined(_WIN64)
 	"Windows"
 #elif defined(__DragonFly__) || defined(__FreeBSD__) || \
-		defined(__NetBSD__) || defined(__OpenBSD__)
+		defined(__NetBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 	"BSD"
 #elif defined(__APPLE__) && defined(__MACH__)
 	#if TARGET_OS_MAC
