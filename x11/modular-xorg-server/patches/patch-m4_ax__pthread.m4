$NetBSD$

--- m4/ax_pthread.m4.orig	2020-12-01 16:32:25.000000000 +0000
+++ m4/ax_pthread.m4
@@ -274,7 +274,7 @@ if test "x$ax_pthread_ok" = xyes; then
         AC_MSG_CHECKING([if more special flags are required for pthreads])
         flag=no
         case ${host_os} in
-            aix* | freebsd* | darwin*) flag="-D_THREAD_SAFE";;
+            aix* | freebsd* | darwin* | quinnbsd*) flag="-D_THREAD_SAFE";;
             osf* | hpux*) flag="-D_REENTRANT";;
             solaris*)
             if test "$GCC" = "yes"; then
