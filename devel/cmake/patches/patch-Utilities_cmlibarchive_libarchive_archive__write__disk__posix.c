$NetBSD$

--- Utilities/cmlibarchive/libarchive/archive_write_disk_posix.c.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibarchive/libarchive/archive_write_disk_posix.c
@@ -446,7 +446,7 @@ la_opendirat(int fd, const char *path) {
 	    | O_PATH
 #elif defined(O_SEARCH)
 	    | O_SEARCH
-#elif defined(__FreeBSD__) && defined(O_EXEC)
+#elif (defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(O_EXEC)
 	    | O_EXEC
 #else
 	    | O_RDONLY
