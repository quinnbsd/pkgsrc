$NetBSD$

--- ./libs/log/src/process_name.cpp.orig	2020-12-03 05:01:48.000000000 +0000
+++ ./libs/log/src/process_name.cpp
@@ -107,7 +107,7 @@ BOOST_LOG_CLOSE_NAMESPACE // namespace l
 
 #include <boost/log/detail/footer.hpp>
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 
 #include <stddef.h>
 #include <unistd.h>
