$NetBSD$

--- unittests/Support/Path.cpp.orig	2019-12-11 19:15:30.000000000 +0000
+++ unittests/Support/Path.cpp
@@ -1758,7 +1758,7 @@ TEST_F(FileSystemTest, permissions) {
   // AIX and Solaris without root will mask off (i.e., lose) the sticky bit
   // on files.
 #if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) &&  \
-    !defined(_AIX) && !(defined(__sun__) && defined(__svr4__))
+    !defined(_AIX) && !(defined(__sun__) && defined(__svr4__)) && !defined(__QuinnBSD__)
   EXPECT_EQ(fs::setPermissions(TempPath, fs::sticky_bit), NoError);
   EXPECT_TRUE(CheckPermissions(fs::sticky_bit));
 
