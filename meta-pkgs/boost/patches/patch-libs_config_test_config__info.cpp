$NetBSD$

--- ./libs/config/test/config_info.cpp.orig	2020-12-03 05:01:13.000000000 +0000
+++ ./libs/config/test/config_info.cpp
@@ -207,6 +207,8 @@ void print_compiler_macros()
   PRINT_MACRO(__EXCEPTIONS);
   PRINT_MACRO(__FreeBSD__);
   PRINT_MACRO(__FreeBSD_cc_version);
+  PRINT_MACRO(__QuinnBSD__);
+  PRINT_MACRO(__QuinnBSD_cc_version);
   PRINT_MACRO(__ELF__);
   PRINT_MACRO(__GNUPRO__);
   PRINT_MACRO(unix);
