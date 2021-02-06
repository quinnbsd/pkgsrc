$NetBSD$

--- ptydata.c.orig	2020-10-12 18:46:28.000000000 +0000
+++ ptydata.c
@@ -281,7 +281,7 @@ readPtyData(XtermWidget xw, PtySelect *
 		Panic("input: read returned unexpected error (%d)\n", save_err);
 	    size = 0;
 	} else if (size == 0) {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 	    NormalExit();
 #else
 	    Panic("input: read returned zero\n", 0);
