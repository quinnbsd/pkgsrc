$NetBSD$

--- ./lib/StaticAnalyzer/Checkers/MallocChecker.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/StaticAnalyzer/Checkers/MallocChecker.cpp
@@ -985,7 +985,7 @@ llvm::Optional<ProgramStateRef> MallocCh
   llvm::Triple::OSType OS = Ctx.getTargetInfo().getTriple().getOS();
 
   if (!KernelZeroFlagVal.hasValue()) {
-    if (OS == llvm::Triple::FreeBSD)
+    if (OS == llvm::Triple::FreeBSD || OS == llvm::Triple::QuinnBSD)
       KernelZeroFlagVal = 0x0100;
     else if (OS == llvm::Triple::NetBSD)
       KernelZeroFlagVal = 0x0002;
