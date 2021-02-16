$NetBSD$

--- tools/build/src/engine/build.sh.orig	2020-12-03 05:02:49.000000000 +0000
+++ tools/build/src/engine/build.sh
@@ -122,6 +122,8 @@ guess_toolset ()
        fi
     elif test_uname AIX && test_path xlC_r && test_cxx11 vacpp ; then B2_TOOLSET=vacpp
     elif test_uname FreeBSD && test_path freebsd-version && test_path clang++ && test_cxx11 clang ; then B2_TOOLSET=clang
+    elif test_uname QuinnBSD && test_path freebsd-version && test_path clang++ && test_cxx11 clang ; then B2_TOOLSET=clang
+
     elif test_path g++ && test_cxx11 gcc ; then B2_TOOLSET=gcc
     elif test_path clang++ && test_cxx11 clang ; then B2_TOOLSET=clang
     elif test_path icc && test_cxx11 intel-linux ; then B2_TOOLSET=intel-linux
