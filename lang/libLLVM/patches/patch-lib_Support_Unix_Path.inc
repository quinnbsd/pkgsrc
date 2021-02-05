$NetBSD$

--- lib/Support/Unix/Path.inc.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Support/Unix/Path.inc
@@ -56,13 +56,13 @@
 
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
@@ -109,7 +109,7 @@ const file_t kInvalidFile = -1;
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) ||     \
     defined(__minix) || defined(__FreeBSD_kernel__) || defined(__linux__) ||   \
-    defined(__CYGWIN__) || defined(__DragonFly__) || defined(_AIX) || defined(__GNU__)
+    defined(__CYGWIN__) || defined(__DragonFly__) || defined(_AIX) || defined(__GNU__) || defined(__QuinnBSD__)
 static int
 test_dir(char ret[PATH_MAX], const char *dir, const char *bin)
 {
@@ -185,7 +185,7 @@ std::string getMainExecutable(const char
   }
 #elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) ||   \
     defined(__minix) || defined(__DragonFly__) ||                              \
-    defined(__FreeBSD_kernel__) || defined(_AIX)
+    defined(__FreeBSD_kernel__) || defined(_AIX) || defined(__QuinnBSD__)
   StringRef curproc("/proc/curproc/file");
   char exe_path[PATH_MAX];
   // /proc is not mounted by default under FreeBSD, but gives more accurate
