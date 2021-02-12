$NetBSD$

--- ./lib/Driver/ToolChains/CommonArgs.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/ToolChains/CommonArgs.cpp
@@ -598,11 +598,12 @@ void tools::linkSanitizerRuntimeDeps(con
   if (!TC.getTriple().isOSFreeBSD() &&
       !TC.getTriple().isOSNetBSD() &&
       !TC.getTriple().isOSOpenBSD() &&
+      !TC.getTriple().isOSQuinnBSD() &&
        TC.getTriple().getOS() != llvm::Triple::RTEMS)
     CmdArgs.push_back("-ldl");
   // Required for backtrace on some OSes
   if (TC.getTriple().isOSFreeBSD() ||
-      TC.getTriple().isOSNetBSD())
+      TC.getTriple().isOSNetBSD() || TC.getTriple().isOSQuinnBSD())
     CmdArgs.push_back("-lexecinfo");
 }
 
@@ -781,6 +782,7 @@ void tools::linkXRayRuntimeDeps(const To
 
   if (!TC.getTriple().isOSFreeBSD() &&
       !TC.getTriple().isOSNetBSD() &&
+      !TC.getTriple().isOSQuinnBSD() &&
       !TC.getTriple().isOSOpenBSD())
     CmdArgs.push_back("-ldl");
 }
