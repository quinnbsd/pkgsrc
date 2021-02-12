$NetBSD$

--- lib/CodeGen/TargetInfo.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/CodeGen/TargetInfo.cpp
@@ -1966,6 +1966,7 @@ bool X86_32TargetCodeGenInfo::isStructRe
   switch (Triple.getOS()) {
   case llvm::Triple::DragonFly:
   case llvm::Triple::FreeBSD:
+  case llvm::Triple::QuinnBSD:
   case llvm::Triple::OpenBSD:
   case llvm::Triple::Win32:
     return true;
@@ -2172,7 +2173,7 @@ class X86_64ABIInfo : public SwiftABIInf
     const llvm::Triple &Triple = getTarget().getTriple();
     if (Triple.isOSDarwin() || Triple.getOS() == llvm::Triple::PS4)
       return false;
-    if (Triple.isOSFreeBSD() && Triple.getOSMajorVersion() >= 10)
+    if ((Triple.isOSFreeBSD() || Triple.isOSQuinnBSD()) && Triple.getOSMajorVersion() >= 10)
       return false;
     return true;
   }
