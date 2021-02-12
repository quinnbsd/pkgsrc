$NetBSD$

--- deps/uv/src/unix/fs.c.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/src/unix/fs.c
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
@@ -1345,6 +1345,7 @@ static void uv__to_stat(struct stat* src
     defined(__FreeBSD__)     || \
     defined(__OpenBSD__)     || \
     defined(__NetBSD__)      || \
+    defined(__QuinnBSD__)    || \
     defined(_GNU_SOURCE)     || \
     defined(_BSD_SOURCE)     || \
     defined(_SVID_SOURCE)    || \
@@ -1357,7 +1358,7 @@ static void uv__to_stat(struct stat* src
   dst->st_ctim.tv_sec = src->st_ctim.tv_sec;
   dst->st_ctim.tv_nsec = src->st_ctim.tv_nsec;
 # if defined(__FreeBSD__)    || \
-     defined(__NetBSD__)
+     defined(__NetBSD__) || defined(__QuinnBSD__)
   dst->st_birthtim.tv_sec = src->st_birthtim.tv_sec;
   dst->st_birthtim.tv_nsec = src->st_birthtim.tv_nsec;
   dst->st_flags = src->st_flags;
