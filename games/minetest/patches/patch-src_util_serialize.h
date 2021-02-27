$NetBSD$

--- src/util/serialize.h.orig	2021-02-23 18:50:37.000000000 +0000
+++ src/util/serialize.h
@@ -32,7 +32,7 @@ with this program; if not, write to the
 		#define __BIG_ENDIAN 1
 	#elif defined(__MACH__) && defined(__APPLE__)
 		#include <machine/endian.h>
-	#elif defined(__FreeBSD__) || defined(__DragonFly__)
+	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 		#include <sys/endian.h>
 	#else
 		#include <endian.h>
