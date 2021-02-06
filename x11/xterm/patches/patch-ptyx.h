$NetBSD$

--- ptyx.h.orig	2020-12-25 15:15:37.000000000 +0000
+++ ptyx.h
@@ -179,7 +179,7 @@
 #define USE_PTY_DEVICE 1
 #define USE_PTY_SEARCH 1
 
-#if defined(__osf__) || (defined(linux) && defined(__GLIBC__) && (__GLIBC__ >= 2) && (__GLIBC_MINOR__ >= 1)) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__osf__) || (defined(linux) && defined(__GLIBC__) && (__GLIBC__ >= 2) && (__GLIBC_MINOR__ >= 1)) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__QuinnBSD__)
 #undef USE_PTY_DEVICE
 #undef USE_PTY_SEARCH
 #define USE_PTS_DEVICE 1
@@ -249,7 +249,7 @@
 #ifdef __hpux
 #define	PTYCHAR2	"fedcba9876543210"
 #else	/* !__hpux */
-#if defined(__DragonFly__) || defined(__FreeBSD__)
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 #define	PTYCHAR2	"0123456789abcdefghijklmnopqrstuv"
 #else /* !__FreeBSD__ */
 #define	PTYCHAR2	"0123456789abcdef"
