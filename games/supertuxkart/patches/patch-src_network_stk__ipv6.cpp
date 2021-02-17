$NetBSD$

--- src/network/stk_ipv6.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ src/network/stk_ipv6.cpp
@@ -37,7 +37,9 @@ extern "C"
 #endif
 
 #else
-
+#if defined(__QuinnBSD__)
+#include <netinet/in.h>
+#endif
 #include <arpa/inet.h>
 #include <err.h>
 #include <netdb.h>
