$NetBSD$

--- deps/uv/src/unix/bsd-ifaddrs.c.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/src/unix/bsd-ifaddrs.c
@@ -50,7 +50,7 @@ static int uv__ifaddr_exclude(struct ifa
     return (ent->ifa_addr->sa_family != AF_LINK);
 #endif
 #if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || \
-    defined(__HAIKU__)
+    defined(__HAIKU__) || defined(__QuinnBSD__)
   /*
    * On BSD getifaddrs returns information related to the raw underlying
    * devices.  We're not interested in this information.
