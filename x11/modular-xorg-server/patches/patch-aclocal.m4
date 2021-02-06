$NetBSD$

--- aclocal.m4.orig	2020-12-01 16:32:40.000000000 +0000
+++ aclocal.m4
@@ -2207,7 +2207,7 @@ case $host_os in
 	lint_name=splint
 	lint_options="-badflag"
 	;;
-  *freebsd* | *netbsd*)
+  *freebsd* | *netbsd* | *quinnbsd*)
 	lint_name=lint
 	lint_options="-u -b"
 	;;
