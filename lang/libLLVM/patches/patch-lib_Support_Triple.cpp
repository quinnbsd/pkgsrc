$NetBSD$

--- lib/Support/Triple.cpp.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Support/Triple.cpp
@@ -181,6 +181,7 @@ StringRef Triple::getOSTypeName(OSType K
   case Darwin: return "darwin";
   case DragonFly: return "dragonfly";
   case FreeBSD: return "freebsd";
+  case QuinnBSD: return "quinnbsd";
   case Fuchsia: return "fuchsia";
   case IOS: return "ios";
   case KFreeBSD: return "kfreebsd";
@@ -486,6 +487,7 @@ static Triple::OSType parseOS(StringRef
     .StartsWith("darwin", Triple::Darwin)
     .StartsWith("dragonfly", Triple::DragonFly)
     .StartsWith("freebsd", Triple::FreeBSD)
+    .StartsWith("quinnbsd", Triple::QuinnBSD)
     .StartsWith("fuchsia", Triple::Fuchsia)
     .StartsWith("ios", Triple::IOS)
     .StartsWith("kfreebsd", Triple::KFreeBSD)
@@ -1600,6 +1602,7 @@ StringRef Triple::getARMCPUForArch(Strin
   // Some defaults are forced.
   switch (getOS()) {
   case llvm::Triple::FreeBSD:
+  case llvm::Triple::QuinnBSD:
   case llvm::Triple::NetBSD:
     if (!MArch.empty() && MArch == "v6")
       return "arm1176jzf-s";
