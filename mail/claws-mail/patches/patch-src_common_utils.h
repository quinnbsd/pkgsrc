$NetBSD$

--- src/common/utils.h.orig	2020-10-19 10:37:56.000000000 +0000
+++ src/common/utils.h
@@ -168,7 +168,7 @@ typedef gint64 goffset;
 #define IS_ASCII(c) (((guchar) c) <= 0177 ? 1 : 0)
 
 /* from NetworkManager */
-#if (defined(HAVE_BACKTRACE) && !defined(__FreeBSD__))
+#if (defined(HAVE_BACKTRACE) && !(defined(__FreeBSD__) || defined(__QuinnBSD__)))
 #define print_backtrace()						\
 G_STMT_START								\
 {									\
