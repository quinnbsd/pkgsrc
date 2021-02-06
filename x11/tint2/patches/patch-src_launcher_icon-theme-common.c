$NetBSD$

--- src/launcher/icon-theme-common.c.orig	2019-07-15 06:15:40.000000000 +0000
+++ src/launcher/icon-theme-common.c
@@ -61,7 +61,8 @@ const GSList *get_icon_locations()
     icon_locations = g_slist_append(icon_locations, g_build_filename(g_get_home_dir(), ".local/share/icons", NULL));
 
     icon_locations = load_locations_from_env(icon_locations, "XDG_DATA_DIRS", ".icons", ".pixmaps", NULL);
-
+    icon_locations = g_slist_append(icon_locations, g_strdup("/usr/pkg/share/icons"));
+    icon_locations = g_slist_append(icon_locations, g_strdup("/usr/pkg/share/pixmaps"));
     icon_locations = g_slist_append(icon_locations, g_strdup("/usr/local/share/icons"));
     icon_locations = g_slist_append(icon_locations, g_strdup("/usr/local/share/pixmaps"));
     icon_locations = g_slist_append(icon_locations, g_strdup("/usr/share/icons"));
