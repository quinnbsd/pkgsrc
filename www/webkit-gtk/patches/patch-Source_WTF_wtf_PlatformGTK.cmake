$NetBSD$

--- Source/WTF/wtf/PlatformGTK.cmake.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -56,6 +56,12 @@ elseif (CMAKE_SYSTEM_NAME MATCHES "FreeB
 
         unix/MemoryPressureHandlerUnix.cpp
     )
+elseif (CMAKE_SYSTEM_NAME MATCHES "QuinnBSD")
+    list(APPEND WTF_SOURCES
+        generic/MemoryFootprintGeneric.cpp
+
+        unix/MemoryPressureHandlerUnix.cpp
+    )
 else ()
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
