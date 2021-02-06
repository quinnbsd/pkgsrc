$NetBSD$

--- cups/http.h.orig	2020-11-27 14:25:26.000000000 +0000
+++ cups/http.h
@@ -78,7 +78,7 @@ extern "C" {
 #if defined(AF_INET6) && !defined(s6_addr32)
 #  if defined(__sun)
 #    define s6_addr32	_S6_un._S6_u32
-#  elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)|| defined(__DragonFly__)
+#  elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)|| defined(__DragonFly__) || defined(__QuinnBSD__)
 #    define s6_addr32	__u6_addr.__u6_addr32
 #  elif defined(_WIN32)
 /*
