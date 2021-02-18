$NetBSD$

--- src/vis.c.orig	2018-05-25 18:09:38.000000000 +0000
+++ src/vis.c
@@ -142,7 +142,7 @@ static const wchar_t char_glob[] = L"*?[
  * loops below are using sizeof(uint64_t) - 1 instead of MB_LEN_MAX, and
  * the assertion is commented out.
  */
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 /*
  * On FreeBSD including <sys/systm.h> for CTASSERT only works in kernel
  * mode.
