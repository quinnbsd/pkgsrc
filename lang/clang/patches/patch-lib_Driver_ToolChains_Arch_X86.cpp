$NetBSD$

--- ./lib/Driver/ToolChains/Arch/X86.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/ToolChains/Arch/X86.cpp
@@ -94,6 +94,7 @@ const char *x86::getX86TargetCPU(const A
 
   switch (Triple.getOS()) {
   case llvm::Triple::FreeBSD:
+  case llvm::Triple::QuinnBSD:
   case llvm::Triple::NetBSD:
   case llvm::Triple::OpenBSD:
     return "i486";
