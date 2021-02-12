$NetBSD$

--- node.gyp.orig	2021-01-04 13:59:34.000000000 +0000
+++ node.gyp
@@ -333,7 +333,7 @@
       'target_name': 'node_text_start',
       'type': 'none',
       'conditions': [
-        [ 'OS in "linux freebsd solaris" and '
+        [ 'OS in "linux freebsd solaris quinnbsd" and '
           'target_arch=="x64"', {
           'type': 'static_library',
           'sources': [
@@ -528,7 +528,7 @@
             'src/node_snapshot_stub.cc'
           ],
         }],
-        [ 'OS in "linux freebsd" and '
+        [ 'OS in "linux freebsd quinnbsd" and '
           'target_arch=="x64"', {
           'dependencies': [ 'node_text_start' ],
           'ldflags+': [
@@ -902,7 +902,7 @@
             'src/tls_wrap.h'
           ],
         }],
-        [ 'OS in "linux freebsd mac solaris" and '
+        [ 'OS in "linux freebsd quinnbsd mac solaris" and '
           'target_arch=="x64" and '
           'node_target_type=="executable"', {
           'defines': [ 'NODE_ENABLE_LARGE_CODE_PAGES=1' ],
