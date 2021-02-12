$NetBSD$

--- configure.py.orig	2021-01-04 13:59:31.000000000 +0000
+++ configure.py
@@ -47,7 +47,7 @@ from fetch_deps import FetchDeps
 # parse our options
 parser = optparse.OptionParser()
 
-valid_os = ('win', 'mac', 'solaris', 'freebsd', 'openbsd', 'linux',
+valid_os = ('win', 'mac', 'solaris', 'freebsd', 'openbsd', 'linux', 'quinnbsd',
             'android', 'aix', 'cloudabi')
 valid_arch = ('arm', 'arm64', 'ia32', 'mips', 'mipsel', 'mips64el', 'ppc',
               'ppc64', 'x32','x64', 'x86', 'x86_64', 's390x')
@@ -1141,10 +1141,10 @@ def configure_node(o):
 
   o['variables']['enable_lto'] = b(options.enable_lto)
 
-  if flavor in ('solaris', 'mac', 'linux', 'freebsd'):
+  if flavor in ('solaris', 'mac', 'linux', 'freebsd', 'quinnbsd'):
     use_dtrace = not options.without_dtrace
     # Don't enable by default on linux and freebsd
-    if flavor in ('linux', 'freebsd'):
+    if flavor in ('linux', 'freebsd', 'quinnbsd'):
       use_dtrace = options.with_dtrace
 
     if flavor == 'linux':
