$NetBSD$

--- hw/xfree86/xorg-wrapper.c.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/xorg-wrapper.c
@@ -39,7 +39,7 @@
 #include <sys/sysmacros.h>
 #endif
 #include <sys/types.h>
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #include <sys/consio.h>
 #endif
 #include <unistd.h>
@@ -170,7 +170,7 @@ static int on_console(int fd)
     r = fstat(fd, &st);
     if (r == 0 && S_ISCHR(st.st_mode) && major(st.st_rdev) == 4)
       return 1;
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
     int idx;
 
     if (ioctl(fd, VT_GETINDEX, &idx) != -1)
