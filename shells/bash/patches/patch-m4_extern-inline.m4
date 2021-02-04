$NetBSD$

--- m4/extern-inline.m4.orig	2019-02-13 21:33:43.000000000 +0000
+++ m4/extern-inline.m4
@@ -52,7 +52,7 @@ AC_DEFUN([gl_EXTERN_INLINE],
    It defines a macro __GNUC_GNU_INLINE__ to indicate this situation.
  */
 #if (((defined __APPLE__ && defined __MACH__) \
-      || defined __DragonFly__ || defined __FreeBSD__) \
+      || defined __DragonFly__ || defined __FreeBSD__ || defined __QuinnBSD__) \
      && (defined __header_inline \
          ? (defined __cplusplus && defined __GNUC_STDC_INLINE__ \
             && ! defined __clang__) \
