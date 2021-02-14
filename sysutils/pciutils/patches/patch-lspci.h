$NetBSD$

--- lspci.h.orig	2019-02-13 10:05:03.000000000 +0000
+++ lspci.h
@@ -14,7 +14,7 @@
  *  This increases our memory footprint, but only slightly since we don't
  *  use alloca() much.
  */
-#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__DragonFly__) || defined (__DJGPP__)
+#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__DragonFly__) || defined (__DJGPP__) || defined(__QuinnBSD__)
 /* alloca() is defined in stdlib.h */
 #elif defined(__GNUC__) && !defined(PCI_OS_WINDOWS)
 #include <alloca.h>
