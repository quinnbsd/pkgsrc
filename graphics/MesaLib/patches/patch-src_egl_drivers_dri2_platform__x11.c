$NetBSD$

--- src/egl/drivers/dri2/platform_x11.c.orig	2020-04-29 22:48:24.000000000 +0000
+++ src/egl/drivers/dri2/platform_x11.c
@@ -635,6 +635,23 @@ dri2_x11_local_authenticate(struct dri2_
    return EGL_TRUE;
 }
 
+#if (defined(__APPLE__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__-0 < 1070)
+static char *
+strndup(const char *s, int length)
+{
+   char *d;
+
+   d = malloc(length + 1);
+   if (d == NULL)
+      return NULL;
+
+   memcpy(d, s, length);
+   d[length] = '\0';
+
+   return d;
+}
+#endif
+
 static EGLBoolean
 dri2_x11_connect(struct dri2_egl_display *dri2_dpy)
 {
@@ -1550,8 +1567,15 @@ dri2_initialize_x11(_EGLDriver *drv, _EG
 
    if (!disp->Options.ForceSoftware) {
 #ifdef HAVE_DRI3
-      if (!env_var_as_boolean("LIBGL_DRI3_DISABLE", false))
+#if ((defined(__FreeBSD__) || defined(__FreeBSD_kernel__)) && !defined(__DRM_NEXT__)) || defined(__DragonFly__) || defined(__NetBSD__) || (defined(__QuinnBSD__) && !defined(__DRM_NEXT__))
+      if (env_var_as_boolean("LIBGL_DRI3_ENABLE", false))
+#endif
+      if (!env_var_as_boolean("LIBGL_DRI3_DISABLE", false)) {
+         _eglLog(_EGL_INFO, "platform_x11.c: calling dri2_initialize_x11_dri3\n");
          initialized = dri2_initialize_x11_dri3(drv, disp);
+         if (initialized)
+            _eglLog(_EGL_INFO, "platform_x11.c: initialized by dri2_initialize_x11_dri3\n");
+      }
 #endif
 
       if (!initialized)
