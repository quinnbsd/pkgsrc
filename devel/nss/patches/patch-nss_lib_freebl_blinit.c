$NetBSD$

--- nss/lib/freebl/blinit.c.orig	2021-01-22 17:08:28.000000000 +0000
+++ nss/lib/freebl/blinit.c
@@ -146,7 +146,7 @@ extern unsigned long getauxval(unsigned
 static unsigned long (*getauxval)(unsigned long) = NULL;
 #endif /* defined(__GNUC__) && __GNUC__ >= 2 && defined(__ELF__)*/
 
-#if defined(__FreeBSD__) && !defined(__aarch64__) && __has_include(<sys/auxv.h>)
+#if (defined(__FreeBSD__) || defined(__QuinnBSD__)) && !defined(__aarch64__) && __has_include(<sys/auxv.h>)
 /* Avoid conflict with static declaration above */
 #define getauxval freebl_getauxval
 static unsigned long getauxval(unsigned long type)
@@ -190,7 +190,7 @@ static unsigned long getauxval(unsigned
 #endif
 #endif /* defined(__linux__) */
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <stdint.h>
 #include <machine/armreg.h>
 // Support for older version of armreg.h
@@ -222,7 +222,7 @@ CheckARMSupport()
         arm_sha1_support_ = (hwcaps & HWCAP_SHA1) == HWCAP_SHA1;
         arm_sha2_support_ = (hwcaps & HWCAP_SHA2) == HWCAP_SHA2;
     }
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     /* qemu-user does not support register access from userspace */
     if (PR_GetEnvSecure("QEMU_EMULATING") == NULL) {
         uint64_t isar0 = READ_SPECIALREG(id_aa64isar0_el1);
@@ -483,7 +483,7 @@ ppc_crypto_support()
 #endif
 
 /* clang-format off */
-#if defined(__linux__) || (defined(__FreeBSD__) && __FreeBSD__ >= 12)
+#if defined(__linux__) || (defined(__FreeBSD__) && __FreeBSD__ >= 12) || defined(__QuinnBSD__)
 #if __has_include(<sys/auxv.h>)
 #include <sys/auxv.h>
 #endif
@@ -506,8 +506,8 @@ CheckPPCSupport()
 #if __has_include(<sys/auxv.h>)
     hwcaps = getauxval(AT_HWCAP2);
 #endif
-#elif defined(__FreeBSD__)
-#if __FreeBSD__ >= 12
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
+#if __FreeBSD__ >= 12 || defined(__QuinnBSD__)
 #if __has_include(<sys/auxv.h>)
     elf_aux_info(AT_HWCAP2, &hwcaps, sizeof(hwcaps));
 #endif
