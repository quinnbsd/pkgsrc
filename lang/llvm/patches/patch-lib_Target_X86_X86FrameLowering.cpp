$NetBSD$

--- lib/Target/X86/X86FrameLowering.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Target/X86/X86FrameLowering.cpp
@@ -2302,7 +2302,7 @@ void X86FrameLowering::adjustForSegmente
     report_fatal_error("Segmented stacks do not support vararg functions.");
   if (!STI.isTargetLinux() && !STI.isTargetDarwin() && !STI.isTargetWin32() &&
       !STI.isTargetWin64() && !STI.isTargetFreeBSD() &&
-      !STI.isTargetDragonFly())
+      !STI.isTargetDragonFly() && !STI.isTargetQuinnBSD())
     report_fatal_error("Segmented stacks not supported on this platform.");
 
   // Eventually StackSize will be calculated by a link-time pass; which will
@@ -2360,7 +2360,7 @@ void X86FrameLowering::adjustForSegmente
     } else if (STI.isTargetWin64()) {
       TlsReg = X86::GS;
       TlsOffset = 0x28; // pvArbitrary, reserved for application use
-    } else if (STI.isTargetFreeBSD()) {
+    } else if (STI.isTargetFreeBSD() || STI.isTargetQuinnBSD()) {
       TlsReg = X86::FS;
       TlsOffset = 0x18;
     } else if (STI.isTargetDragonFly()) {
@@ -2391,7 +2391,7 @@ void X86FrameLowering::adjustForSegmente
     } else if (STI.isTargetDragonFly()) {
       TlsReg = X86::FS;
       TlsOffset = 0x10; // use tls_tcb.tcb_segstack
-    } else if (STI.isTargetFreeBSD()) {
+    } else if (STI.isTargetFreeBSD() || STI.isTargetQuinnBSD()) {
       report_fatal_error("Segmented stacks not supported on FreeBSD i386.");
     } else {
       report_fatal_error("Segmented stacks not supported on this platform.");
