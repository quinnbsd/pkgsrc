$NetBSD$

--- node.gypi.orig	2021-01-04 13:59:34.000000000 +0000
+++ node.gypi
@@ -203,7 +203,7 @@
         'NODE_PLATFORM="darwin"',
       ],
     }],
-    [ 'OS=="freebsd"', {
+    [ 'OS=="freebsd" or OS=="quinnbsd"', {
       'libraries': [
         '-lutil',
         '-lkvm',
@@ -245,6 +245,7 @@
     [ 'OS=="solaris"', {
       'libraries': [
         '-lkstat',
+        '-lsocket',
         '-lumem',
       ],
       'defines!': [
@@ -256,7 +257,7 @@
         'NODE_PLATFORM="sunos"',
       ],
     }],
-    [ '(OS=="freebsd" or OS=="linux") and node_shared=="false"'
+    [ '(OS=="freebsd" or OS=="linux" or OS=="quinnbsd") and node_shared=="false"'
         ' and force_load=="true"', {
       'ldflags': [
         '-Wl,-z,noexecstack',
@@ -281,7 +282,7 @@
         ],
       },
     }],
-    [ 'coverage=="true" and node_shared=="false" and OS in "mac freebsd linux"', {
+    [ 'coverage=="true" and node_shared=="false" and OS in "mac quinnbsd freebsd linux"', {
       'cflags!': [ '-O3' ],
       'ldflags': [ '--coverage',
                    '-g',
@@ -312,7 +313,7 @@
         '-lrt'
       ],
     }],
-    [ 'OS in "freebsd linux"', {
+    [ 'OS in "freebsd quinnbsd linux"', {
       'ldflags': [ '-Wl,-z,relro',
                    '-Wl,-z,now' ]
     }],
@@ -346,7 +347,7 @@
                 },
               },
               'conditions': [
-                ['OS in "linux freebsd" and node_shared=="false"', {
+                ['OS in "linux freebsd quinnbsd" and node_shared=="false"', {
                   'ldflags': [
                     '-Wl,--whole-archive,'
                       '<(obj_dir)/deps/openssl/<(openssl_product)',
