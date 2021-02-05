$NetBSD$

--- src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c.orig	2020-04-29 22:48:24.000000000 +0000
+++ src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c
@@ -249,6 +249,16 @@ pipe_loader_drm_probe_fd(struct pipe_loa
    return ret;
 }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QuinnBSD__)
+static int
+open_drm_minor(int minor)
+{
+   char path[PATH_MAX];
+   snprintf(path, sizeof(path), DRM_DEV_NAME, DRM_DIR_NAME, minor);
+   return open(path, O_RDWR, 0);
+}
+#endif
+
 static int
 open_drm_render_node_minor(int minor)
 {
@@ -261,7 +271,19 @@ open_drm_render_node_minor(int minor)
 int
 pipe_loader_drm_probe(struct pipe_loader_device **devs, int ndev)
 {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QuinnBSD__)
+   int i, k, fd, num_render_node_devs;
+   int j = 0;
+
+   struct {
+      unsigned vendor_id;
+      unsigned chip_id;
+   } render_node_devs[DRM_RENDER_NODE_MAX_NODES];
+
+   /* Look for render nodes first */
+#else
    int i, j, fd;
+#endif
 
    for (i = DRM_RENDER_NODE_MIN_MINOR, j = 0;
         i <= DRM_RENDER_NODE_MAX_MINOR; i++) {
@@ -276,6 +298,11 @@ pipe_loader_drm_probe(struct pipe_loader
          continue;
       }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QuinnBSD__)
+      render_node_devs[j].vendor_id = dev->u.pci.vendor_id;
+      render_node_devs[j].chip_id = dev->u.pci.chip_id;
+
+#endif
       if (j < ndev) {
          devs[j] = dev;
       } else {
@@ -285,6 +312,48 @@ pipe_loader_drm_probe(struct pipe_loader
       j++;
    }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QuinnBSD__)
+   num_render_node_devs = j;
+
+   /* Next look for drm devices. */
+   for (i = 0; i < DRM_MAX_MINOR; i++) {
+      struct pipe_loader_device *dev;
+      boolean duplicate = FALSE;
+      fd = open_drm_minor(i);
+      if (fd < 0)
+         continue;
+
+      if (!pipe_loader_drm_probe_fd(&dev, fd)) {
+         close(fd);
+         continue;
+      }
+
+      /* Check to make sure we aren't already accessing this device via
+       * render nodes.
+       */
+      for (k = 0; k < num_render_node_devs; k++) {
+         if (dev->u.pci.vendor_id == render_node_devs[k].vendor_id &&
+             dev->u.pci.chip_id == render_node_devs[k].chip_id) {
+            close(fd);
+            dev->ops->release(&dev);
+            duplicate = TRUE;
+            break;
+         }
+      }
+
+      if (duplicate)
+         continue;
+
+      if (j < ndev) {
+         devs[j] = dev;
+      } else {
+         dev->ops->release(&dev);
+      }
+
+      j++;
+   }
+
+#endif
    return j;
 }
 
