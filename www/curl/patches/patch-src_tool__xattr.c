$NetBSD$

--- src/tool_xattr.c.orig	2020-12-07 08:24:14.000000000 +0000
+++ src/tool_xattr.c
@@ -24,7 +24,7 @@
 #ifdef HAVE_FSETXATTR
 #  include <sys/xattr.h> /* header from libc, not from libattr */
 #  define USE_XATTR
-#elif defined(__FreeBSD_version) && (__FreeBSD_version > 500000)
+#elif (defined(__FreeBSD_version) && (__FreeBSD_version > 500000)) || defined(__QuinnBSD__)
 #  include <sys/types.h>
 #  include <sys/extattr.h>
 #  define USE_XATTR
@@ -110,7 +110,7 @@ int fwrite_xattr(CURL *curl, int fd)
         err = fsetxattr(fd, mappings[i].attr, value, strlen(value), 0, 0);
 #elif defined(HAVE_FSETXATTR_5)
         err = fsetxattr(fd, mappings[i].attr, value, strlen(value), 0);
-#elif defined(__FreeBSD_version)
+#elif defined(__FreeBSD_version) || defined(__QuinnBSD_version)
         {
           ssize_t rc = extattr_set_fd(fd, EXTATTR_NAMESPACE_USER,
                                       mappings[i].attr, value, strlen(value));
