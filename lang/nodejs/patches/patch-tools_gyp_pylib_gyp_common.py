$NetBSD$

--- tools/gyp/pylib/gyp/common.py.orig	2021-01-04 13:59:35.000000000 +0000
+++ tools/gyp/pylib/gyp/common.py
@@ -449,7 +449,7 @@ def GetFlavor(params):
         return flavors[sys.platform]
     if sys.platform.startswith("sunos"):
         return "solaris"
-    if sys.platform.startswith(("dragonfly", "freebsd")):
+    if sys.platform.startswith(("dragonfly", "freebsd", "quinnbsd")):
         return "freebsd"
     if sys.platform.startswith("openbsd"):
         return "openbsd"
