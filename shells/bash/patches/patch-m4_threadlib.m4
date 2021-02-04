$NetBSD$

--- m4/threadlib.m4.orig	2019-02-13 21:22:54.000000000 +0000
+++ m4/threadlib.m4
@@ -94,7 +94,7 @@ changequote([,])dnl
     # need special flags to disable these optimizations. For example, the
     # definition of 'errno' in <errno.h>.
     case "$host_os" in
-      aix* | freebsd*) CPPFLAGS="$CPPFLAGS -D_THREAD_SAFE" ;;
+      aix* | freebsd* | quinnbsd*) CPPFLAGS="$CPPFLAGS -D_THREAD_SAFE" ;;
       solaris*) CPPFLAGS="$CPPFLAGS -D_REENTRANT" ;;
     esac
   fi
