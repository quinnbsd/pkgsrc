$NetBSD$

--- source/Irrlicht/COSOperator.cpp.orig	2012-11-03 18:07:52.000000000 +0000
+++ source/Irrlicht/COSOperator.cpp
@@ -12,6 +12,7 @@
 #include <string.h>
 #include <unistd.h>
 #ifndef _IRR_SOLARIS_PLATFORM_
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -183,7 +184,7 @@ bool COSOperator::getSystemMemory(u32* T
 	_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
 	return true;
 
-#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__)
+#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 #if defined(_SC_PHYS_PAGES) && defined(_SC_AVPHYS_PAGES)
         long ps = sysconf(_SC_PAGESIZE);
         long pp = sysconf(_SC_PHYS_PAGES);
