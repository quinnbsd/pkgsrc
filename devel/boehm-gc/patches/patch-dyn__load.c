$NetBSD$

--- dyn_load.c.orig	2019-03-02 08:54:41.000000000 +0000
+++ dyn_load.c
@@ -437,7 +437,7 @@ GC_INNER GC_bool GC_register_main_static
 #endif /* __GLIBC__ >= 2 || HOST_ANDROID */
 
 #if defined(__DragonFly__) || defined(__FreeBSD_kernel__) \
-    || (defined(FREEBSD) && __FreeBSD__ >= 7)
+    || (defined(FREEBSD) && __FreeBSD__ >= 7) || defined(__QuinnBSD__)
   /* On the FreeBSD system, any target system at major version 7 shall   */
   /* have dl_iterate_phdr; therefore, we need not make it weak as below. */
 # ifndef HAVE_DL_ITERATE_PHDR
