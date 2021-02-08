$NetBSD$

--- utils/lit/lit/llvm/config.py.orig	2019-12-11 19:15:30.000000000 +0000
+++ utils/lit/lit/llvm/config.py
@@ -53,7 +53,7 @@ class LLVMConfig(object):
             features.add('system-windows')
         elif platform.system() == "Linux":
             features.add('system-linux')
-        elif platform.system() in ['FreeBSD']:
+        elif platform.system() in ['FreeBSD','QuinnBSD']:
             features.add('system-freebsd')
         elif platform.system() == "NetBSD":
             features.add('system-netbsd')
