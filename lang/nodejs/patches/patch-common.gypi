$NetBSD$

--- common.gypi.orig	2021-01-04 13:59:31.000000000 +0000
+++ common.gypi
@@ -368,11 +368,11 @@
           'BUILDING_UV_SHARED=1',
         ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris aix"', {
+      [ 'OS in "linux quinnbsd freebsd openbsd netbsd solaris aix"', {
         'cflags': [ '-pthread' ],
         'ldflags': [ '-pthread' ],
       }],
-      [ 'OS in "linux freebsd openbsd solaris android aix cloudabi"', {
+      [ 'OS in "linux quinnbsd freebsd openbsd netbsd netbsd solaris android aix cloudabi"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [ '-fno-rtti', '-fno-exceptions', '-std=gnu++1y' ],
         'defines': [ '__STDC_FORMAT_MACROS' ],
@@ -525,10 +525,10 @@
           }],
         ],
       }],
-      ['OS=="freebsd" and node_use_dtrace=="true"', {
+      ['(OS=="freebsd" or OS=="quinnbsd") and node_use_dtrace=="true"', {
         'libraries': [ '-lelf' ],
       }],
-      ['OS=="freebsd"', {
+      ['OS=="freebsd" or OS=="quinnbsd"', {
         'ldflags': [
           '-Wl,--export-dynamic',
         ],
