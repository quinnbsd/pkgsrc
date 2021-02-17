$NetBSD$

--- src/utils/string_utils.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ src/utils/string_utils.cpp
@@ -1406,6 +1406,8 @@ namespace StringUtils
         uagent += (std::string)" (Macintosh)";
 #elif defined(__FreeBSD__)
         uagent += (std::string)" (FreeBSD)";
+#elif defined(__QuinnBSD__)
+	uagent += (std::string)" (QuinnBSD)";
 #elif defined(ANDROID)
         uagent += (std::string)" (Android)";
 #elif defined(linux)
