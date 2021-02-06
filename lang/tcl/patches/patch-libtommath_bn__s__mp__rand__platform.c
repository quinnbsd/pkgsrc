$NetBSD$

--- libtommath/bn_s_mp_rand_platform.c.orig	2020-07-06 20:41:07.000000000 +0000
+++ libtommath/bn_s_mp_rand_platform.c
@@ -7,7 +7,7 @@
  * - *BSD
  * - Windows
  */
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 #define BN_S_READ_ARC4RANDOM_C
 static mp_err s_read_arc4random(void *p, size_t n)
 {
