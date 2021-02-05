$NetBSD$

--- Utilities/cmlibuv/src/unix/process.c.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibuv/src/unix/process.c
@@ -48,7 +48,7 @@ extern char **environ;
 #ifndef CMAKE_BOOTSTRAP
 #if defined(__linux__)
 # define uv__cpu_set_t cpu_set_t
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 # include <sys/param.h>
 # include <sys/cpuset.h>
 # include <pthread_np.h>
@@ -124,7 +124,7 @@ static void uv__chld(uv_signal_t* handle
 
 
 static int uv__make_socketpair(int fds[2]) {
-#if defined(__FreeBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__) || defined(__QuinnBSD__)
   if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, fds))
     return UV__ERR(errno);
 
@@ -151,7 +151,7 @@ static int uv__make_socketpair(int fds[2
 
 
 int uv__make_pipe(int fds[2], int flags) {
-#if defined(__FreeBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__) || defined(__QuinnBSD__)
   if (pipe2(fds, flags | O_CLOEXEC))
     return UV__ERR(errno);
 
@@ -286,7 +286,7 @@ static void uv__process_child_init(const
   int fd;
   int n;
 #ifndef CMAKE_BOOTSTRAP
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
   int r;
   int i;
   int cpumask_size;
@@ -384,7 +384,7 @@ static void uv__process_child_init(const
   }
 
 #ifndef CMAKE_BOOTSTRAP
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
   if (options->cpumask != NULL) {
     cpumask_size = uv_cpumask_size();
     assert(options->cpumask_size >= (size_t)cpumask_size);
@@ -466,7 +466,7 @@ int uv_spawn(uv_loop_t* loop,
 
   if (options->cpumask != NULL) {
 #ifndef CMAKE_BOOTSTRAP
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
     if (options->cpumask_size < (size_t)uv_cpumask_size()) {
       return UV_EINVAL;
     }
