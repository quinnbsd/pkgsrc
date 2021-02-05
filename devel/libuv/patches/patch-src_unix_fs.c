$NetBSD$

--- src/unix/fs.c.orig	2020-09-25 00:34:43.000000000 +0000
+++ src/unix/fs.c
@@ -50,7 +50,7 @@
     defined(__FreeBSD__)          ||                                      \
     defined(__FreeBSD_kernel__)   ||                                      \
     defined(__OpenBSD__)          ||                                      \
-    defined(__NetBSD__)
+    defined(__NetBSD__) || defined(__QuinnBSD__)
 # define HAVE_PREADV 1
 #else
 # define HAVE_PREADV 0
@@ -76,7 +76,7 @@
     defined(__FreeBSD__)          ||                                      \
     defined(__FreeBSD_kernel__)   ||                                      \
     defined(__OpenBSD__)          ||                                      \
-    defined(__NetBSD__)
+    defined(__NetBSD__) || defined(__QuinnBSD__)
 # include <sys/param.h>
 # include <sys/mount.h>
 #elif defined(__sun)      || \
@@ -240,7 +240,7 @@ static ssize_t uv__fs_futime(uv_fs_t* re
     || defined(__FreeBSD_kernel__)                                            \
     || defined(__NetBSD__)                                                    \
     || defined(__OpenBSD__)                                                   \
-    || defined(__sun)
+    || defined(__sun) || defined(__QuinnBSD__)
   struct timeval tv[2];
   tv[0] = uv__fs_to_timeval(req->atime);
   tv[1] = uv__fs_to_timeval(req->mtime);
@@ -944,7 +944,7 @@ ok:
 #elif defined(__APPLE__)           || \
       defined(__DragonFly__)       || \
       defined(__FreeBSD__)         || \
-      defined(__FreeBSD_kernel__)
+      defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
   {
     off_t len;
     ssize_t r;
@@ -954,7 +954,7 @@ ok:
      * number of bytes have been sent, we don't consider it an error.
      */
 
-#if defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
     len = 0;
     r = sendfile(in_fd, out_fd, req->off, req->bufsml[0].len, NULL, &len, 0);
 #elif defined(__FreeBSD_kernel__)
@@ -1022,7 +1022,7 @@ static ssize_t uv__fs_utime(uv_fs_t* req
     || defined(__FreeBSD__)                                                   \
     || defined(__FreeBSD_kernel__)                                            \
     || defined(__NetBSD__)                                                    \
-    || defined(__OpenBSD__)
+    || defined(__OpenBSD__) || defined(__QuinnBSD__)
   struct timeval tv[2];
   tv[0] = uv__fs_to_timeval(req->atime);
   tv[1] = uv__fs_to_timeval(req->mtime);
@@ -1061,7 +1061,7 @@ static ssize_t uv__fs_lutime(uv_fs_t* re
       defined(__DragonFly__)      ||                                          \
       defined(__FreeBSD__)        ||                                          \
       defined(__FreeBSD_kernel__) ||                                          \
-      defined(__NetBSD__)
+      defined(__NetBSD__) || defined(__QuinnBSD__)
   struct timeval tv[2];
   tv[0] = uv__fs_to_timeval(req->atime);
   tv[1] = uv__fs_to_timeval(req->mtime);
@@ -1318,7 +1318,7 @@ static void uv__to_stat(struct stat* src
   dst->st_blksize = src->st_blksize;
   dst->st_blocks = src->st_blocks;
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__NetBSD__)
   dst->st_atim.tv_sec = src->st_atimespec.tv_sec;
   dst->st_atim.tv_nsec = src->st_atimespec.tv_nsec;
   dst->st_mtim.tv_sec = src->st_mtimespec.tv_sec;
@@ -1344,20 +1344,18 @@ static void uv__to_stat(struct stat* src
     defined(__DragonFly__)   || \
     defined(__FreeBSD__)     || \
     defined(__OpenBSD__)     || \
-    defined(__NetBSD__)      || \
     defined(_GNU_SOURCE)     || \
     defined(_BSD_SOURCE)     || \
     defined(_SVID_SOURCE)    || \
     defined(_XOPEN_SOURCE)   || \
-    defined(_DEFAULT_SOURCE))
+    defined(_DEFAULT_SOURCE) || defined(__QuinnBSD__))
   dst->st_atim.tv_sec = src->st_atim.tv_sec;
   dst->st_atim.tv_nsec = src->st_atim.tv_nsec;
   dst->st_mtim.tv_sec = src->st_mtim.tv_sec;
   dst->st_mtim.tv_nsec = src->st_mtim.tv_nsec;
   dst->st_ctim.tv_sec = src->st_ctim.tv_sec;
   dst->st_ctim.tv_nsec = src->st_ctim.tv_nsec;
-# if defined(__FreeBSD__)    || \
-     defined(__NetBSD__)
+# if defined(__FreeBSD__) || defined(__QuinnBSD__)
   dst->st_birthtim.tv_sec = src->st_birthtim.tv_sec;
   dst->st_birthtim.tv_nsec = src->st_birthtim.tv_nsec;
   dst->st_flags = src->st_flags;
