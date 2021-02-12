$NetBSD$

--- io.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ io.c
@@ -41,7 +41,7 @@
 # define NO_SAFE_RENAME
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__sun) || defined(_nec_ews)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__sun) || defined(_nec_ews) || defined(__QuinnBSD__)
 # define USE_SETVBUF
 #endif
 
@@ -9512,7 +9512,7 @@ rb_f_select(int argc, VALUE *argv, VALUE
     return rb_ensure(select_call, (VALUE)&args, select_end, (VALUE)&args);
 }
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
  typedef unsigned long ioctl_req_t;
 # define NUM2IOCTLREQ(num) NUM2ULONG(num)
 #else
