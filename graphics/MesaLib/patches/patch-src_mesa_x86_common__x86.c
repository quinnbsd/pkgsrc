$NetBSD$

--- src/mesa/x86/common_x86.c.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/mesa/x86/common_x86.c
@@ -35,7 +35,7 @@
  */
 
 /* XXX these includes should probably go into imports.h or glheader.h */
-#if defined(USE_SSE_ASM) && defined(__FreeBSD__)
+#if defined(USE_SSE_ASM) && (defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__))
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -126,7 +126,7 @@ static LONG WINAPI ExceptionFilter(LPEXC
  */
 void _mesa_check_os_sse_support( void )
 {
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
    {
       int ret, enabled;
       unsigned int len;
