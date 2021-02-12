$NetBSD$

--- ./lib/Driver/ToolChain.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/ToolChain.cpp
@@ -373,6 +373,8 @@ StringRef ToolChain::getOSLibName() cons
     return "openbsd";
   case llvm::Triple::Solaris:
     return "sunos";
+  case llvm::Triple::QuinnBSD:
+    return "quinnbsd";
   default:
     return getOS();
   }
@@ -534,6 +536,8 @@ std::string ToolChain::GetLinkerPath() c
     llvm::SmallString<8> LinkerName;
     if (Triple.isOSDarwin())
       LinkerName.append("ld64.");
+    else if (Triple.isOSNetBSD())
+      LinkerName.append("nb.");
     else
       LinkerName.append("ld.");
     LinkerName.append(UseLinker);
