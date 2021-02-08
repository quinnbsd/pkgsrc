$NetBSD$

--- nss/lib/freebl/unix_rand.c.orig	2021-01-22 17:08:28.000000000 +0000
+++ nss/lib/freebl/unix_rand.c
@@ -160,7 +160,7 @@ RNG_kstat(PRUint32 *fed)
 
 #endif
 
-#if defined(SCO) || defined(UNIXWARE) || defined(BSDI) || defined(FREEBSD) || defined(NETBSD) || defined(DARWIN) || defined(OPENBSD) || defined(NTO) || defined(__riscos__) || defined(__GNU__) || defined(__FreeBSD_kernel__) || defined(__NetBSD_kernel__)
+#if defined(SCO) || defined(UNIXWARE) || defined(BSDI) || defined(FREEBSD) || defined(NETBSD) || defined(DARWIN) || defined(OPENBSD) || defined(NTO) || defined(__riscos__) || defined(__GNU__) || defined(__FreeBSD_kernel__) || defined(__NetBSD_kernel__) || defined(__QuinnBSD__)
 #include <sys/times.h>
 
 static size_t
