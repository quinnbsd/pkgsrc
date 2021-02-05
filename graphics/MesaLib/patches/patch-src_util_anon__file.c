$NetBSD$

--- src/util/anon_file.c.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/util/anon_file.c
@@ -34,7 +34,7 @@
 #include <fcntl.h>
 #include <errno.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/mman.h>
 #elif defined(HAVE_MEMFD_CREATE) || defined(ANDROID)
 #include <sys/syscall.h>
@@ -45,7 +45,7 @@
 #include <stdlib.h>
 #endif
 
-#if !(defined(__FreeBSD__) || defined(HAVE_MEMFD_CREATE) || defined(HAVE_MKOSTEMP) || defined(ANDROID))
+#if !(defined(__FreeBSD__) || defined(__QuinnBSD__) || defined(HAVE_MEMFD_CREATE) || defined(HAVE_MKOSTEMP) || defined(ANDROID))
 static int
 set_cloexec_or_close(int fd)
 {
@@ -69,7 +69,7 @@ err:
 }
 #endif
 
-#if !(defined(__FreeBSD__) || defined(HAVE_MEMFD_CREATE) || defined(ANDROID))
+#if !(defined(__FreeBSD__) || defined(__QuinnBSD__) || defined(HAVE_MEMFD_CREATE) || defined(ANDROID))
 static int
 create_tmpfile_cloexec(char *tmpname)
 {
@@ -116,7 +116,7 @@ int
 os_create_anonymous_file(off_t size, const char *debug_name)
 {
    int fd, ret;
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
    (void*)debug_name;
    fd = shm_open(SHM_ANON, O_CREAT | O_RDWR | O_CLOEXEC, 0600);
 #elif defined(HAVE_MEMFD_CREATE) || defined(ANDROID)
