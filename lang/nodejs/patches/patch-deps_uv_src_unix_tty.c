$NetBSD$

--- deps/uv/src/unix/tty.c.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/src/unix/tty.c
@@ -68,7 +68,7 @@ static uv_spinlock_t termios_spinlock =
 
 static int uv__tty_is_slave(const int fd) {
   int result;
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
   int dummy;
 
   result = ioctl(fd, TIOCGPTN, &dummy) != 0;
