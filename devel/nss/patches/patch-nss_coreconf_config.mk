$NetBSD$

--- nss/coreconf/config.mk.orig	2021-01-22 17:08:28.000000000 +0000
+++ nss/coreconf/config.mk
@@ -30,8 +30,8 @@ endif
 #       one for each OS release.                                      #
 #######################################################################
 
-TARGET_OSES = FreeBSD BSD_OS NetBSD OpenUNIX OS2 QNX Darwin BeOS OpenBSD \
-              AIX RISCOS WINNT WIN95 Linux Android
+TARGET_OSES = QuinnBSD FreeBSD BSD_OS NetBSD OpenUNIX OS2 QNX Darwin BeOS OpenBSD \
+              AIX RISCOS WINNT WIN95 Linux Android DragonFly
 
 ifeq (,$(filter-out $(TARGET_OSES),$(OS_TARGET)))
 include $(CORE_DEPTH)/coreconf/$(OS_TARGET).mk
@@ -241,6 +241,7 @@ endif
 DEFINES += -DUSE_UTIL_DIRECTLY
 USE_UTIL_DIRECTLY = 1
 
+EXTRA_SHARED_LIBS +=    -Wl,-R${PREFIX}/lib/${MOZILLA_PKG_NAME}
 # Build with NO_NSPR_10_SUPPORT to avoid using obsolete NSPR features
 DEFINES += -DNO_NSPR_10_SUPPORT
 
