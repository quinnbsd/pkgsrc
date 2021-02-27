$NetBSD$

--- src/util/string.cpp.orig	2021-02-23 18:50:37.000000000 +0000
+++ src/util/string.cpp
@@ -39,9 +39,11 @@ with this program; if not, write to the
 	#include <windows.h>
 #endif
 
-#if defined(_ICONV_H_) && (defined(__FreeBSD__) || defined(__NetBSD__) || \
-	defined(__OpenBSD__) || defined(__DragonFly__))
-	#define BSD_ICONV_USED
+#ifdef __NetBSD__
+#  include <sys/param.h>
+#  if __NetBSD_Version__ <= 999001500
+#  define BSD_ICONV_USED
+#  endif
 #endif
 
 static bool parseHexColorString(const std::string &value, video::SColor &color,
@@ -80,7 +82,7 @@ static bool convert(const char *to, cons
 	return true;
 }
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 // On Android iconv disagrees how big a wchar_t is for whatever reason
 const char *DEFAULT_ENCODING = "UTF-32LE";
 #else
@@ -98,7 +100,7 @@ std::wstring utf8_to_wide(const std::str
 	std::wstring out;
 	out.resize(outbuf_size / sizeof(wchar_t));
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 	SANITY_CHECK(sizeof(wchar_t) == 4);
 #endif
 
