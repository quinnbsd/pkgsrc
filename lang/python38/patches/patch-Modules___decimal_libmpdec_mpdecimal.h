$NetBSD$

--- Modules/_decimal/libmpdec/mpdecimal.h.orig	2020-12-21 16:25:24.000000000 +0000
+++ Modules/_decimal/libmpdec/mpdecimal.h
@@ -69,7 +69,7 @@ extern "C" {
   #else
     #define UNUSED
   #endif
-  #if (defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)) && \
+  #if (defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__) || defined(__APPLE__)) && \
       defined(__GNUC__) && __GNUC__ >= 4 && !defined(__INTEL_COMPILER)
     #define MPD_PRAGMA(x) _Pragma(x)
     #define MPD_HIDE_SYMBOLS_START "GCC visibility push(hidden)"
@@ -135,6 +135,9 @@ const char *mpd_version(void);
   #elif defined(__x86_64__)
     #define CONFIG_64
     #define ASM
+  #elif defined(__aarch64__)
+    #define CONFIG_64
+    #define ANSI
   #else
     #error "unknown architecture for universal build."
   #endif
