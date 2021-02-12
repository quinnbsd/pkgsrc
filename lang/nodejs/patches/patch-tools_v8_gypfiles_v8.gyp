$NetBSD$

--- tools/v8_gypfiles/v8.gyp.orig	2021-01-04 13:59:36.000000000 +0000
+++ tools/v8_gypfiles/v8.gyp
@@ -782,7 +782,7 @@
           'conditions': [
             # iOS Xcode simulator builds run on an x64 target. iOS and macOS are both
             # based on Darwin and thus POSIX-compliant to a similar degree.
-            ['OS=="linux" or OS=="mac" or OS=="ios" or OS=="freebsd"', {
+            ['OS=="linux" or OS=="mac" or OS=="ios" or OS=="freebsd" or OS=="quinnbsd"', {
               'sources': [
                 '<!@pymod_do_main(GN-scraper "<(V8_ROOT)/BUILD.gn"  "\\"v8_base_without_compiler.*?is_linux.*?sources \+= ")',
               ],
@@ -903,6 +903,12 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
+        # NetBSD/arm also needs -larm.
+        ['OS == "netbsd" and v8_current_cpu in ["arm"]', {
+          'link_settings': {
+            'libraries': ['-larm', ],
+          },
+        }],
         ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "arm"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
@@ -1179,7 +1185,7 @@
           ],
         },
          ],
-        ['OS=="freebsd"', {
+        ['OS=="freebsd" or OS=="quinnbsd"', {
           'link_settings': {
             'libraries': [
               '-L/usr/local/lib -lexecinfo',
