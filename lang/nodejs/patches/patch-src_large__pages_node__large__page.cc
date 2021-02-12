$NetBSD$

--- src/large_pages/node_large_page.cc.orig	2021-01-04 13:59:34.000000000 +0000
+++ src/large_pages/node_large_page.cc
@@ -63,12 +63,12 @@
 #if defined(NODE_ENABLE_LARGE_CODE_PAGES) && NODE_ENABLE_LARGE_CODE_PAGES
 #include "debug_utils-inl.h"
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 #if defined(__linux__)
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif  // ifndef _GNU_SOURCE
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include "uv.h"  // uv_exepath
 #endif  // defined(__linux__)
 #include <link.h>
@@ -76,7 +76,7 @@
 
 #include <sys/types.h>
 #include <sys/mman.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/sysctl.h>
 #elif defined(__APPLE__)
 #include <mach/vm_map.h>
@@ -89,7 +89,7 @@
 #include <string>
 #include <fstream>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
 extern "C" {
 // This symbol must be declared weak because this file becomes part of all
 // Node.js targets (like node_mksnapshot, node_mkcodecache, and cctest) and
@@ -137,8 +137,8 @@ inline uintptr_t hugepage_align_down(uin
   return ((addr) & ~((hps) - 1));
 }
 
-#if defined(__linux__) || defined(__FreeBSD__)
-#if defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #ifndef ElfW
 #define ElfW(name) Elf_##name
 #endif  // ifndef ElfW
@@ -175,11 +175,11 @@ int FindMapping(struct dl_phdr_info* inf
 
 struct text_region FindNodeTextRegion() {
   struct text_region nregion;
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
   dl_iterate_params dl_params;
   uintptr_t lpstub_start = reinterpret_cast<uintptr_t>(&__start_lpstub);
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
   // On FreeBSD we need the name of the binary, because `dl_iterate_phdr` does
   // not pass in an empty string as the `dlpi_name` of the binary but rather its
   // absolute path.
@@ -274,7 +274,7 @@ bool IsTransparentHugePagesEnabled() {
 
   return always == "[always]" || madvise == "[madvise]";
 }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 bool IsSuperPagesEnabled() {
   // It is enabled by default on amd64.
   unsigned int super_pages = 0;
@@ -357,7 +357,7 @@ MoveTextRegionToLargePages(const text_re
   if (tmem.mem() == MAP_FAILED) goto fail;
   if (madvise(tmem.mem(), size, 14 /* MADV_HUGEPAGE */) == -1) goto fail;
   memcpy(start, nmem.mem(), size);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
   tmem.Reset(start, size,
              PROT_READ | PROT_WRITE | PROT_EXEC,
              MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED |
@@ -398,7 +398,7 @@ int MapStaticCodeToLargePages() {
   bool have_thp = false;
 #if defined(__linux__)
   have_thp = IsTransparentHugePagesEnabled();
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
   have_thp = IsSuperPagesEnabled();
 #elif defined(__APPLE__)
   // pse-36 flag is present in recent mac x64 products.
