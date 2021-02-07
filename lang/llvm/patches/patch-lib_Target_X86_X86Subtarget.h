$NetBSD$

--- lib/Target/X86/X86Subtarget.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Target/X86/X86Subtarget.h
@@ -776,6 +776,7 @@ public:
 
   bool isTargetDarwin() const { return TargetTriple.isOSDarwin(); }
   bool isTargetFreeBSD() const { return TargetTriple.isOSFreeBSD(); }
+  bool isTargetQuinnBSD() const { return TargetTriple.isOSQuinnBSD(); }
   bool isTargetDragonFly() const { return TargetTriple.isOSDragonFly(); }
   bool isTargetSolaris() const { return TargetTriple.isOSSolaris(); }
   bool isTargetPS4() const { return TargetTriple.isPS4CPU(); }
