$NetBSD$

--- nss/coreconf/arch.mk.orig	2021-01-22 17:08:28.000000000 +0000
+++ nss/coreconf/arch.mk
@@ -106,7 +106,7 @@ endif
 # IRIX 6.5-ALPHA-1289139620.
 #
 
-ifeq (,$(filter-out Linux FreeBSD IRIX,$(OS_ARCH)))
+ifeq (,$(filter-out Linux DragonFly FreeBSD QuinnBSD IRIX,$(OS_ARCH)))
     OS_RELEASE := $(shell echo $(OS_RELEASE) | sed 's/-.*//')
 endif
 
