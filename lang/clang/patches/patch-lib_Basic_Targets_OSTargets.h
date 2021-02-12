$NetBSD$

--- lib/Basic/Targets/OSTargets.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Basic/Targets/OSTargets.h
@@ -263,6 +263,66 @@ public:
   }
 };
 
+#ifndef QUINNBSD_CC_VERSION
+#define QUINNBSD_CC_VERSION 0U
+#endif
+
+// QuinnBSD Target
+template <typename Target>
+class LLVM_LIBRARY_VISIBILITY QuinnBSDTargetInfo : public OSTargetInfo<Target> {
+protected:
+  void getOSDefines(const LangOptions &Opts, const llvm::Triple &Triple,
+                    MacroBuilder &Builder) const override {
+    // FreeBSD defines; list based off of gcc output
+
+    unsigned Release = Triple.getOSMajorVersion();
+    if (Release == 0U)
+      Release = 13U;
+    unsigned CCVersion = QUINNBSD_CC_VERSION;
+    if (CCVersion == 0U)
+      CCVersion = Release * 100000U + 1U;
+
+    Builder.defineMacro("__QuinnBSD__", Twine(Release));
+    Builder.defineMacro("__QuinnBSD_cc_version", Twine(CCVersion));
+    Builder.defineMacro("__KPRINTF_ATTRIBUTE__");
+    DefineStd(Builder, "unix", Opts);
+    Builder.defineMacro("__ELF__");
+
+    // On FreeBSD, wchar_t contains the number of the code point as
+    // used by the character set of the locale. These character sets are
+    // not necessarily a superset of ASCII.
+    //
+    // FIXME: This is wrong; the macro refers to the numerical values
+    // of wchar_t *literals*, which are not locale-dependent. However,
+    // FreeBSD systems apparently depend on us getting this wrong, and
+    // setting this to 1 is conforming even if all the basic source
+    // character literals have the same encoding as char and wchar_t.
+    Builder.defineMacro("__STDC_MB_MIGHT_NEQ_WC__", "1");
+  }
+
+public:
+  QuinnBSDTargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
+      : OSTargetInfo<Target>(Triple, Opts) {
+    switch (Triple.getArch()) {
+    default:
+    case llvm::Triple::x86:
+    case llvm::Triple::x86_64:
+      this->MCountName = ".mcount";
+      break;
+    case llvm::Triple::mips:
+    case llvm::Triple::mipsel:
+    case llvm::Triple::ppc:
+    case llvm::Triple::ppc64:
+    case llvm::Triple::ppc64le:
+      this->MCountName = "_mcount";
+      break;
+    case llvm::Triple::arm:
+      this->MCountName = "__mcount";
+      break;
+    }
+  }
+};
+
 // GNU/kFreeBSD Target
 template <typename Target>
 class LLVM_LIBRARY_VISIBILITY KFreeBSDTargetInfo : public OSTargetInfo<Target> {
@@ -436,12 +496,22 @@ protected:
     Builder.defineMacro("__ELF__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
+    if (this->HasFloat128)
+      Builder.defineMacro("__FLOAT128__");
   }
 
 public:
   NetBSDTargetInfo(const llvm::Triple &Triple, const TargetOptions &Opts)
       : OSTargetInfo<Target>(Triple, Opts) {
     this->MCountName = "__mcount";
+    switch (Triple.getArch()) {
+    default:
+      break;
+    case llvm::Triple::x86:
+    case llvm::Triple::x86_64:
+      this->HasFloat128 = true;
+      break;
+    }
   }
 };
 
@@ -615,22 +685,15 @@ protected:
     Builder.defineMacro("__ELF__");
     Builder.defineMacro("__svr4__");
     Builder.defineMacro("__SVR4");
-    // Solaris headers require _XOPEN_SOURCE to be set to 600 for C99 and
-    // newer, but to 500 for everything else.  feature_test.h has a check to
-    // ensure that you are not using C99 with an old version of X/Open or C89
-    // with a new version.
-    if (Opts.C99)
-      Builder.defineMacro("_XOPEN_SOURCE", "600");
-    else
-      Builder.defineMacro("_XOPEN_SOURCE", "500");
+    // Compatibility with GCC to satisfy <sys/feature_tests.h> requirements.
     if (Opts.CPlusPlus) {
-      Builder.defineMacro("__C99FEATURES__");
+      Builder.defineMacro("__STDC_VERSION__", "199901L");
+      Builder.defineMacro("_XOPEN_SOURCE", "600");
       Builder.defineMacro("_FILE_OFFSET_BITS", "64");
+      Builder.defineMacro("_LARGEFILE_SOURCE");
+      Builder.defineMacro("_LARGEFILE64_SOURCE");
+      Builder.defineMacro("__EXTENSIONS__");
     }
-    // GCC restricts the next two to C++.
-    Builder.defineMacro("_LARGEFILE_SOURCE");
-    Builder.defineMacro("_LARGEFILE64_SOURCE");
-    Builder.defineMacro("__EXTENSIONS__");
     if (Opts.POSIXThreads)
       Builder.defineMacro("_REENTRANT");
     if (this->HasFloat128)
