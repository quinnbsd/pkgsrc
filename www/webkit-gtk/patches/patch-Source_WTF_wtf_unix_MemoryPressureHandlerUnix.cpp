$NetBSD$

--- Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/unix/MemoryPressureHandlerUnix.cpp
@@ -28,7 +28,7 @@
 #include "config.h"
 #include <wtf/MemoryPressureHandler.h>
 
-#include <malloc.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <wtf/MainThread.h>
 #include <wtf/MemoryFootprint.h>
