$NetBSD$

--- lib/Support/Unix/Signals.inc.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Support/Unix/Signals.inc
@@ -431,7 +431,7 @@ void llvm::sys::AddSignalHandler(sys::Si
 
 #if defined(HAVE_BACKTRACE) && ENABLE_BACKTRACES && HAVE_LINK_H &&    \
     (defined(__linux__) || defined(__FreeBSD__) ||                             \
-     defined(__FreeBSD_kernel__) || defined(__NetBSD__))
+     defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__QuinnBSD__))
 struct DlIteratePhdrData {
   void **StackTrace;
   int depth;
