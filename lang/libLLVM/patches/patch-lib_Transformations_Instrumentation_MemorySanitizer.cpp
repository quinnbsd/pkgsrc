$NetBSD$

--- lib/Transforms/Instrumentation/MemorySanitizer.cpp.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Transforms/Instrumentation/MemorySanitizer.cpp
@@ -860,6 +860,7 @@ void MemorySanitizer::initializeModule(M
     Triple TargetTriple(M.getTargetTriple());
     switch (TargetTriple.getOS()) {
       case Triple::FreeBSD:
+      case Triple::QuinnBSD:
         switch (TargetTriple.getArch()) {
           case Triple::x86_64:
             MapParams = FreeBSD_X86_MemoryMapParams.bits64;
