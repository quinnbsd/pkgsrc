$NetBSD$

--- m4/libuv-check-flags.m4.orig	2020-09-25 00:34:43.000000000 +0000
+++ m4/libuv-check-flags.m4
@@ -111,7 +111,7 @@ AC_DEFUN([CC_NOUNDEFINED], [
      dnl FreeBSD (et al.) does not complete linking for shared objects when pthreads
      dnl are requested, as different implementations are present; to avoid problems
      dnl use -Wl,-z,defs only for those platform not behaving this way.
-     *-freebsd* | *-openbsd*) ;;
+     *-freebsd* | *-openbsd* | *-quinnbsd*) ;;
      *)
         dnl First of all check for the --no-undefined variant of GNU ld. This allows
         dnl for a much more readable commandline, so that people can understand what
