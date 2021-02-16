$NetBSD$

--- ./boost/config/platform/bsd.hpp.orig	2020-12-03 05:01:13.000000000 +0000
+++ ./boost/config/platform/bsd.hpp
@@ -9,7 +9,7 @@
 
 //  generic BSD config options:
 
-#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__) && !defined(__QuinnBSD__)
 #error "This platform is not BSD"
 #endif
 
@@ -21,6 +21,8 @@
 #define BOOST_PLATFORM "OpenBSD " BOOST_STRINGIZE(__OpenBSD__)
 #elif defined(__DragonFly__)
 #define BOOST_PLATFORM "DragonFly " BOOST_STRINGIZE(__DragonFly__)
+#elif defined(__QuinnBSD__)
+#define BOOST_PLATFORM "QuinnBSD " BOOST_STRINGIZE(__QuinnBSD__)
 #endif
 
 //
@@ -28,7 +30,7 @@
 // FreeBSD has <nl_types.h> but does not
 // advertise the fact in <unistd.h>:
 //
-#if (defined(__FreeBSD__) && (__FreeBSD__ >= 3)) || defined(__DragonFly__)
+#if (defined(__FreeBSD__) && (__FreeBSD__ >= 3)) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #  define BOOST_HAS_NL_TYPES_H
 #endif
 
@@ -37,7 +39,7 @@
 // and not in <unistd.h>
 //
 #if (defined(__FreeBSD__) && (__FreeBSD__ <= 3))\
-   || defined(__OpenBSD__) || defined(__DragonFly__) 
+   || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #  define BOOST_HAS_PTHREADS
 #endif
 
@@ -56,13 +58,15 @@
 #endif
 
 #if !((defined(__FreeBSD__) && (__FreeBSD__ >= 5)) \
-      || (defined(__NetBSD_GCC__) && (__NetBSD_GCC__ >= 2095003)) || defined(__DragonFly__))
+      || (defined(__NetBSD_GCC__) && (__NetBSD_GCC__ >= 2095003)) \
+      || defined(__DragonFly__) \
+      || defined(__OpenBSD__) || defined(__QuinnBSD__))
 #  define BOOST_NO_CWCHAR
 #endif
 //
 // The BSD <ctype.h> has macros only, no functions:
 //
-#if !defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #  define BOOST_NO_CTYPE_FUNCTIONS
 #endif
 
