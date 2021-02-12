$NetBSD$

--- ./Source/ThirdParty/gtest/include/gtest/internal/gtest-port-arch.h.orig	2020-08-12 09:17:53.000000000 +0000
+++ ./Source/ThirdParty/gtest/include/gtest/internal/gtest-port-arch.h
@@ -70,7 +70,7 @@
 # if TARGET_OS_IPHONE
 #  define GTEST_OS_IOS 1
 # endif
-#elif defined __FreeBSD__
+#elif defined __FreeBSD__ || defined __QuinnBSD__
 # define GTEST_OS_FREEBSD 1
 #elif defined __Fuchsia__
 # define GTEST_OS_FUCHSIA 1
