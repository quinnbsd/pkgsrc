$NetBSD$

--- ./lib/Driver/ToolChains/Arch/Mips.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/ToolChains/Arch/Mips.cpp
@@ -51,7 +51,7 @@ void mips::getMipsCPUAndABI(const ArgLis
 
   // MIPS2 is the default for mips(el)?-unknown-freebsd.
   // MIPS3 is the default for mips64(el)?-unknown-freebsd.
-  if (Triple.isOSFreeBSD()) {
+  if (Triple.isOSFreeBSD() || Triple.isOSQuinnBSD()) {
     DefMips32CPU = "mips2";
     DefMips64CPU = "mips3";
   }
@@ -173,7 +173,7 @@ mips::FloatABI mips::getMipsFloatABI(con
 
   // If unspecified, choose the default based on the platform.
   if (ABI == mips::FloatABI::Invalid) {
-    if (Triple.isOSFreeBSD()) {
+    if (Triple.isOSFreeBSD() || Triple.isOSQuinnBSD()) {
       // For FreeBSD, assume "soft" on all flavors of MIPS.
       ABI = mips::FloatABI::Soft;
     } else {
