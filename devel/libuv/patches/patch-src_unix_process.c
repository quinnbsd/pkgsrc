$NetBSD$

--- src/unix/process.c.orig	2020-09-25 00:34:43.000000000 +0000
+++ src/unix/process.c
@@ -113,7 +113,7 @@ static void uv__chld(uv_signal_t* handle
 
 
 static int uv__make_socketpair(int fds[2]) {
-#if defined(__FreeBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__) || defined(__QuinnBSD__)
   if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, fds))
     return UV__ERR(errno);
 
@@ -140,7 +140,7 @@ static int uv__make_socketpair(int fds[2
 
 
 int uv__make_pipe(int fds[2], int flags) {
-#if defined(__FreeBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__) || defined(__QuinnBSD__)
   if (pipe2(fds, flags | O_CLOEXEC))
     return UV__ERR(errno);
 
