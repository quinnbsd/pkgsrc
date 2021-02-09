$NetBSD$

--- src/cpuinfo/SDL_cpuinfo.c.orig	2020-12-21 17:44:36.000000000 +0000
+++ src/cpuinfo/SDL_cpuinfo.c
@@ -50,7 +50,7 @@
 #endif
 #if defined(__MACOSX__) && (defined(__ppc__) || defined(__ppc64__))
 #include <sys/sysctl.h>         /* For AltiVec check */
-#elif (defined(__OpenBSD__) || defined(__FreeBSD__)) && defined(__powerpc__)
+#elif (defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(__powerpc__)
 #include <sys/param.h>
 #include <sys/sysctl.h> /* For AltiVec check */
 #include <machine/cpu.h>
@@ -319,10 +319,10 @@ CPU_haveAltiVec(void)
 {
     volatile int altivec = 0;
 #ifndef SDL_CPUINFO_DISABLED
-#if (defined(__MACOSX__) && (defined(__ppc__) || defined(__ppc64__))) || (defined(__OpenBSD__) && defined(__powerpc__)) || (defined(__FreeBSD__) && defined(__powerpc__))
+#if (defined(__MACOSX__) && (defined(__ppc__) || defined(__ppc64__))) || (defined(__OpenBSD__) && defined(__powerpc__)) || ((defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(__powerpc__))
 #ifdef __OpenBSD__
     int selectors[2] = { CTL_MACHDEP, CPU_ALTIVEC };
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     int selectors[2] = { CTL_HW, PPC_FEATURE_HAS_ALTIVEC };
 #else
     int selectors[2] = { CTL_HW, HW_VECTORUNIT };
@@ -894,7 +894,7 @@ SDL_GetSystemRAM(void)
 #endif
 #ifdef HAVE_SYSCTLBYNAME
         if (SDL_SystemRAM <= 0) {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #ifdef HW_REALMEM
             int mib[2] = {CTL_HW, HW_REALMEM};
 #else
