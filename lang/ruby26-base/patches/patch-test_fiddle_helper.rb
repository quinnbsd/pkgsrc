$NetBSD$

--- test/fiddle/helper.rb.orig	2020-03-31 11:23:13.000000000 +0000
+++ test/fiddle/helper.rb
@@ -38,7 +38,7 @@ when /gnu/	#GNU/Hurd
 when /mirbsd/
   libc_so = "/usr/lib/libc.so.41.10"
   libm_so = "/usr/lib/libm.so.7.0"
-when /freebsd/
+when /freebsd|quinnbsd/
   libc_so = "/lib/libc.so.7"
   libm_so = "/lib/libm.so.5"
 when /bsd|dragonfly/
