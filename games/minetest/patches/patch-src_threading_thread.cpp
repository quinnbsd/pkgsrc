$NetBSD$

--- src/threading/thread.cpp.orig	2020-07-09 20:04:20.000000000 +0000
+++ src/threading/thread.cpp
@@ -31,7 +31,7 @@ DEALINGS IN THE SOFTWARE.
 // for setName
 #if defined(__linux__)
 	#include <sys/prctl.h>
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 	#include <pthread_np.h>
 #elif defined(_MSC_VER)
 	struct THREADNAME_INFO {
@@ -213,13 +213,13 @@ void Thread::setName(const std::string &
 	// distributions are still runing 2.11 and previous versions.
 	prctl(PR_SET_NAME, name.c_str());
 
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 	pthread_set_name_np(pthread_self(), name.c_str());
 
 #elif defined(__NetBSD__)
 
-	pthread_setname_np(pthread_self(), name.c_str());
+	pthread_setname_np(pthread_self(), "%s", (char *)name.c_str());
 
 #elif defined(__APPLE__)
 
@@ -273,7 +273,7 @@ bool Thread::bindToProcessor(unsigned in
 
 	return SetThreadAffinityMask(pthread_gethandle(getThreadHandle()), 1 << proc_number);
 
-#elif __FreeBSD_version >= 702106 || defined(__linux__) || defined(__DragonFly__)
+#elif __FreeBSD_version >= 702106 || defined(__linux__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 	cpu_set_t cpuset;
 
