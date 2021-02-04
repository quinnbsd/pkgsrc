$NetBSD$

--- lib/sh/eaccess.c.orig	2020-06-05 17:43:10.000000000 +0000
+++ lib/sh/eaccess.c
@@ -213,7 +213,7 @@ sh_eaccess (path, mode)
 #  else		/* HAVE_EACCESS */	/* FreeBSD */
   ret = eaccess (path, mode);	/* XXX -- not always correct for X_OK */
 #  endif	/* HAVE_EACCESS */
-#  if defined (__FreeBSD__) || defined (SOLARIS) || defined (_AIX)
+#  if defined (__FreeBSD__) || defined (SOLARIS) || defined (_AIX) || defined (__QuinnBSD__)
   if (ret == 0 && current_user.euid == 0 && mode == X_OK)
     return (sh_stataccess (path, mode));
 #  endif	/* __FreeBSD__ || SOLARIS || _AIX */
@@ -232,7 +232,7 @@ sh_eaccess (path, mode)
   if (current_user.uid == current_user.euid && current_user.gid == current_user.egid)
     {
       ret = access (path, mode);
-#if defined (__FreeBSD__) || defined (SOLARIS)
+#if defined (__FreeBSD__) || defined (SOLARIS) || defined (__QuinnBSD__)
       if (ret == 0 && current_user.euid == 0 && mode == X_OK)
 	return (sh_stataccess (path, mode));
 #endif
