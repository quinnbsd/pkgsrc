$NetBSD$

--- tools/v8_gypfiles/toolchain.gypi.orig	2021-01-04 13:59:36.000000000 +0000
+++ tools/v8_gypfiles/toolchain.gypi
@@ -990,7 +990,7 @@
         },
       }],
       ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" \
-         or OS=="netbsd" or OS=="mac" or OS=="android" or OS=="qnx") and \
+         or OS=="netbsd" or OS=="mac" or OS=="android" or OS=="qnx" or OS=="quinnbsd") and \
         v8_target_arch=="ia32"', {
         'cflags': [
           '-msse2',
@@ -999,7 +999,7 @@
         ],
       }],
       ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" \
-         or OS=="netbsd" or OS=="mac" or OS=="android" or OS=="qnx") and \
+         or OS=="netbsd" or OS=="mac" or OS=="android" or OS=="qnx" or OS=="quinnbsd") and \
         (v8_target_arch=="arm" or v8_target_arch=="ia32" or \
          v8_target_arch=="mips" or v8_target_arch=="mipsel" or \
          v8_target_arch=="ppc")', {
@@ -1070,7 +1070,7 @@
         ],
       }],
       ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris" \
-         or OS=="netbsd" or OS=="qnx" or OS=="aix"', {
+         or OS=="netbsd" or OS=="qnx" or OS=="aix" or OS=="quinnbsd"', {
         'conditions': [
           [ 'v8_no_strict_aliasing==1', {
             'cflags': [ '-fno-strict-aliasing' ],
@@ -1083,7 +1083,7 @@
       ['OS=="freebsd" or OS=="openbsd"', {
         'cflags': [ '-I/usr/local/include' ],
       }],
-      ['OS=="netbsd"', {
+      ['OS=="netbsd" or OS=="quinnbsd"', {
         'cflags': [ '-I/usr/pkg/include' ],
       }],
       ['OS=="aix"', {
@@ -1117,7 +1117,7 @@
         ],
         'conditions': [
           ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd" or \
-            OS=="qnx" or OS=="aix"', {
+            OS=="qnx" or OS=="aix" or OS=="quinnbsd"', {
             'cflags': [ '-Woverloaded-virtual', '<(wno_array_bounds)', ],
           }],
           ['OS=="linux" and v8_enable_backtrace==1', {
@@ -1168,7 +1168,7 @@
             },
             'conditions': [
               ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd" or \
-            OS=="qnx" or OS=="aix"', {
+            OS=="qnx" or OS=="aix" or OS=="quinnbsd"', {
                 'cflags!': [
                   '-O3',
                   '-O2',
@@ -1219,7 +1219,7 @@
             },
             'conditions': [
               ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd" or \
-            OS=="qnx" or OS=="aix"', {
+            OS=="qnx" or OS=="aix" or OS=="quinnbsd"', {
                 'cflags!': [
                   '-O0',
                   '-O1',
@@ -1269,7 +1269,7 @@
         'defines!': ['ENABLE_HANDLE_ZAPPING',],
         'conditions': [
           ['OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="netbsd" \
-            or OS=="aix"', {
+            or OS=="aix" or OS=="quinnbsd"', {
             'cflags!': [
               '-Os',
             ],
