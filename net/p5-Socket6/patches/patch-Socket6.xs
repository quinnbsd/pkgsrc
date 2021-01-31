$NetBSD$

--- Socket6.xs.orig	2018-09-30 04:22:53.000000000 +0000
+++ Socket6.xs
@@ -63,9 +63,10 @@ const struct in6_addr in6addr_loopback =
 # include <sys/param.h>
 # include <net/route.h>
 # if (defined(__FreeBSD__) && __FreeBSD_version >= 700048) || \
-     (defined(__NetBSD__) && __NetBSD_Version__ >= 899002500)
+     (defined(__NetBSD__) && __NetBSD_Version__ >= 899002500) || defined(__QuinnBSD__)
 #  include <netipsec/ipsec.h>
-# elif !defined(__OpenBSD__) && !defined(__DragonFly__)
+# elif !defined(__OpenBSD__) && !defined(__DragonFly__) && \
+     !defined(__Minix__)
 #  include <netinet6/ipsec.h>
 # endif
 #endif
