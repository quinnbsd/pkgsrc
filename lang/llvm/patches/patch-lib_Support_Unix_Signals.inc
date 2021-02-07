$NetBSD$

--- lib/Support/Unix/Signals.inc.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Support/Unix/Signals.inc
@@ -462,7 +462,7 @@ void llvm::sys::AddSignalHandler(sys::Si
 
 #if defined(HAVE_BACKTRACE) && ENABLE_BACKTRACES && HAVE_LINK_H &&    \
     (defined(__linux__) || defined(__FreeBSD__) ||                             \
-     defined(__FreeBSD_kernel__) || defined(__NetBSD__))
+     defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__QuinnBSD__))
 struct DlIteratePhdrData {
   void **StackTrace;
   int depth;
