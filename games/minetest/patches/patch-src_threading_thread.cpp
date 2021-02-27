$NetBSD$

--- src/threading/thread.cpp.orig	2021-02-23 18:50:37.000000000 +0000
+++ src/threading/thread.cpp
@@ -31,7 +31,7 @@ DEALINGS IN THE SOFTWARE.
 // for setName
 #if defined(__linux__)
 	#include <sys/prctl.h>
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 	#include <pthread_np.h>
 #elif defined(__NetBSD__)
 	#include <sched.h>
@@ -205,7 +205,7 @@ void Thread::setName(const std::string &
 	// distributions are still runing 2.11 and previous versions.
 	prctl(PR_SET_NAME, name.c_str());
 
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 	pthread_set_name_np(pthread_self(), name.c_str());
 
@@ -269,7 +269,7 @@ bool Thread::bindToProcessor(unsigned in
 
 	return SetThreadAffinityMask(pthread_gethandle(getThreadHandle()), 1 << proc_number);
 
-#elif __FreeBSD_version >= 702106 || defined(__linux__) || defined(__DragonFly__)
+#elif __FreeBSD_version >= 702106 || defined(__linux__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 	cpu_set_t cpuset;
 
