$NetBSD$

--- nss/lib/freebl/unix_urandom.c.orig	2021-01-22 17:08:28.000000000 +0000
+++ nss/lib/freebl/unix_urandom.c
@@ -32,7 +32,7 @@ RNG_SystemRNG(void *dest, size_t maxLen)
     size_t fileBytes = 0;
     unsigned char *buffer = dest;
 
-#if defined(__OpenBSD__) || (defined(__FreeBSD__) && __FreeBSD_version >= 1200000) || (defined(LINUX) && defined(__GLIBC__) && ((__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 25))))
+#if defined(__OpenBSD__) || defined(__QuinnBSD__) || (defined(__FreeBSD__) && __FreeBSD_version >= 1200000) || (defined(LINUX) && defined(__GLIBC__) && ((__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 25))))
     int result;
 
     while (fileBytes < maxLen) {
