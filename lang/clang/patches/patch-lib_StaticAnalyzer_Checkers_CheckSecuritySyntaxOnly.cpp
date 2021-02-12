$NetBSD$

--- ./lib/StaticAnalyzer/Checkers/CheckSecuritySyntaxOnly.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/StaticAnalyzer/Checkers/CheckSecuritySyntaxOnly.cpp
@@ -29,6 +29,7 @@ static bool isArc4RandomAvailable(const
   return T.getVendor() == llvm::Triple::Apple ||
          T.getOS() == llvm::Triple::CloudABI ||
          T.isOSFreeBSD() ||
+         T.isOSQuinnBSD() ||
          T.isOSNetBSD() ||
          T.isOSOpenBSD() ||
          T.isOSDragonFly();
