$NetBSD$

--- include/X11/Xosdefs.h.orig	2020-04-14 15:29:25.000000000 +0000
+++ include/X11/Xosdefs.h
@@ -106,7 +106,7 @@ in this Software without prior written a
 # endif
 
 # if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) \
-	|| defined(__APPLE__) || defined(__DragonFly__)
+	|| defined(__APPLE__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #  ifndef CSRG_BASED
 #   define CSRG_BASED
 #  endif
