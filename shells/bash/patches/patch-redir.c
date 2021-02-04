$NetBSD$

--- redir.c.orig	2020-06-11 14:39:36.000000000 +0000
+++ redir.c
@@ -62,7 +62,7 @@ extern int errno;
 
 /* FreeBSD 13 can reliably handle atomic writes at this capacity without
    hanging. */
-#if __FreeBSD__ && !defined (HEREDOC_PIPESIZE)
+#if (defined(__FreeBSD__) || defined(__QuinnBSD__)) && !defined (HEREDOC_PIPESIZE)
 #  define HEREDOC_PIPESIZE 4096
 #endif
 
