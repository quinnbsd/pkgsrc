$NetBSD$

--- ./tools/hal-system-sonypic.c.orig	2009-05-15 16:28:34.000000000 +0000
+++ ./tools/hal-system-sonypic.c
@@ -63,7 +63,7 @@
 static int
 sonypi_get_lcd_brightness (__u8 *val)
 {
-#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
@@ -163,7 +163,7 @@ error_set:
 static int
 sonypi_set_lcd_brightness (__u8 val)
 {
-#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
@@ -195,7 +195,7 @@ sonypi_set_lcd_brightness (__u8 val)
 static int
 sonypi_set_bluetooth_power (int val)
 {
-#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__QuinnBSD__)
 	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
