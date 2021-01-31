$NetBSD$

--- tp/Texinfo/XS/gnulib/lib/float.in.h.orig	2019-08-25 17:11:45.000000000 +0000
+++ tp/Texinfo/XS/gnulib/lib/float.in.h
@@ -63,7 +63,7 @@
 /* On FreeBSD/x86 6.4, the 'long double' type really has only 53 bits of
    precision in the compiler but 64 bits of precision at runtime.  See
    <https://lists.gnu.org/r/bug-gnulib/2008-07/msg00063.html>.  */
-#if defined __i386__ && (defined __FreeBSD__ || defined __DragonFly__)
+#if defined __i386__ && (defined __FreeBSD__ || defined __DragonFly__ || defined__QuinnBSD__)
 /* Number of mantissa units, in base FLT_RADIX.  */
 # undef LDBL_MANT_DIG
 # define LDBL_MANT_DIG   64
