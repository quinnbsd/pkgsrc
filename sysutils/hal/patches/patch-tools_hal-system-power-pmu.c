$NetBSD$

--- ./tools/hal-system-power-pmu.c.orig	2009-05-12 12:25:58.000000000 +0000
+++ ./tools/hal-system-power-pmu.c
@@ -53,7 +53,11 @@
 static int
 pmac_sleep (void)
 {
-#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
+	return FALSE;			/* FIXME implement */
+#elif __NetBSD__
+	return FALSE;			/* FIXME implement */
+#elif __DragonFly__
 	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
@@ -90,7 +94,11 @@ pmac_sleep (void)
 static int
 pmac_get_lcd_brightness (int *val)
 {
-#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
+	return FALSE;			/* FIXME implement */
+#elif __NetBSD__
+	return FALSE;			/* FIXME implement */
+#elif __DragonFly__
 	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
@@ -127,7 +135,11 @@ pmac_get_lcd_brightness (int *val)
 static int
 pmac_set_lcd_brightness (int val)
 {
-#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
+	return FALSE;			/* FIXME implement */
+#elif __NetBSD__
+	return FALSE;			/* FIXME implement */
+#elif __DragonFly__
 	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
