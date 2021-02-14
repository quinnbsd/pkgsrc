$NetBSD$

--- include/private/gcconfig.h.orig	2019-03-02 08:54:41.000000000 +0000
+++ include/private/gcconfig.h
@@ -133,7 +133,7 @@ EXTERN_C_BEGIN
 # endif
 
 /* And one for FreeBSD: */
-# if (defined(__FreeBSD__) || defined(__DragonFly__) \
+# if (defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__) \
       || defined(__FreeBSD_kernel__)) && !defined(FREEBSD) \
      && !defined(SN_TARGET_ORBIS) /* Orbis compiler defines __FreeBSD__ */
 #   define FREEBSD
@@ -299,7 +299,7 @@ EXTERN_C_BEGIN
 #   define mach_type_known
 # elif defined(sparc) && defined(unix) && !defined(sun) && !defined(linux) \
        && !defined(__OpenBSD__) && !defined(__NetBSD__) \
-       && !defined(__FreeBSD__) && !defined(__DragonFly__)
+       && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__QuinnBSD__)
 #   define SPARC
 #   define DRSNX
 #   define mach_type_known
@@ -3009,7 +3009,7 @@ EXTERN_C_BEGIN
 # define SUNOS5SIGS
 #endif
 
-#if defined(FREEBSD) && (defined(__DragonFly__) || __FreeBSD__ >= 4 \
+#if defined(FREEBSD) && (defined(__DragonFly__) || defined(__QuinnBSD__) || __FreeBSD__ >= 4 \
                          || (__FreeBSD_kernel__ >= 4))
 # define SUNOS5SIGS
 #endif
