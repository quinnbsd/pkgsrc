$NetBSD$

--- lib/rubygems/platform.rb.orig	2020-03-31 11:23:13.000000000 +0000
+++ lib/rubygems/platform.rb
@@ -61,12 +61,7 @@ class Gem::Platform
         arch.last << "-#{extra}"
       end
 
-      cpu = arch.shift
-
-      @cpu = case cpu
-             when /i\d86/ then 'x86'
-             else cpu
-             end
+      @cpu = arch.shift
 
       if arch.length == 2 and arch.last =~ /^\d+(\.\d+)?$/  # for command-line
         @os, @version = arch
@@ -82,6 +77,7 @@ class Gem::Platform
                       when /darwin(\d+)?/ then          [ 'darwin',    $1  ]
                       when /^macruby$/ then             [ 'macruby',   nil ]
                       when /freebsd(\d+)?/ then         [ 'freebsd',   $1  ]
+                      when /quinnbsd(\d+)?/ then        [ 'freebsd',   $1  ]
                       when /hpux(\d+)?/ then            [ 'hpux',      $1  ]
                       when /^java$/, /^jruby$/ then     [ 'java',      nil ]
                       when /^java([\d.]*)/ then         [ 'java',      $1  ]
@@ -95,6 +91,7 @@ class Gem::Platform
                         @cpu = 'x86' if @cpu.nil? and os =~ /32$/
                         [os, version]
                       when /netbsdelf/ then             [ 'netbsdelf', nil ]
+                      when /netbsd/ then                [ 'netbsd',    nil ]
                       when /openbsd(\d+\.\d+)?/ then    [ 'openbsd',   $1  ]
                       when /bitrig(\d+\.\d+)?/ then     [ 'bitrig',    $1  ]
                       when /solaris(\d+\.\d+)?/ then    [ 'solaris',   $1  ]
