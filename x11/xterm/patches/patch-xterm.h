$NetBSD$

--- xterm.h.orig	2020-12-23 00:21:44.000000000 +0000
+++ xterm.h
@@ -84,8 +84,8 @@
 #define USE_POSIX_TERMIOS 1
 #endif
 
-#ifdef __FreeBSD__
-#if __FreeBSD_version >= 900000
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
+#if __FreeBSD_version >= 900000 || defined(__QuinnBSD__)
 #define USE_SYSV_UTMP 1
 #define UTMPX_FOR_UTMP 1
 #define HAVE_UTMP_UT_HOST 1
@@ -131,11 +131,11 @@
 #define HAVE_UTMP_UT_HOST 1
 #endif
 
-#if defined(UTMPX_FOR_UTMP) && !(defined(__MVS__) || defined(__hpux) || defined(__FreeBSD__))
+#if defined(UTMPX_FOR_UTMP) && !(defined(__MVS__) || defined(__hpux) || defined(__FreeBSD__) || defined(__QuinnBSD__))
 #define HAVE_UTMP_UT_SESSION 1
 #endif
 
-#if !(defined(linux) && (!defined(__GLIBC__) || (__GLIBC__ < 2))) && !defined(SVR4) && !defined(__FreeBSD__)
+#if !(defined(linux) && (!defined(__GLIBC__) || (__GLIBC__ < 2))) && !defined(SVR4) && !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 #define ut_xstatus ut_exit.e_exit
 #endif
 
