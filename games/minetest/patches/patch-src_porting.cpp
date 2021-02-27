$NetBSD$

--- src/porting.cpp.orig	2021-02-23 18:50:37.000000000 +0000
+++ src/porting.cpp
@@ -25,7 +25,7 @@ with this program; if not, write to the
 
 #include "porting.h"
 
-#if defined(__FreeBSD__)  || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__)  || defined(__NetBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 	#include <sys/types.h>
 	#include <sys/sysctl.h>
 	extern char **environ;
@@ -303,7 +303,7 @@ bool getCurrentExecPath(char *buf, size_
 
 
 //// FreeBSD, NetBSD, DragonFlyBSD
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 bool getCurrentExecPath(char *buf, size_t len)
 {
@@ -422,7 +422,7 @@ bool setSystemPaths()
 
 
 //// Linux
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 bool setSystemPaths()
 {
