$NetBSD$

--- ./boost/interprocess/shared_memory_object.hpp.orig	2020-12-03 05:01:42.000000000 +0000
+++ ./boost/interprocess/shared_memory_object.hpp
@@ -39,7 +39,7 @@
 #  include <unistd.h>       //ftruncate, close
 #  include <sys/stat.h>     //mode_t, S_IRWXG, S_IRWXO, S_IRWXU,
 #  if defined(BOOST_INTERPROCESS_RUNTIME_FILESYSTEM_BASED_POSIX_SHARED_MEMORY)
-#     if defined(__FreeBSD__)
+#     if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #        include <sys/sysctl.h>
 #     endif
 #  endif
@@ -257,7 +257,7 @@ namespace shared_memory_object_detail {
 
 #ifdef BOOST_INTERPROCESS_RUNTIME_FILESYSTEM_BASED_POSIX_SHARED_MEMORY
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 
 inline bool use_filesystem_based_posix()
 {
