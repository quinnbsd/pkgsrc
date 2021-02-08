$NetBSD$

--- libavutil/common.h.orig	2020-07-11 10:39:32.000000000 +0000
+++ libavutil/common.h
@@ -44,6 +44,22 @@
 #include "version.h"
 #include "libavutil/avconfig.h"
 
+#if defined(__cplusplus)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__linux__) || defined(__QuinnBSD__)
+#undef _STDINT_H_
+#undef _SYS_STDINT_H_
+#undef _STDINT_H
+#undef _GCC_WRAP_STDINT_H
+#ifndef __STDC_CONSTANT_MACROS
+#define __STDC_CONSTANT_MACROS
+#endif
+#include <stdint.h>
+#endif /* FreeBSD | OpenBSD | linux */
+#if defined(__DragonFly__) || defined(__NetBSD__)
+#include <machine/int_const.h>
+#endif /* DragonFly | NetBSD */
+#endif /* __cplusplus */
+
 #if AV_HAVE_BIGENDIAN
 #   define AV_NE(be, le) (be)
 #else
