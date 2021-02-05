$NetBSD$

--- src/gallium/state_trackers/clover/llvm/invocation.cpp.orig	2020-04-29 22:48:24.000000000 +0000
+++ src/gallium/state_trackers/clover/llvm/invocation.cpp
@@ -188,6 +188,10 @@ namespace {
       return get_lang_standard_from_version_str(device_version);
    }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+   const char* cstr(const std::string& str) { return str.c_str(); }
+#endif
+
    std::unique_ptr<clang::CompilerInstance>
    create_compiler_instance(const device &dev, const std::string& ir_target,
                             const std::vector<std::string> &opts,
@@ -200,9 +204,13 @@ namespace {
       // Parse the compiler options.  A file name should be present at the end
       // and must have the .cl extension in order for the CompilerInvocation
       // class to recognize it as an OpenCL source file.
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+      std::vector<const char *> copts(opts.size());
+      std::transform(opts.begin(), opts.end(), copts.begin(), cstr);
+#else
       const std::vector<const char *> copts =
          map(std::mem_fn(&std::string::c_str), opts);
-
+#endif
       const target &target = ir_target;
       const std::string &device_clc_version = dev.device_clc_version();
 
