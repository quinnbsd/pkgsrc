$NetBSD$

--- ./lib/Driver/ToolChains/Arch/ARM.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/ToolChains/Arch/ARM.cpp
@@ -225,6 +225,7 @@ arm::FloatABI arm::getARMFloatABI(const
       break;
 
     case llvm::Triple::FreeBSD:
+    case llvm::Triple::QuinnBSD:
       switch (Triple.getEnvironment()) {
       case llvm::Triple::GNUEABIHF:
         ABI = FloatABI::Hard;
