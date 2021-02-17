$NetBSD$

--- lib/angelscript/source/as_memory.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ lib/angelscript/source/as_memory.cpp
@@ -38,7 +38,7 @@
 
 #include <stdlib.h>
 
-#if !defined(__APPLE__) && !defined(__SNC__) && !defined(__ghs__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__APPLE__) && !defined(__SNC__) && !defined(__ghs__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__QuinnBSD__)
 #include <malloc.h>
 #endif
 
