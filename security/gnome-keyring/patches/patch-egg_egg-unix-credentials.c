$NetBSD$

--- egg/egg-unix-credentials.c.orig	2018-06-25 04:15:03.000000000 +0000
+++ egg/egg-unix-credentials.c
@@ -48,6 +48,10 @@
 #include <ucred.h>
 #endif
 
+#if defined(__NetBSD__)
+#undef LOCAL_CREDS
+#endif
+
 int
 egg_unix_credentials_read (int sock, pid_t *pid, uid_t *uid)
 {
@@ -179,7 +183,7 @@ egg_unix_credentials_write (int socket)
 {
 	char buf;
 	int bytes_written;
-#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__) || defined(__QuinnBSD__))
 	union {
 		struct cmsghdr hdr;
 		char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
@@ -190,7 +194,7 @@ egg_unix_credentials_write (int socket)
 
 	buf = 0;
 
-#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__) || defined(__QuinnBSD__))
 	iov.iov_base = &buf;
 	iov.iov_len = 1;
 
@@ -208,7 +212,7 @@ egg_unix_credentials_write (int socket)
 
 again:
 
-#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__) || defined(__QuinnBSD__))
 	bytes_written = sendmsg (socket, &msg, 0);
 #else
 	bytes_written = write (socket, &buf, 1);
@@ -243,14 +247,14 @@ egg_unix_credentials_executable (pid_t p
 	char *result = NULL;
 
 	/* Try and figure out the path from the pid */
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 	char path[1024];
 	char buffer[64];
 	int count;
 
 #if defined(__linux__)
 	snprintf (buffer, sizeof (buffer), "/proc/%d/exe", (int)pid);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 	snprintf (buffer, sizeof (buffer), "/proc/%d/file", (int)pid);
 #endif
 
