$NetBSD$

--- ./src/plugins/pgpcore/sgpgme.c.orig	2020-10-19 10:37:56.000000000 +0000
+++ ./src/plugins/pgpcore/sgpgme.c
@@ -39,7 +39,7 @@
 #  include <pthread.h>
 #  include <windows.h>
 #endif
-#if (defined(__DragonFly__) || defined(SOLARIS) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__OpenBSD__))
+#if (defined(__DragonFly__) || defined(SOLARIS) || defined (__NetBSD__) || defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__QuinnBSD__))
 #  include <sys/signal.h>
 #endif
 #ifndef G_OS_WIN32
@@ -339,6 +339,7 @@ gchar *sgpgme_sigstat_info_full(gpgme_ct
 		gpgme_key_t key;
 		gpgme_error_t err;
 		const gchar *keytype, *keyid, *uid;
+		time_t ts;
 		
 		err = gpgme_get_key(ctx, sig->fpr, &key, 0);
 
