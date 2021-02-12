$NetBSD$

--- ./process.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./process.c
@@ -117,7 +117,7 @@ static VALUE rb_cProcessTms;
 #define WSTOPSIG        WEXITSTATUS
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__QuinnBSD__)
 #define HAVE_44BSD_SETUID 1
 #define HAVE_44BSD_SETGID 1
 #endif
