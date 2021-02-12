$NetBSD$

--- ./lib/Driver/ToolChains/Clang.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/ToolChains/Clang.cpp
@@ -1919,7 +1919,7 @@ void Clang::AddPPCTargetArgs(const ArgLi
         break;
       }
 
-      if (T.isMusl() || (T.isOSFreeBSD() && T.getOSMajorVersion() >= 13))
+      if (T.isMusl() || ((T.isOSFreeBSD() || T.isOSQuinnBSD()) && T.getOSMajorVersion() >= 13))
         ABIName = "elfv2";
       else
         ABIName = "elfv1";
