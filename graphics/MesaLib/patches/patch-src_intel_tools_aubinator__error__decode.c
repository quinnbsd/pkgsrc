$NetBSD$

--- src/intel/tools/aubinator_error_decode.c.orig	2020-04-29 22:48:24.000000000 +0000
+++ src/intel/tools/aubinator_error_decode.c
@@ -22,6 +22,9 @@
  *
  */
 
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
+#define _WITH_GETLINE
+#endif
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
