$NetBSD$

--- Include/py_curses.h.orig	2020-04-19 21:13:39.000000000 +0000
+++ Include/py_curses.h
@@ -12,7 +12,7 @@
 #endif
 #endif /* __APPLE__ */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 /*
 ** On FreeBSD, [n]curses.h and stdlib.h/wchar.h use different guards
 ** against multiple definition of wchar_t and wint_t.
