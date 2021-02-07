$NetBSD$

--- include/llvm/ADT/Triple.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ include/llvm/ADT/Triple.h
@@ -192,7 +192,8 @@ public:
     Hurd,       // GNU/Hurd
     WASI,       // Experimental WebAssembly OS
     Emscripten,
-    LastOSType = Emscripten
+    QuinnBSD,
+    LastOSType = QuinnBSD
   };
   enum EnvironmentType {
     UnknownEnvironment,
@@ -503,6 +504,10 @@ public:
     return getOS() == Triple::FreeBSD;
   }
 
+  bool isOSQuinnBSD() const {
+    return getOS() == Triple::QuinnBSD;
+  }
+
   bool isOSFuchsia() const {
     return getOS() == Triple::Fuchsia;
   }
