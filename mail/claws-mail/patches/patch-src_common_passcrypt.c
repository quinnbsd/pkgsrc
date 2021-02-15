$NetBSD$

--- src/common/passcrypt.c.orig	2020-10-19 10:37:56.000000000 +0000
+++ src/common/passcrypt.c
@@ -17,7 +17,7 @@
  * 
  */
 
-#if !defined (__FreeBSD__)
+#if !defined (__FreeBSD__) && !defined(__QuinnBSD__)
 #define _XOPEN_SOURCE 600
 #else
 #define _XOPEN_SOURCE
@@ -31,7 +31,7 @@
 #include <unistd.h>
 #include <nettle/des.h>
 
-#if defined (__FreeBSD__)
+#if defined (__FreeBSD__) || defined(__QuinnBSD__)
 #include <rpc/des_crypt.h>
 #endif
 
@@ -58,7 +58,7 @@ void passcrypt_decrypt(gchar *password,
 unsigned char crypt_cfb_iv[64];
 int crypt_cfb_blocksize = 8;	/* 8 for DES */
 
-#if defined (__FreeBSD__)
+#if defined (__FreeBSD__) || defined(__QuinnBSD__)
 static void
 crypt_cfb_buf(const char key[8], unsigned char *buf, unsigned len,
 	      unsigned chunksize, int decrypt)
