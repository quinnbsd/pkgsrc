$NetBSD$

--- Source/JavaScriptCore/jsc.cpp.orig	2020-08-12 09:17:53.000000000 +0000
+++ Source/JavaScriptCore/jsc.cpp
@@ -87,6 +87,10 @@
 #include <wtf/text/StringBuilder.h>
 #include <wtf/threads/Signals.h>
 
+#if OS(FREEBSD)
+#include <locale.h>
+#endif
+
 #if OS(WINDOWS)
 #include <direct.h>
 #include <fcntl.h>
