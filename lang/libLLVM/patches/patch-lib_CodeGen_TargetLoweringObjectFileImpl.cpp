$NetBSD$

--- lib/CodeGen/TargetLoweringObjectFileImpl.cpp.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/CodeGen/TargetLoweringObjectFileImpl.cpp
@@ -192,7 +192,7 @@ void TargetLoweringObjectFileELF::Initia
     // FreeBSD must be explicit about the data size and using pcrel since it's
     // assembler/linker won't do the automatic conversion that the Linux tools
     // do.
-    if (TgtM.getTargetTriple().isOSFreeBSD()) {
+    if (TgtM.getTargetTriple().isOSFreeBSD() || TgtM.getTargetTriple().isOSQuinnBSD()) {
       PersonalityEncoding |= dwarf::DW_EH_PE_pcrel | dwarf::DW_EH_PE_sdata4;
       LSDAEncoding = dwarf::DW_EH_PE_pcrel | dwarf::DW_EH_PE_sdata4;
     }
