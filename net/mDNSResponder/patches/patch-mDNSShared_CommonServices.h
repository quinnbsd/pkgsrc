$NetBSD$

--- mDNSShared/CommonServices.h.orig	2009-08-11 01:13:47.000000000 +0000
+++ mDNSShared/CommonServices.h
@@ -64,6 +64,32 @@
 	#endif
 #endif
 
+// NetBSD
+
+#if( !defined( TARGET_OS_NETBSD ) )
+	#if( defined( __NetBSD__ ) )
+		#define	TARGET_OS_NETBSD		1
+	#else
+		#define	TARGET_OS_NETBSD		0
+	#endif
+#endif
+
+#if( !defined( TARGET_OS_FREEBSD ) )
+	#if( defined( __FreeBSD__ ) || defined(__QuinnBSD__) )
+		#define	TARGET_OS_FREEBSD		1
+	#else
+		#define	TARGET_OS_FREEBSD		0
+	#endif
+#endif
+
+#if( !defined( TARGET_OS_DRAGONFLY ) )
+	#if( defined( __DragonFly__ ) )
+		#define	TARGET_OS_DRAGONFLY		1
+	#else
+	#define	TARGET_OS_DRAGONFLY		0
+	#endif
+#endif
+
 // Solaris
 
 #if( !defined( TARGET_OS_SOLARIS ) )
@@ -74,6 +100,16 @@
 	#endif
 #endif
 
+// OpenBSD
+
+#if( !defined( TARGET_OS_OPENBSD ) )
+	#if( defined( __OpenBSD__ ) )
+		#define	TARGET_OS_OPENBSD		1
+	#else
+		#define	TARGET_OS_OPENBSD		0
+	#endif
+#endif
+
 // Palm
 
 #if( !defined( TARGET_OS_PALM ) )
@@ -90,7 +126,7 @@
 	
 	// No predefined macro for VxWorks so just assume VxWorks if nothing else is set.
 	
-	#if( !macintosh && !__MACH__  && !defined( __linux__ ) && !defined ( __SVR4 ) && !defined ( __sun ) && !defined( __PALMOS_TRAPS__ ) && !defined( __PALMOS_ARMLET__ ) && !defined( _WIN32 ) )
+	#if( !macintosh && !__MACH__  && !defined( __linux__ ) && !defined ( __SVR4 ) && !defined ( __sun ) && !defined( __PALMOS_TRAPS__ ) && !defined( __PALMOS_ARMLET__ ) && !defined( _WIN32 ) && !defined(__NetBSD__) && !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__QuinnBSD__))
 		#define	TARGET_OS_VXWORKS		1
 	#else
 		#define	TARGET_OS_VXWORKS		0
@@ -186,6 +222,27 @@
 	#include	<stdint.h>
 	#include	<arpa/inet.h>
 	
+#elif ( TARGET_OS_NETBSD )
+
+	// NetBSD
+
+	#include	<arpa/inet.h>
+
+#elif ( TARGET_OS_FREEBSD )
+
+	// FreeBSD
+
+	#include	<stdint.h>
+	#include	<arpa/inet.h>
+	#include	<sys/socket.h> // for AF_INET6 definition
+
+#elif ( TARGET_OS_DRAGONFLY )
+
+	// DragonFly
+
+	#include	<arpa/inet.h>
+	#include	<sys/socket.h> // for AF_INET6 definition
+
 #elif( TARGET_OS_SOLARIS )
 	
 	// Solaris
@@ -202,6 +259,14 @@
 		#define TARGET_RT_BIG_ENDIAN		1
 	#endif
 
+#elif ( TARGET_OS_OPENBSD )
+
+	// OpenBSD
+
+	#include	<pthread.h>
+	#include	<arpa/inet.h>
+	#include	<sys/socket.h> // for AF_INET6 definition
+
 #elif( TARGET_OS_PALM )
 	
 	// Palm (no special includes yet).
@@ -455,7 +520,7 @@
 // - Windows
 
 #if( TARGET_LANGUAGE_C_LIKE )
-	#if( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_LINUX && !TARGET_OS_VXWORKS && !TARGET_OS_MAC)
+	#if( !defined(_SSIZE_T) && ( TARGET_OS_WIN32 || !defined( _BSD_SSIZE_T_DEFINED_ ) ) && !TARGET_OS_LINUX && !TARGET_OS_VXWORKS && !TARGET_OS_MAC && !TARGET_OS_NETBSD && !TARGET_OS_DRAGONFLY && !TARGET_OS_FREEBSD && !TARGET_OS_OPENBSD)
 		typedef int						ssize_t;
 	#endif
 #endif
