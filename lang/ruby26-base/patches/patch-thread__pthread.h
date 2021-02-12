$NetBSD$

--- ./thread_pthread.h.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./thread_pthread.h
@@ -25,7 +25,7 @@ typedef struct native_thread_data_struct
         struct list_node ubf;
         struct list_node gvl;
     } node;
-#if defined(__GLIBC__) || defined(__FreeBSD__)
+#if defined(__GLIBC__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
     union
 #else
     /*
