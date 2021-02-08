$NetBSD$

--- src/mesa/x86/assyntax.h.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/mesa/x86/assyntax.h
@@ -978,7 +978,8 @@
 #if defined(Lynx) || (defined(SYSV) || defined(SVR4)) \
  || (defined(__linux__) || defined(__OS2ELF__)) && defined(__ELF__) \
  || (defined(__FreeBSD__) && __FreeBSD__ >= 3) \
- || (defined(__NetBSD__) && defined(__ELF__))
+ || (defined(__NetBSD__) && defined(__ELF__)) \
+ || defined(__QuinnBSD__)
 #define GLNAME(a)	a
 #else
 #define GLNAME(a)	CONCAT(_, a)
