$NetBSD$

--- src/common_interface.c.orig	2019-07-17 16:25:27.000000000 +0000
+++ src/common_interface.c
@@ -70,6 +70,22 @@
 # define HTOLE_32(x)   (x)
 #endif /* Solaris */
 
+#elif defined(__APPLE__)
+
+#include <architecture/byte_order.h>
+
+#if __BYTE_ORDER == __BIG_ENDIAN
+# define LETOH_16(x)	OSSwapInt16(x)
+# define HTOLE_16(x)	OSSwapInt16(x)
+# define LETOH_32(x)	OSSwapInt32(x)
+# define HTOLE_32(x)	OSSwapInt32(x)
+#else
+# define LETOH_16(x)	(x)
+# define HTOLE_16(x)	(x)
+# define LETOH_32(x)	(x)
+# define HTOLE_32(x)	(x)
+#endif /* darwin */
+
 #else
 
 #include <sys/endian.h>
@@ -77,7 +93,7 @@
 #define HTOLE_16(x)	htole16(x)
 #define HTOLE_32(x)	htole32(x)
 
-#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QuinnBSD__)
 #define LETOH_16(x)	le16toh(x)
 #define LETOH_32(x)	le32toh(x)
 #else
