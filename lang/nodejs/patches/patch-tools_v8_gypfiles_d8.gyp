$NetBSD$

--- tools/v8_gypfiles/d8.gyp.orig	2021-01-04 13:59:36.000000000 +0000
+++ tools/v8_gypfiles/d8.gyp
@@ -45,7 +45,7 @@
         }],
         ['(OS=="linux" or OS=="mac" or OS=="freebsd" or OS=="netbsd" \
            or OS=="openbsd" or OS=="solaris" or OS=="android" \
-           or OS=="qnx" or OS=="aix")', {
+           or OS=="qnx" or OS=="aix" or OS=="quinnbsd")', {
              'sources': [ '<(V8_ROOT)/src/d8/d8-posix.cc', ]
            }],
         [ 'OS=="win"', {
