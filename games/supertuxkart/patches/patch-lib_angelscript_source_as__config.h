$NetBSD$

--- lib/angelscript/source/as_config.h.orig	2020-01-03 18:47:06.000000000 +0000
+++ lib/angelscript/source/as_config.h
@@ -944,7 +944,7 @@
 		#endif
 
 	// Free BSD
-	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+	#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 		#define AS_BSD
 		#if (defined(i386) || defined(__i386) || defined(__i386__)) && !defined(__LP64__)
 			#undef COMPLEX_MASK
