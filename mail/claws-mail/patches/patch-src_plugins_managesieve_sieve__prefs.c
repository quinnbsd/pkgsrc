$NetBSD$

--- ./src/plugins/managesieve/sieve_prefs.c.orig	2020-10-19 10:37:56.000000000 +0000
+++ ./src/plugins/managesieve/sieve_prefs.c
@@ -477,7 +477,7 @@ struct SieveAccountConfig *sieve_prefs_a
 	guchar tls_type, auth, auth_type;
 	gsize len;
 	gint num;
-#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 	/* Non-GNU sscanf() does not understand the %ms format, so we
 	 * have to do the allocation of target buffer ourselves before
 	 * calling sscanf(), and copy the host string to config->host.
@@ -503,13 +503,13 @@ struct SieveAccountConfig *sieve_prefs_a
 
 	enc_userid[0] = '\0';
 	enc_passwd[0] = '\0';
-#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 	if ((num = sscanf(confstr, "%c%c %255s %c%hu %hhu %hhu %hhu %255s %255s",
 #else
 	if ((num = sscanf(confstr, "%c%c %ms %c%hu %hhu %hhu %hhu %255s %255s",
 #endif
 			&enable, &use_host,
-#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 			tmphost,
 #else
 			&config->host,
@@ -539,7 +539,7 @@ struct SieveAccountConfig *sieve_prefs_a
 	config->auth = auth;
 	config->auth_type = auth_type;
 
-#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(G_OS_WIN32) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 	config->host = g_strndup(tmphost, 255);
 #endif
 
