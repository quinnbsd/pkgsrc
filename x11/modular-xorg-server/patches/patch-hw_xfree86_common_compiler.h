$NetBSD$

--- hw/xfree86/common/compiler.h.orig	2020-12-01 16:32:25.000000000 +0000
+++ hw/xfree86/common/compiler.h
@@ -265,7 +265,7 @@ inl(unsigned long port)
 
 #endif                          /* __linux__ */
 
-#if (defined(__FreeBSD__) || defined(__OpenBSD__)) \
+#if (defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)) \
       && !defined(DO_PROTOTYPES)
 
 /* for FreeBSD and OpenBSD on Alpha, we use the libio (resp. libalpha) */
