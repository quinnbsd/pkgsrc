$NetBSD$

--- Source/kwsys/SystemInformation.cxx.orig	2021-01-28 15:28:45.000000000 +0000
+++ Source/kwsys/SystemInformation.cxx
@@ -79,7 +79,7 @@ typedef int siginfo_t;
 #endif
 
 #if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) ||    \
-  defined(__DragonFly__)
+  defined(__DragonFly__) || defined(__QuinnBSD__)
 #  include <netdb.h>
 #  include <netinet/in.h>
 #  include <sys/param.h>
@@ -1514,7 +1514,7 @@ void SystemInformationImplementation::Ru
 #elif defined(__QNX__)
   this->QueryQNXProcessor();
 #elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) ||  \
-  defined(__DragonFly__)
+  defined(__DragonFly__) || defined(__QuinnBSD__)
   this->QueryBSDProcessor();
 #elif defined(__hpux)
   this->QueryHPUXProcessor();
@@ -1541,7 +1541,7 @@ void SystemInformationImplementation::Ru
 #elif defined(__QNX__)
   this->QueryQNXMemory();
 #elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) ||  \
-  defined(__DragonFly__)
+  defined(__DragonFly__) || defined(__QuinnBSD__)
   this->QueryBSDMemory();
 #elif defined(__CYGWIN__)
   this->QueryCygwinMemory();
@@ -3861,7 +3861,7 @@ long long SystemInformationImplementatio
   return GetCurrentProcessId();
 #elif defined(__linux) || defined(__APPLE__) || defined(__OpenBSD__) ||       \
   defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) ||    \
-  defined(__CYGWIN__)
+  defined(__CYGWIN__) || defined(__QuinnBSD__)
   return getpid();
 #else
   return -1;
@@ -4936,7 +4936,7 @@ bool SystemInformationImplementation::Qu
 bool SystemInformationImplementation::QueryBSDMemory()
 {
 #if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) ||    \
-  defined(__DragonFly__)
+  defined(__DragonFly__) || defined(__QuinnBSD__)
   int ctrl[2] = { CTL_HW, HW_PHYSMEM };
 #  if defined(HW_PHYSMEM64)
   int64_t k;
@@ -5012,7 +5012,7 @@ bool SystemInformationImplementation::Qu
 bool SystemInformationImplementation::QueryBSDProcessor()
 {
 #if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) ||    \
-  defined(__DragonFly__)
+  defined(__DragonFly__) || defined(__QuinnBSD__)
   int k;
   size_t sz = sizeof(k);
   int ctrl[2] = { CTL_HW, HW_NCPU };
