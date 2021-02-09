$NetBSD$

--- cmake/Modules/DefinePlatformDefaults.cmake.orig	2018-09-10 05:36:49.000000000 +0000
+++ cmake/Modules/DefinePlatformDefaults.cmake
@@ -9,6 +9,11 @@ if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
     set(BSD TRUE)
 endif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
 
+if (CMAKE_SYSTEM_NAME MATCHES "QuinnBSD")
+    set(FREEBSD TRUE)
+    set(BSD TRUE)
+endif (CMAKE_SYSTEM_NAME MATCHES "QuinnBSD")
+
 if (CMAKE_SYSTEM_NAME MATCHES "OpenBSD")
     set(OPENBSD TRUE)
     set(BSD TRUE)
