$NetBSD$

--- lib/Support/Unix/Threading.inc.orig	2019-12-11 19:15:30.000000000 +0000
+++ lib/Support/Unix/Threading.inc
@@ -20,11 +20,11 @@
 
 #include <pthread.h>
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #include <pthread_np.h> // For pthread_getthreadid_np() / pthread_set_name_np()
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 #include <errno.h>
 #include <sys/sysctl.h>
 #include <sys/user.h>
@@ -89,7 +89,7 @@ uint64_t llvm::get_threadid() {
   thread_port_t Self = mach_thread_self();
   mach_port_deallocate(mach_task_self(), Self);
   return Self;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
   return uint64_t(pthread_getthreadid_np());
 #elif defined(__NetBSD__)
   return uint64_t(_lwp_self());
@@ -114,7 +114,7 @@ static constexpr uint32_t get_max_thread
 #else
   return 0;
 #endif
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
   return 16;
 #elif defined(__OpenBSD__)
   return 32;
@@ -147,7 +147,7 @@ void llvm::set_thread_name(const Twine &
   ::pthread_setname_np(::pthread_self(), NameStr.data());
 #endif
 #endif
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
   ::pthread_set_name_np(::pthread_self(), NameStr.data());
 #elif defined(__NetBSD__)
   ::pthread_setname_np(::pthread_self(), "%s",
@@ -160,7 +160,7 @@ void llvm::set_thread_name(const Twine &
 void llvm::get_thread_name(SmallVectorImpl<char> &Name) {
   Name.clear();
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
   int pid = ::getpid();
   uint64_t tid = get_threadid();
 
