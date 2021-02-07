$NetBSD$

--- lib/Support/Triple.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Support/Triple.cpp
@@ -192,6 +192,7 @@ StringRef Triple::getOSTypeName(OSType K
   case ELFIAMCU: return "elfiamcu";
   case Emscripten: return "emscripten";
   case FreeBSD: return "freebsd";
+  case QuinnBSD: return "quinnbsd";
   case Fuchsia: return "fuchsia";
   case Haiku: return "haiku";
   case HermitCore: return "hermit";
@@ -489,6 +490,7 @@ static Triple::OSType parseOS(StringRef
     .StartsWith("darwin", Triple::Darwin)
     .StartsWith("dragonfly", Triple::DragonFly)
     .StartsWith("freebsd", Triple::FreeBSD)
+    .StartsWith("quinnbsd", Triple::QuinnBSD)
     .StartsWith("fuchsia", Triple::Fuchsia)
     .StartsWith("ios", Triple::IOS)
     .StartsWith("kfreebsd", Triple::KFreeBSD)
@@ -1609,6 +1611,7 @@ StringRef Triple::getARMCPUForArch(Strin
 
   // Some defaults are forced.
   switch (getOS()) {
+  case llvm::Triple::QuinnBSD:
   case llvm::Triple::FreeBSD:
   case llvm::Triple::NetBSD:
     if (!MArch.empty() && MArch == "v6")
