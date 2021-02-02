$NetBSD$

--- Include/pythread.h.orig	2020-12-21 16:25:24.000000000 +0000
+++ Include/pythread.h
@@ -26,7 +26,7 @@ PyAPI_FUNC(unsigned long) PyThread_start
 PyAPI_FUNC(void) _Py_NO_RETURN PyThread_exit_thread(void);
 PyAPI_FUNC(unsigned long) PyThread_get_thread_ident(void);
 
-#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(_WIN32) || defined(_AIX)
+#if defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(_WIN32) || defined(_AIX) || defined(__QuinnBSD__)
 #define PY_HAVE_THREAD_NATIVE_ID
 PyAPI_FUNC(unsigned long) PyThread_get_thread_native_id(void);
 #endif
