$NetBSD$

--- lib/irrlicht/source/Irrlicht/COSOperator.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/COSOperator.cpp
@@ -290,7 +290,7 @@ bool COSOperator::getSystemMemory(u32* T
 	_IRR_IMPLEMENT_MANAGED_MARSHALLING_BUGFIX;
 	return true;
 
-#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__)
+#elif defined(_IRR_POSIX_API_) && !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 #if defined(_SC_PHYS_PAGES) && defined(_SC_AVPHYS_PAGES)
         long ps = sysconf(_SC_PAGESIZE);
         long pp = sysconf(_SC_PHYS_PAGES);
