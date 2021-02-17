$NetBSD$

--- src/main.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ src/main.cpp
@@ -692,7 +692,7 @@ void cmdLineHelp()
     "       --apitrace          This will disable buffer storage and\n"
     "                           writing gpu query strings to opengl, which\n"
     "                           can be seen later in apitrace.\n"
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
     "\n"
     "Environment variables:\n"
     "       IRR_DEVICE_TYPE=[x11, wayland] Force x11/wayland device\n"
