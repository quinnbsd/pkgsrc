$NetBSD$

--- ./lib/Basic/Targets/PPC.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Basic/Targets/PPC.h
@@ -344,6 +344,7 @@ public:
     switch (getTriple().getOS()) {
     case llvm::Triple::Linux:
     case llvm::Triple::FreeBSD:
+    case llvm::Triple::QuinnBSD:
     case llvm::Triple::NetBSD:
       SizeType = UnsignedInt;
       PtrDiffType = SignedInt;
@@ -359,7 +360,7 @@ public:
       break;
     }
 
-    if (Triple.isOSFreeBSD() || Triple.isOSNetBSD() || Triple.isOSOpenBSD() ||
+    if (Triple.isOSFreeBSD() || Triple.isOSNetBSD() || Triple.isOSOpenBSD() || Triple.isOSQuinnBSD() ||
         Triple.getOS() == llvm::Triple::AIX || Triple.isMusl()) {
       LongDoubleWidth = LongDoubleAlign = 64;
       LongDoubleFormat = &llvm::APFloat::IEEEdouble();
@@ -396,7 +397,7 @@ public:
     if (Triple.getOS() == llvm::Triple::AIX)
       SuitableAlign = 64;
 
-    if (Triple.isOSFreeBSD() || Triple.getOS() == llvm::Triple::AIX ||
+    if (Triple.isOSFreeBSD() || Triple.isOSQuinnBSD() || Triple.getOS() == llvm::Triple::AIX ||
         Triple.isMusl()) {
       LongDoubleWidth = LongDoubleAlign = 64;
       LongDoubleFormat = &llvm::APFloat::IEEEdouble();
