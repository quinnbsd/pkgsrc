$NetBSD$

--- metadata/meta-get-tree.c.orig	2011-03-21 15:42:18.000000000 +0000
+++ metadata/meta-get-tree.c
@@ -51,7 +51,7 @@ main (int argc,
 	{
 	  char buffer[1000];
 	  g_print ("Pausing, press enter\n");
-	  gets(buffer);
+	  gets_s(buffer, 1000);
 	}
     }
 
