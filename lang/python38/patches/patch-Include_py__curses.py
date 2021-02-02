$NetBSD$

--- Include/py_curses.h.orig	2020-12-21 16:25:24.000000000 +0000
+++ Include/py_curses.h
@@ -14,7 +14,7 @@
 
 /* On FreeBSD, [n]curses.h and stdlib.h/wchar.h use different guards
    against multiple definition of wchar_t and wint_t. */
-#if defined(__FreeBSD__) && defined(_XOPEN_SOURCE_EXTENDED)
+#if (defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(_XOPEN_SOURCE_EXTENDED)
 # ifndef __wchar_t
 #   define __wchar_t
 # endif
