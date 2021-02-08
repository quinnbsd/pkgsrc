$NetBSD$

--- include/X11/Xos_r.h.orig	2020-04-14 15:29:25.000000000 +0000
+++ include/X11/Xos_r.h
@@ -248,7 +248,7 @@ typedef struct {
  */
 
 #if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-    defined(__APPLE__) || defined(__DragonFly__)
+    defined(__APPLE__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 static __inline__ void _Xpw_copyPasswd(_Xgetpwparams p)
 {
    memcpy(&(p).pws, (p).pwp, sizeof(struct passwd));
@@ -403,7 +403,7 @@ typedef int _Xgetservbynameparams; /* du
 #elif !defined(XOS_USE_MTSAFE_NETDBAPI) || defined(XNO_MTSAFE_NETDBAPI)
 /* WARNING:  The h_addr_list and s_aliases values are *not* copied! */
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <sys/param.h>
 #endif
 
