$NetBSD$

--- ./mjit_worker.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./mjit_worker.c
@@ -239,7 +239,7 @@ static char *libruby_pathflag;
 
 #if defined(__GNUC__) && \
      (!defined(__clang__) || \
-      (defined(__clang__) && (defined(__FreeBSD__) || defined(__GLIBC__))))
+      (defined(__clang__) && (defined(__FreeBSD__) || defined(__QuinnBSD__) || defined(__GLIBC__))))
 # define GCC_PIC_FLAGS "-Wfatal-errors", "-fPIC", "-shared", "-w", "-pipe",
 # define MJIT_CFLAGS_PIPE 1
 #else
