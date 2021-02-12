$NetBSD$

--- tools/utils.py.orig	2021-01-04 13:59:36.000000000 +0000
+++ tools/utils.py
@@ -67,6 +67,8 @@ def GuessOS():
     # Doing so on purpose as they are pretty close
     # minus few features
     return 'freebsd'
+  elif id == 'QuinnBSD':
+    return 'freebsd'
   elif id == 'AIX':
     return 'aix'
   elif id == 'OS400':
