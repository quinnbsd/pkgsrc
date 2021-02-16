$NetBSD$

--- ./boost/test/impl/execution_monitor.ipp.orig	2020-12-03 05:02:32.000000000 +0000
+++ ./boost/test/impl/execution_monitor.ipp
@@ -137,7 +137,7 @@ namespace { void _set_se_translator( voi
 #  include <signal.h>
 #  include <setjmp.h>
 
-#  if defined(__FreeBSD__)
+#  if defined(__FreeBSD__) || defined(__QuinnBSD__)
 
 #    include <osreldate.h>
 
@@ -171,7 +171,8 @@ namespace { void _set_se_translator( voi
 #  if defined(SIGPOLL) && !defined(__CYGWIN__)                              && \
       !(defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__))  && \
       !defined(__NetBSD__)                                                  && \
-      !defined(__QNXNTO__)
+      !defined(__QNXNTO__)                                                  && \
+      !defined(__DragonFly__)
 #    define BOOST_TEST_CATCH_SIGPOLL
 #  endif
 
