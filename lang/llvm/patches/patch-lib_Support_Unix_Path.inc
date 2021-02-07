$NetBSD$

--- lib/Support/Unix/Path.inc.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Support/Unix/Path.inc
@@ -38,7 +38,7 @@
 #include <mach-o/dyld.h>
 #include <sys/attr.h>
 #include <copyfile.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <osreldate.h>
 #if __FreeBSD_version >= 1300057
 #include <sys/auxv.h>
@@ -64,13 +64,13 @@ extern char **environ;
 
 #include <sys/types.h>
 #if !defined(__APPLE__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) &&   \
-    !defined(__linux__) && !defined(__FreeBSD_kernel__) && !defined(_AIX)
+    !defined(__linux__) && !defined(__FreeBSD_kernel__) && !defined(_AIX) && !defined(__QuinnBSD__)
 #include <sys/statvfs.h>
 #define STATVFS statvfs
 #define FSTATVFS fstatvfs
 #define STATVFS_F_FRSIZE(vfs) vfs.f_frsize
 #else
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/mount.h>
 #include <sys/param.h>
 #elif defined(__linux__)
@@ -117,7 +117,7 @@ const file_t kInvalidFile = -1;
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) ||     \
     defined(__minix) || defined(__FreeBSD_kernel__) || defined(__linux__) ||   \
-    defined(__CYGWIN__) || defined(__DragonFly__) || defined(_AIX) || defined(__GNU__)
+    defined(__CYGWIN__) || defined(__DragonFly__) || defined(_AIX) || defined(__GNU__) || defined(__QuinnBSD__)
 static int
 test_dir(char ret[PATH_MAX], const char *dir, const char *bin)
 {
@@ -191,7 +191,7 @@ std::string getMainExecutable(const char
     if (realpath(exe_path, link_path))
       return link_path;
   }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
   // On FreeBSD if the exec path specified in ELF auxiliary vectors is
   // preferred, if available.  /proc/curproc/file and the KERN_PROC_PATHNAME
   // sysctl may not return the desired path if there are multiple hardlinks
