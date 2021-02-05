$NetBSD$

--- tools/llvm-objcopy/CopyConfig.cpp.orig	2019-12-11 19:15:30.000000000 +0000
+++ tools/llvm-objcopy/CopyConfig.cpp
@@ -321,6 +321,10 @@ static Expected<TargetInfo>
 getOutputTargetInfoByTargetName(StringRef TargetName) {
   StringRef OriginalTargetName = TargetName;
   bool IsFreeBSD = TargetName.consume_back("-freebsd");
+  if (!IsFreeBSD) {
+    TargetName = OriginalTargetName;
+    IsFreeBSD = TargetName.consume_back("-quinnbsd");
+  }
   auto Iter = TargetMap.find(TargetName);
   if (Iter == std::end(TargetMap))
     return createStringError(errc::invalid_argument,
