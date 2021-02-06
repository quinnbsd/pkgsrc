$NetBSD$

--- include/greet.h.orig	2019-03-02 22:06:13.000000000 +0000
+++ include/greet.h
@@ -45,7 +45,7 @@ from The Open Group.
 # define GETPWNAM_ARGS /*unknown*/
 #endif
 
-#if defined(__FreeBSD__) || defined(__bsdi__) || defined(__osf__)
+#if defined(__FreeBSD__) || defined(__bsdi__) || defined(__osf__) || defined(__QuinnBSD__)
 # define SETGRENT_TYPE int
 #else
 # define SETGRENT_TYPE void
