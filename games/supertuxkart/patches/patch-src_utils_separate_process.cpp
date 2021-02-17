$NetBSD$

--- src/utils/separate_process.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ src/utils/separate_process.cpp
@@ -35,7 +35,7 @@
 #  include <errno.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -62,7 +62,7 @@ std::string SeparateProcess::getCurrentE
         return file_manager->getFileSystem()->getAbsolutePath(path).c_str();
     }
     return "";
-#elif defined (__FreeBSD__)
+#elif defined (__FreeBSD__) || defined(__QuinnBSD__)
     char path[PATH_MAX];
     size_t len = PATH_MAX;
     const int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
