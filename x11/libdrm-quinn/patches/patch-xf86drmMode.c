$NetBSD$

--- xf86drmMode.c.orig	2021-01-11 18:15:27.391364000 +0000
+++ xf86drmMode.c
@@ -795,7 +795,7 @@ drm_public int drmCheckModesettingSuppor
 	closedir(sysdir);
 	if (found)
 		return 0;
-#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
+#elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined(__QuinnBSD__)
 	char sbusid[1024];
 	char oid[128];
 	int i, modesetting, ret;
