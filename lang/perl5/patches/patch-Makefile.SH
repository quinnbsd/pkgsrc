$NetBSD$

--- Makefile.SH.orig	2020-12-18 12:43:54.000000000 +0000
+++ Makefile.SH
@@ -70,7 +70,7 @@ true)
 				${revision}.${patchlevel}.${subversion}"
 		case "$osvers" in
 	        1[5-9]*|[2-9]*)
-			shrpldflags="$shrpldflags -install_name `pwd`/\$@ -Xlinker -headerpad_max_install_names"
+			shrpldflags="$shrpldflags -install_name \$(shrpdir)/\$@ -Xlinker -headerpad_max_install_names"
 			exeldflags="-Xlinker -headerpad_max_install_names"
 			;;
 		*)
@@ -85,7 +85,7 @@ true)
 	sunos*)
 		linklibperl="-lperl"
 		;;
-	netbsd*|freebsd[234]*|openbsd*|dragonfly*|bitrig*)
+	netbsd*|freebsd[234]*|openbsd*|dragonfly*|bitrig*|quinnbsd*)
 		linklibperl="-L. -lperl"
 		;;
 	interix*)
