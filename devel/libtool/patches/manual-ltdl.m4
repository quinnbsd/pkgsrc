$NetBSD$

--- m4/ltdl.m4.orig	2015-01-16 18:52:04.000000000 +0000
+++ m4/ltdl.m4
@@ -473,7 +473,7 @@ AC_CACHE_CHECK([whether deplibs are load
     # If you are looking for one http://www.opendarwin.org/projects/dlcompat
     lt_cv_sys_dlopen_deplibs=yes
     ;;
-  freebsd* | dragonfly*)
+  freebsd* | dragonfly* | quinnbsd*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
   gnu* | linux* | k*bsd*-gnu | kopensolaris*-gnu)
@@ -496,7 +496,10 @@ AC_CACHE_CHECK([whether deplibs are load
     # at 6.2 and later dlopen does load deplibs.
     lt_cv_sys_dlopen_deplibs=yes
     ;;
-  netbsd*)
+  mirbsd*)
+    lt_cv_sys_dlopen_deplibs=yes
+    ;;
+  netbsd* | minix*)
     lt_cv_sys_dlopen_deplibs=yes
     ;;
   openbsd*)
