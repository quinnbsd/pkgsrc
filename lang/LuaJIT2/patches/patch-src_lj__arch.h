$NetBSD$

--- src/lj_arch.h.orig	2017-05-01 18:11:00.000000000 +0000
+++ src/lj_arch.h
@@ -68,6 +68,7 @@
 #define LUAJIT_OS	LUAJIT_OS_OSX
 #elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || \
        defined(__NetBSD__) || defined(__OpenBSD__) || \
+       defined(__QuinnBSD__) || \
        defined(__DragonFly__)) && !defined(__ORBIS__)
 #define LUAJIT_OS	LUAJIT_OS_BSD
 #elif (defined(__sun__) && defined(__svr4__))
@@ -339,12 +340,21 @@
 #if defined(_SOFT_FLOAT) || defined(_SOFT_DOUBLE)
 #error "No support for PowerPC CPUs without double-precision FPU"
 #endif
-#if defined(_LITTLE_ENDIAN)
-#error "No support for little-endian PowerPC"
+
+#if defined(_BYTE_ORDER) && defined(_LITTLE_ENDIAN)
+# if (_BYTE_ORDER == _LITTLE_ENDIAN)
+#  error "No support for little-endian PowerPC"
+# endif
+#else
+# if defined(_LITTLE_ENDIAN)
+#  error "No support for little-endian PowerPC"
+# endif
 #endif
+
 #if defined(_LP64)
 #error "No support for PowerPC 64 bit mode"
 #endif
+
 #elif LJ_TARGET_MIPS
 #if defined(__mips_soft_float)
 #error "No support for MIPS CPUs without FPU"
