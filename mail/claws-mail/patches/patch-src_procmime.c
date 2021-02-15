$NetBSD$

--- ./src/procmime.c.orig	2020-10-19 10:37:56.000000000 +0000
+++ ./src/procmime.c
@@ -1148,7 +1148,7 @@ GList *procmime_get_mime_type_list(void)
 	if (mime_type_list) 
 		return mime_type_list;
 	
-#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 	if ((fp = claws_fopen(DATAROOTDIR "/mime/globs", "rb")) == NULL) 
 #else
 	if ((fp = claws_fopen("/usr/share/mime/globs", "rb")) == NULL) 
