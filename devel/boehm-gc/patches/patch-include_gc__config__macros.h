$NetBSD$

--- include/gc_config_macros.h.orig	2019-03-02 08:54:41.000000000 +0000
+++ include/gc_config_macros.h
@@ -90,7 +90,7 @@
 #   define GC_HAIKU_THREADS
 # elif defined(__OpenBSD__)
 #   define GC_OPENBSD_THREADS
-# elif defined(__DragonFly__) || defined(__FreeBSD_kernel__) \
+# elif defined(__DragonFly__) || defined(__QuinnBSD__) || defined(__FreeBSD_kernel__) \
        || (defined(__FreeBSD__) && !defined(SN_TARGET_ORBIS))
 #   define GC_FREEBSD_THREADS
 # elif defined(__NetBSD__)
@@ -331,7 +331,7 @@
 /* of compilers.                                                        */
 /* This may also be desirable if it is possible but expensive to        */
 /* retrieve the call chain.                                             */
-#if (defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__) \
+#if (defined(__linux__) || defined(__DragonFly__) || defined(__QuinnBSD__) || defined(__FreeBSD__) \
      || defined(__FreeBSD_kernel__) || defined(__HAIKU__) \
      || defined(__NetBSD__) || defined(__OpenBSD__) \
      || defined(HOST_ANDROID) || defined(__ANDROID__)) \
