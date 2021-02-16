$NetBSD$

--- ./libs/log/example/doc/extension_system_uptime_attr.cpp.orig	2020-12-03 05:01:48.000000000 +0000
+++ ./libs/log/example/doc/extension_system_uptime_attr.cpp
@@ -32,7 +32,7 @@
 #include <time.h>
 #include <errno.h>
 #include <sys/sysctl.h>
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #include <time.h>
 #endif
 
@@ -112,7 +112,7 @@ unsigned int get_uptime()
     if (sysctl(mib, 2, &boottime, &len, NULL, 0) < 0)
         BOOST_THROW_EXCEPTION(std::runtime_error("Could not acquire uptime"));
     return time(NULL) - boottime.tv_sec;
-#elif (defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)) && defined(CLOCK_UPTIME)
+#elif (defined(__FreeBSD__) || defined(__QuinnBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)) && defined(CLOCK_UPTIME) 
     struct timespec ts;
     if (clock_gettime(CLOCK_UPTIME, &ts) != 0)
         BOOST_THROW_EXCEPTION(std::runtime_error("Could not acquire uptime"));
