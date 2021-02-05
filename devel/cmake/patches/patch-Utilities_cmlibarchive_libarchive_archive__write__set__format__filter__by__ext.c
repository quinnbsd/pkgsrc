$NetBSD$

--- Utilities/cmlibarchive/libarchive/archive_write_set_format_filter_by_ext.c.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibarchive/libarchive/archive_write_set_format_filter_by_ext.c
@@ -50,7 +50,7 @@ struct { const char *name; int (*format)
 	{ ".jar",	archive_write_set_format_zip,             archive_write_add_filter_none},
 	{ ".cpio",	archive_write_set_format_cpio,            archive_write_add_filter_none},
 	{ ".iso",	archive_write_set_format_iso9660,         archive_write_add_filter_none},
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 	{ ".a",	        archive_write_set_format_ar_bsd,          archive_write_add_filter_none},
 	{ ".ar",	archive_write_set_format_ar_bsd,          archive_write_add_filter_none},
 #else         
