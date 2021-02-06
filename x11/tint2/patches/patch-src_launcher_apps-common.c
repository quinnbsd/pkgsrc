$NetBSD$

--- src/launcher/apps-common.c.orig	2019-07-15 06:15:40.000000000 +0000
+++ src/launcher/apps-common.c
@@ -316,6 +316,7 @@ const GSList *get_apps_locations()
 
     apps_locations = load_locations_from_env(apps_locations, "XDG_DATA_DIRS", "applications", NULL);
 
+    apps_locations = g_slist_append(apps_locations, g_strdup("/usr/pkg/share/applications"));
     apps_locations = g_slist_append(apps_locations, g_strdup("/usr/local/share/applications"));
     apps_locations = g_slist_append(apps_locations, g_strdup("/usr/share/applications"));
     apps_locations = g_slist_append(apps_locations, g_strdup("/opt/share/applications"));
