$NetBSD$

--- lib/Support/Unix/Memory.inc.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Support/Unix/Memory.inc
@@ -31,7 +31,7 @@
 #if defined(__mips__)
 #  if defined(__OpenBSD__)
 #    include <mips64/sysarch.h>
-#  elif !defined(__FreeBSD__)
+#  elif !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 #    include <sys/cachectl.h>
 #  endif
 #endif
@@ -59,7 +59,7 @@ int getPosixProtectionFlags(unsigned Fla
     return PROT_READ | PROT_WRITE | PROT_EXEC;
   case llvm::sys::Memory::MF_EXEC:
 #if (defined(__FreeBSD__) || defined(__POWERPC__) || defined (__ppc__) || \
-     defined(_POWER) || defined(_ARCH_PPC))
+     defined(_POWER) || defined(_ARCH_PPC) || defined(__QuinnBSD__))
     // On PowerPC, having an executable page that has no read permission
     // can have unintended consequences.  The function InvalidateInstruction-
     // Cache uses instructions dcbf and icbi, both of which are treated by
