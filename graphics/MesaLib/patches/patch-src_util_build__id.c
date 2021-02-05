$NetBSD$

--- src/util/build_id.c.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/util/build_id.c
@@ -35,7 +35,15 @@
 #endif
 
 #ifndef ElfW
-#define ElfW(type) Elf_##type
+# if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+#  ifdef __LP64__
+#    define ElfW(type) Elf64_##type
+#  else
+#    define ElfW(type) Elf32_##type
+#  endif /* __LP64__ */
+#  else
+#    define ElfW(type) Elf_##type
+#  endif
 #endif
 
 struct build_id_note {
