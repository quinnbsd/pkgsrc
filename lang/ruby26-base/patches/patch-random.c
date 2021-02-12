$NetBSD$

--- ./random.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./random.c
@@ -504,7 +504,7 @@ fill_random_bytes_syscall(void *buf, siz
 {
 #if (defined(__OpenBSD__) && OpenBSD >= 201411) || \
     (defined(__NetBSD__)  && __NetBSD_Version__ >= 700000000) || \
-    (defined(__FreeBSD__) && __FreeBSD_version >= 1200079)
+    (defined(__FreeBSD__) && __FreeBSD_version >= 1200079) || defined(__QuinnBSD__)
     arc4random_buf(buf, size);
     return 0;
 #else
