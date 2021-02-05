$NetBSD$

--- include/llvm/ADT/Triple.h.orig	2019-12-11 19:15:30.000000000 +0000
+++ include/llvm/ADT/Triple.h
@@ -189,7 +189,8 @@ public:
     Hurd,       // GNU/Hurd
     WASI,       // Experimental WebAssembly OS
     Emscripten,
-    LastOSType = Emscripten
+    QuinnBSD,
+    LastOSType = QuinnBSD
   };
   enum EnvironmentType {
     UnknownEnvironment,
@@ -501,6 +502,9 @@ public:
   bool isOSFreeBSD() const {
     return getOS() == Triple::FreeBSD;
   }
+  bool isOSQuinnBSD() const {
+    return getOS() == Triple::QuinnBSD;
+  }
 
   bool isOSFuchsia() const {
     return getOS() == Triple::Fuchsia;
