$NetBSD$

--- lib/Transforms/Instrumentation/InstrProfiling.cpp.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Transforms/Instrumentation/InstrProfiling.cpp
@@ -714,7 +714,7 @@ static bool needsRuntimeRegistrationOfSe
   // Use linker script magic to get data/cnts/name start/end.
   if (TT.isOSLinux() || TT.isOSFreeBSD() || TT.isOSNetBSD() ||
       TT.isOSSolaris() || TT.isOSFuchsia() || TT.isPS4CPU() ||
-      TT.isOSWindows())
+      TT.isOSWindows() || TT.isOSQuinnBSD())
     return false;
 
   return true;
