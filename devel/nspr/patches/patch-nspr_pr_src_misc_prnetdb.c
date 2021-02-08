$NetBSD$

--- nspr/pr/src/misc/prnetdb.c.orig	2020-09-17 15:01:34.000000000 +0000
+++ nspr/pr/src/misc/prnetdb.c
@@ -68,12 +68,17 @@ PRLock *_pr_dnsLock = NULL;
 #if defined(AIX4_3_PLUS) || (defined(AIX) && defined(_THREAD_SAFE)) \
     || (defined(HPUX10_10) && defined(_REENTRANT)) \
         || (defined(HPUX10_20) && defined(_REENTRANT)) \
-        || defined(OPENBSD)
+        || defined(OPENBSD) || defined(NETBSD)
 #define _PR_HAVE_GETPROTO_R
 #define _PR_HAVE_GETPROTO_R_INT
 #endif
 
-#if __FreeBSD_version >= 602000
+#if __FreeBSD_version >= 602000 || defined(__QuinnBSD__)
+#define _PR_HAVE_GETPROTO_R
+#define _PR_HAVE_5_ARG_GETPROTO_R
+#endif
+
+#if __DragonFly_version >= 200202
 #define _PR_HAVE_GETPROTO_R
 #define _PR_HAVE_5_ARG_GETPROTO_R
 #endif
@@ -302,7 +307,7 @@ _pr_QueryNetIfs(void)
 }
 
 #elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) \
-    || defined(NETBSD) || defined(OPENBSD)
+    || defined(NETBSD) || defined(OPENBSD) || defined(DRAGONFLY) || defined(__QuinnBSD__)
 
 /*
  * Use the BSD getifaddrs function.
@@ -2161,6 +2166,11 @@ PR_IMPLEMENT(PRAddrInfo *) PR_GetAddrInf
          */
         hints.ai_socktype = SOCK_STREAM;
 
+/* NetBSD >= 2.99.9 has a thread-safe resolver */
+#if defined(__NetBSD_Version__) && __NetBSD_Version__ < 299000900
+        LOCK_DNS();
+#endif
+
         rv = GETADDRINFO(hostname, NULL, &hints, &res);
 #ifdef AI_ADDRCONFIG
         if (rv == EAI_BADFLAGS && (hints.ai_flags & AI_ADDRCONFIG)) {
