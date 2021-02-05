$NetBSD$

--- utils/unittest/googletest/include/gtest/internal/gtest-port-arch.h.orig	2019-12-11 19:15:30.000000000 +0000
+++ utils/unittest/googletest/include/gtest/internal/gtest-port-arch.h
@@ -67,7 +67,7 @@
 # if TARGET_OS_IPHONE
 #  define GTEST_OS_IOS 1
 # endif
-#elif defined __FreeBSD__
+#elif defined __FreeBSD__ || defined __QuinnBSD__
 # define GTEST_OS_FREEBSD 1
 #elif defined __linux__
 # define GTEST_OS_LINUX 1
