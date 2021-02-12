$NetBSD$

--- ./lib/Basic/Targets.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Basic/Targets.cpp
@@ -136,6 +136,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new CloudABITargetInfo<AArch64leTargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<AArch64leTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<AArch64leTargetInfo>(Triple, Opts);
     case llvm::Triple::Fuchsia:
       return new FuchsiaTargetInfo<AArch64leTargetInfo>(Triple, Opts);
     case llvm::Triple::Linux:
@@ -160,6 +162,8 @@ TargetInfo *AllocateTarget(const llvm::T
     switch (os) {
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<AArch64beTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<AArch64beTargetInfo>(Triple, Opts);
     case llvm::Triple::Fuchsia:
       return new FuchsiaTargetInfo<AArch64beTargetInfo>(Triple, Opts);
     case llvm::Triple::Linux:
@@ -182,6 +186,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new LinuxTargetInfo<ARMleTargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<ARMleTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<ARMleTargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<ARMleTargetInfo>(Triple, Opts);
     case llvm::Triple::OpenBSD:
@@ -216,6 +222,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new LinuxTargetInfo<ARMbeTargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<ARMbeTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<ARMbeTargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<ARMbeTargetInfo>(Triple, Opts);
     case llvm::Triple::OpenBSD:
@@ -245,6 +253,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new RTEMSTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     default:
@@ -259,6 +269,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new RTEMSTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::NaCl:
@@ -275,6 +287,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new RTEMSTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::OpenBSD:
@@ -291,6 +305,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new RTEMSTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<MipsTargetInfo>(Triple, Opts);
     case llvm::Triple::OpenBSD:
@@ -318,6 +334,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new LinuxTargetInfo<PPC32TargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<PPC32TargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<PPC32TargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<PPC32TargetInfo>(Triple, Opts);
     case llvm::Triple::OpenBSD:
@@ -340,6 +358,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new PS3PPUTargetInfo<PPC64TargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     case llvm::Triple::NetBSD:
       return new NetBSDTargetInfo<PPC64TargetInfo>(Triple, Opts);
     case llvm::Triple::AIX:
@@ -372,6 +392,8 @@ TargetInfo *AllocateTarget(const llvm::T
     switch (os) {
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<RISCV32TargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<RISCV32TargetInfo>(Triple, Opts);
     case llvm::Triple::Linux:
       return new LinuxTargetInfo<RISCV32TargetInfo>(Triple, Opts);
     default:
@@ -383,6 +405,8 @@ TargetInfo *AllocateTarget(const llvm::T
     switch (os) {
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<RISCV64TargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<RISCV64TargetInfo>(Triple, Opts);
     case llvm::Triple::Fuchsia:
       return new FuchsiaTargetInfo<RISCV64TargetInfo>(Triple, Opts);
     case llvm::Triple::Linux:
@@ -434,6 +458,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new OpenBSDTargetInfo<SparcV9TargetInfo>(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<SparcV9TargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<SparcV9TargetInfo>(Triple, Opts);
     default:
       return new SparcV9TargetInfo(Triple, Opts);
     }
@@ -477,6 +503,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new OpenBSDI386TargetInfo(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<X86_32TargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<X86_32TargetInfo>(Triple, Opts);
     case llvm::Triple::KFreeBSD:
       return new KFreeBSDTargetInfo<X86_32TargetInfo>(Triple, Opts);
     case llvm::Triple::Minix:
@@ -534,6 +562,8 @@ TargetInfo *AllocateTarget(const llvm::T
       return new OpenBSDX86_64TargetInfo(Triple, Opts);
     case llvm::Triple::FreeBSD:
       return new FreeBSDTargetInfo<X86_64TargetInfo>(Triple, Opts);
+    case llvm::Triple::QuinnBSD:
+      return new QuinnBSDTargetInfo<X86_64TargetInfo>(Triple, Opts);
     case llvm::Triple::Fuchsia:
       return new FuchsiaTargetInfo<X86_64TargetInfo>(Triple, Opts);
     case llvm::Triple::KFreeBSD:
