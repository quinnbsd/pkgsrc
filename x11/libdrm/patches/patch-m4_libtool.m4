$NetBSD$

--- m4/libtool.m4.orig	2019-10-16 21:36:51.000000000 +0000
+++ m4/libtool.m4
@@ -1727,7 +1727,7 @@ AC_CACHE_VAL([lt_cv_sys_max_cmd_len], [d
     lt_cv_sys_max_cmd_len=8192;
     ;;
 
-  bitrig* | darwin* | dragonfly* | freebsd* | netbsd* | openbsd*)
+  bitrig* | darwin* | dragonfly* | freebsd* | netbsd* | openbsd* | quinnbsd*)
     # This has been around since 386BSD, at least.  Likely further.
     if test -x /sbin/sysctl; then
       lt_cv_sys_max_cmd_len=`/sbin/sysctl -n kern.argmax`
@@ -2235,7 +2235,7 @@ else
       old_striplib="$STRIP -S"
       AC_MSG_RESULT([yes])
       ;;
-    freebsd*)
+    freebsd* | quinnbsd*)
       if $STRIP -V 2>&1 | $GREP "elftoolchain" >/dev/null; then
         old_striplib="$STRIP --strip-debug"
         striplib="$STRIP --strip-unneeded"
@@ -2677,7 +2677,7 @@ dgux*)
   shlibpath_var=LD_LIBRARY_PATH
   ;;
 
-freebsd* | dragonfly*)
+freebsd* | dragonfly* | quinnbsd*)
   # DragonFly does not have aout.  When/if they implement a new
   # versioning mechanism, adjust this.
   if test -x /usr/bin/objformat; then
@@ -3510,7 +3510,7 @@ darwin* | rhapsody*)
   lt_cv_deplibs_check_method=pass_all
   ;;
 
-freebsd* | dragonfly*)
+freebsd* | dragonfly* | quinnbsd*)
   if echo __ELF__ | $CC -E - | $GREP __ELF__ > /dev/null; then
     case $host_cpu in
     i*86 )
@@ -4339,7 +4339,7 @@ m4_if([$1], [CXX], [
 	    ;;
 	esac
 	;;
-      freebsd* | dragonfly*)
+      freebsd* | dragonfly* | quinnbsd*)
 	# FreeBSD uses GNU C++
 	;;
       hpux9* | hpux10* | hpux11*)
@@ -6785,7 +6785,7 @@ if test yes != "$_lt_caught_CXX_error";
         _LT_TAGVAR(archive_cmds_need_lc, $1)=no
         ;;
 
-      freebsd* | dragonfly*)
+      freebsd* | dragonfly* | quinnbsd*)
         # FreeBSD 3 and later use GNU C++ and GNU ld with standard ELF
         # conventions
         _LT_TAGVAR(ld_shlibs, $1)=yes
