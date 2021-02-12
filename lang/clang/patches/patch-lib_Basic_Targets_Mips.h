$NetBSD$

--- lib/Basic/Targets/Mips.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Basic/Targets/Mips.h
@@ -78,6 +78,7 @@ public:
     CPU = ABI == "o32" ? "mips32r2" : "mips64r2";
 
     CanUseBSDABICalls = Triple.isOSFreeBSD() ||
+			Triple.isOSQuinnBSD() ||
                         Triple.isOSOpenBSD();
   }
 
@@ -131,7 +132,7 @@ public:
   void setN32N64ABITypes() {
     LongDoubleWidth = LongDoubleAlign = 128;
     LongDoubleFormat = &llvm::APFloat::IEEEquad();
-    if (getTriple().isOSFreeBSD()) {
+    if (getTriple().isOSFreeBSD() || getTriple().isOSQuinnBSD()) {
       LongDoubleWidth = LongDoubleAlign = 64;
       LongDoubleFormat = &llvm::APFloat::IEEEdouble();
     }
