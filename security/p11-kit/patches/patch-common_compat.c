$NetBSD$

--- common/compat.c.orig	2020-12-11 15:25:36.000000000 +0000
+++ common/compat.c
@@ -828,6 +828,9 @@ mkdtemp (char *template)
 #ifndef HAVE_GETAUXVAL
 
 unsigned long
+#if defined(__GNUC__) || defined(__clang__)
+__attribute__((visibility("hidden")))
+#endif
 getauxval (unsigned long type)
 {
 	static unsigned long secure = 0UL;
@@ -845,7 +848,7 @@ getauxval (unsigned long type)
 		secure = __libc_enable_secure;
 
 #elif defined(HAVE_ISSETUGID) && \
-	!((defined __APPLE__ && defined __MACH__) || (defined __FreeBSD__))
+	!((defined __APPLE__ && defined __MACH__) || (defined __FreeBSD__) || defined(__QuinnBSD__))
 		secure = issetugid ();
 
 #elif defined(OS_UNIX)
