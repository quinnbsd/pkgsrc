$NetBSD$

--- lib/Target/X86/X86TargetMachine.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Target/X86/X86TargetMachine.cpp
@@ -94,7 +94,7 @@ static std::unique_ptr<TargetLoweringObj
     return std::make_unique<TargetLoweringObjectFileMachO>();
   }
 
-  if (TT.isOSFreeBSD())
+  if (TT.isOSFreeBSD() || TT.isOSQuinnBSD())
     return std::make_unique<X86FreeBSDTargetObjectFile>();
   if (TT.isOSLinux() || TT.isOSNaCl() || TT.isOSIAMCU())
     return std::make_unique<X86LinuxNaClTargetObjectFile>();
