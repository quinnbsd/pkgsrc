$NetBSD$

--- ./lib/Driver/ToolChains/Arch/PPC.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/ToolChains/Arch/PPC.cpp
@@ -122,7 +122,7 @@ ppc::ReadGOTPtrMode ppc::getPPCReadGOTPt
                                               const ArgList &Args) {
   if (Args.getLastArg(options::OPT_msecure_plt))
     return ppc::ReadGOTPtrMode::SecurePlt;
-  if ((Triple.isOSFreeBSD() && Triple.getOSMajorVersion() >= 13) ||
+  if (((Triple.isOSFreeBSD() || Triple.isOSQuinnBSD()) && Triple.getOSMajorVersion() >= 13) ||
       Triple.isOSNetBSD() || Triple.isOSOpenBSD() || Triple.isMusl())
     return ppc::ReadGOTPtrMode::SecurePlt;
   else
