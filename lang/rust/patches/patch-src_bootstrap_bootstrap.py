$NetBSD$

--- src/bootstrap/bootstrap.py.orig	2020-11-16 14:01:53.000000000 +0000
+++ src/bootstrap/bootstrap.py
@@ -207,11 +207,17 @@ def default_build_triple():
         'Darwin': 'apple-darwin',
         'DragonFly': 'unknown-dragonfly',
         'FreeBSD': 'unknown-freebsd',
+        'QuinnBSD': 'unknown-freebsd',
         'Haiku': 'unknown-haiku',
         'NetBSD': 'unknown-netbsd',
         'OpenBSD': 'unknown-openbsd'
     }
 
+    # For NetBSD, use `uname -p`, as there it is reliable & sensible
+    if ostype == 'NetBSD':
+        cputype = subprocess.check_output(
+            ['uname', '-p']).strip().decode(default_encoding)
+
     # Consider the direct transformation first and then the special cases
     if ostype in ostype_mapper:
         ostype = ostype_mapper[ostype]
@@ -298,10 +304,12 @@ def default_build_triple():
             ostype = 'linux-androideabi'
         else:
             ostype += 'eabihf'
-    elif cputype in {'armv7l', 'armv8l'}:
+    elif cputype in {'armv7l', 'armv8l', 'earmv7hf'}:
         cputype = 'armv7'
         if ostype == 'linux-android':
             ostype = 'linux-androideabi'
+        elif ostype == 'unknown-netbsd':
+            ostype += '-eabihf'
         else:
             ostype += 'eabihf'
     elif cputype == 'mips':
@@ -791,7 +799,7 @@ class RustBuild(object):
             if "LIBRARY_PATH" in env else ""
         # preserve existing RUSTFLAGS
         env.setdefault("RUSTFLAGS", "")
-        env["RUSTFLAGS"] += " -Cdebuginfo=2"
+        env["RUSTFLAGS"] += " -Copt-level=2"
 
         build_section = "target.{}".format(self.build_triple())
         target_features = []
