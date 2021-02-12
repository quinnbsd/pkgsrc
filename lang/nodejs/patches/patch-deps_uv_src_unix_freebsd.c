$NetBSD$

--- deps/uv/src/unix/freebsd.c.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/src/unix/freebsd.c
@@ -265,7 +265,7 @@ int uv_cpu_info(uv_cpu_info_t** cpu_info
 
 
 int uv__sendmmsg(int fd, struct uv__mmsghdr* mmsg, unsigned int vlen) {
-#if __FreeBSD__ >= 11
+#if __FreeBSD__ >= 11 || defined(__QuinnBSD__)
   return sendmmsg(fd, mmsg, vlen, /* flags */ 0);
 #else
   return errno = ENOSYS, -1;
@@ -274,7 +274,7 @@ int uv__sendmmsg(int fd, struct uv__mmsg
 
 
 int uv__recvmmsg(int fd, struct uv__mmsghdr* mmsg, unsigned int vlen) {
-#if __FreeBSD__ >= 11
+#if __FreeBSD__ >= 11 || defined(__QuinnBSD__)
   return recvmmsg(fd, mmsg, vlen, 0 /* flags */, NULL /* timeout */);
 #else
   return errno = ENOSYS, -1;
