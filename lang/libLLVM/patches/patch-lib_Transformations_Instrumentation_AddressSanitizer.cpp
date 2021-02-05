$NetBSD$

--- lib/Transforms/Instrumentation/AddressSanitizer.cpp.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Transforms/Instrumentation/AddressSanitizer.cpp
@@ -420,6 +420,7 @@ static ShadowMapping getShadowMapping(Tr
   bool IsAndroid = TargetTriple.isAndroid();
   bool IsIOS = TargetTriple.isiOS() || TargetTriple.isWatchOS();
   bool IsFreeBSD = TargetTriple.isOSFreeBSD();
+  bool IsQuinnBSD = TargetTriple.isOSQuinnBSD();
   bool IsNetBSD = TargetTriple.isOSNetBSD();
   bool IsPS4CPU = TargetTriple.isPS4CPU();
   bool IsLinux = TargetTriple.isOSLinux();
@@ -448,7 +449,7 @@ static ShadowMapping getShadowMapping(Tr
       Mapping.Offset = kDynamicShadowSentinel;
     else if (IsMIPS32)
       Mapping.Offset = kMIPS32_ShadowOffset32;
-    else if (IsFreeBSD)
+    else if (IsFreeBSD || IsQuinnBSD)
       Mapping.Offset = kFreeBSD_ShadowOffset32;
     else if (IsNetBSD)
       Mapping.Offset = kNetBSD_ShadowOffset32;
@@ -474,7 +475,7 @@ static ShadowMapping getShadowMapping(Tr
       Mapping.Offset = kPPC64_ShadowOffset64;
     else if (IsSystemZ)
       Mapping.Offset = kSystemZ_ShadowOffset64;
-    else if (IsFreeBSD && !IsMIPS64)
+    else if ((IsFreeBSD || IsQuinnBSD) && !IsMIPS64)
       Mapping.Offset = kFreeBSD_ShadowOffset64;
     else if (IsNetBSD) {
       if (IsKasan)
