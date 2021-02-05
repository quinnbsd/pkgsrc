$NetBSD$

--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2020-04-29 22:48:24.000000000 +0000
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -76,7 +76,7 @@ vmw_region_size(struct vmw_region *regio
 }
 
 #if defined(__DragonFly__) || defined(__FreeBSD__) || \
-    defined(__NetBSD__) || defined(__OpenBSD__)
+    defined(__NetBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #define ERESTART EINTR
 #endif
 
@@ -694,7 +694,9 @@ vmw_ioctl_region_map(struct vmw_region *
 	 return NULL;
       }
 
+#ifdef MADV_HUGEPAGE
       (void) madvise(map, region->size, MADV_HUGEPAGE);
+#endif
       region->data = map;
    }
 
