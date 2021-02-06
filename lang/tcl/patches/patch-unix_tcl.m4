$NetBSD$

--- unix/tcl.m4.orig	2020-12-11 17:46:23.000000000 +0000
+++ unix/tcl.m4
@@ -1488,7 +1488,7 @@ AC_DEFUN([SC_CONFIG_CFLAGS], [
 	    	LDFLAGS="$LDFLAGS -pthread"
 	    ])
 	    ;;
-	DragonFly-*|FreeBSD-*)
+	DragonFly-*|FreeBSD-*|QuinnBSD-*)
 	    # This configuration from FreeBSD Ports.
 	    SHLIB_CFLAGS="-fPIC"
 	    SHLIB_LD="${CC} -shared"
@@ -1980,7 +1980,7 @@ dnl # preprocessing tests use only CPPFL
 	    BSD/OS*) ;;
 	    CYGWIN_*|MINGW32_*|MSYS_*) ;;
 	    IRIX*) ;;
-	    NetBSD-*|DragonFly-*|FreeBSD-*|OpenBSD-*) ;;
+	    NetBSD-*|DragonFly-*|FreeBSD-*|OpenBSD-*|QuinnBSD-*) ;;
 	    Darwin-*) ;;
 	    SCO_SV-3.2*) ;;
 	    *) SHLIB_CFLAGS="-fPIC" ;;
