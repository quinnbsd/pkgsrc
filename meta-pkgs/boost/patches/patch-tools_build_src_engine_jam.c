$NetBSD$

--- ./tools/build/src/engine/jam.cpp.orig	2020-12-03 05:02:49.000000000 +0000
+++ ./tools/build/src/engine/jam.cpp
@@ -737,7 +737,7 @@ char * executable_path( char const * arg
     const char * execname = getexecname();
     return execname ? strdup( execname ) : NULL;
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 # include <sys/sysctl.h>
 char * executable_path( char const * argv0 )
 {
