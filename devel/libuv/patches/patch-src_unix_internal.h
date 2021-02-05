$NetBSD$

--- src/unix/internal.h.orig	2020-09-25 00:34:43.000000000 +0000
+++ src/unix/internal.h
@@ -122,7 +122,7 @@ int uv__pthread_sigmask(int how, const s
 # define UV__POLLPRI 0
 #endif
 
-#if !defined(O_CLOEXEC) && defined(__FreeBSD__)
+#if !defined(O_CLOEXEC) && (defined(__FreeBSD__) || defined(__QuinnBSD__))
 /*
  * It may be that we are just missing `__POSIX_VISIBLE >= 200809`.
  * Try using fixed value const and give up, if it doesn't work
@@ -162,7 +162,7 @@ struct uv__stream_queued_fds_s {
     defined(__FreeBSD_kernel__) || \
     defined(__linux__) || \
     defined(__OpenBSD__) || \
-    defined(__NetBSD__)
+    defined(__NetBSD__) || defined(__QuinnBSD__)
 #define uv__cloexec uv__cloexec_ioctl
 #define uv__nonblock uv__nonblock_ioctl
 #else
@@ -327,7 +327,7 @@ int uv__getsockpeername(const uv_handle_
 
 #if defined(__linux__)            ||                                      \
     defined(__FreeBSD__)          ||                                      \
-    defined(__FreeBSD_kernel__)
+    defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #define HAVE_MMSG 1
 struct uv__mmsghdr {
   struct msghdr msg_hdr;
