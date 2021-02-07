$NetBSD$

--- lib/Transforms/Instrumentation/MemorySanitizer.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Transforms/Instrumentation/MemorySanitizer.cpp
@@ -888,6 +888,7 @@ void MemorySanitizer::initializeModule(M
     Triple TargetTriple(M.getTargetTriple());
     switch (TargetTriple.getOS()) {
       case Triple::FreeBSD:
+      case Triple::QuinnBSD:
         switch (TargetTriple.getArch()) {
           case Triple::x86_64:
             MapParams = FreeBSD_X86_MemoryMapParams.bits64;
