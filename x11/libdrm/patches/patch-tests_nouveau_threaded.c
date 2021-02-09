$NetBSD$

--- tests/nouveau/threaded.c.orig	2021-01-11 18:15:27.388030500 +0000
+++ tests/nouveau/threaded.c
@@ -36,7 +36,7 @@ static int failed;
 
 static int import_fd;
 
-#if defined(__GLIBC__) || defined(__FreeBSD__)
+#if defined(__GLIBC__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 int ioctl(int fd, unsigned long request, ...)
 #else
 int ioctl(int fd, int request, ...)
