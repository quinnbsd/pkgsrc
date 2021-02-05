$NetBSD$

--- scons/gallium.py.orig	2020-04-29 22:48:24.000000000 +0000
+++ scons/gallium.py
@@ -341,7 +341,7 @@ def generate(env):
         cppdefines += ['NDEBUG']
     if env['build'] == 'profile':
         cppdefines += ['PROFILE']
-    if env['platform'] in ('posix', 'linux', 'freebsd', 'darwin'):
+    if env['platform'] in ('posix', 'linux', 'freebsd', 'darwin', 'quinnbsd'):
         cppdefines += [
             '_POSIX_SOURCE',
             ('_POSIX_C_SOURCE', '199309L'),
