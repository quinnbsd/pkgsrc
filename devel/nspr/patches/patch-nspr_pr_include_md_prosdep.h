$NetBSD$

--- nspr/pr/include/md/prosdep.h.orig	2020-09-17 15:01:34.000000000 +0000
+++ nspr/pr/include/md/prosdep.h
@@ -34,7 +34,7 @@ PR_BEGIN_EXTERN_C
 #if defined(AIX)
 #include "md/_aix.h"
 
-#elif defined(FREEBSD)
+#elif defined(FREEBSD) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include "md/_freebsd.h"
 
 #elif defined(NETBSD)
