$NetBSD$

--- pkgs/tdbcmysql1.1.2/tclconfig/tcl.m4.orig	2020-12-21 21:23:27.000000000 +0000
+++ pkgs/tdbcmysql1.1.2/tclconfig/tcl.m4
@@ -1489,7 +1489,7 @@ AC_DEFUN([TEA_CONFIG_CFLAGS], [
 	        ])
 	    ])
 	    ;;
-	Linux*|GNU*|NetBSD-Debian|DragonFly-*|FreeBSD-*)
+	Linux*|GNU*|NetBSD-Debian|DragonFly-*|FreeBSD-*|QuinnBSD-*)
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_SUFFIX=".so"
 
@@ -1501,7 +1501,7 @@ AC_DEFUN([TEA_CONFIG_CFLAGS], [
 	    LDFLAGS="$LDFLAGS -Wl,--export-dynamic"
 
 	    case $system in
-	    DragonFly-*|FreeBSD-*)
+	    DragonFly-*|FreeBSD-*|QuinnBSD-*)
 		AS_IF([test "${TCL_THREADS}" = "1"], [
 		    # The -pthread needs to go in the LDFLAGS, not LIBS
 		    LIBS=`echo $LIBS | sed s/-pthread//`
@@ -1915,7 +1915,7 @@ dnl # preprocessing tests use only CPPFL
 	    BSD/OS*) ;;
 	    CYGWIN_*|MINGW32_*|MINGW64_*|MSYS_*) ;;
 	    IRIX*) ;;
-	    NetBSD-*|DragonFly-*|FreeBSD-*|OpenBSD-*) ;;
+	    NetBSD-*|DragonFly-*|FreeBSD-*|OpenBSD-*|QuinnBSD-*) ;;
 	    Darwin-*) ;;
 	    SCO_SV-3.2*) ;;
 	    windows) ;;
