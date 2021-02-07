$NetBSD$

--- lib/Target/PowerPC/PPCSubtarget.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Target/PowerPC/PPCSubtarget.cpp
@@ -150,7 +150,7 @@ void PPCSubtarget::initSubtargetFeatures
 
   if ((TargetTriple.isOSFreeBSD() && TargetTriple.getOSMajorVersion() >= 13) ||
       TargetTriple.isOSNetBSD() || TargetTriple.isOSOpenBSD() ||
-      TargetTriple.isMusl())
+      TargetTriple.isMusl() || TargetTriple.isOSQuinnBSD())
     SecurePlt = true;
 
   if (HasSPE && IsPPC64)
