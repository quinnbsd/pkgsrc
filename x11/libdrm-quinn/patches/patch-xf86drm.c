$NetBSD$

--- xf86drm.c.orig	2021-01-11 18:15:27.391364000 +0000
+++ xf86drm.c
@@ -62,7 +62,7 @@
 #endif
 #include <math.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/param.h>
 #include <sys/pciio.h>
 #endif
@@ -540,7 +540,7 @@ static int drmGetMinorBase(int type)
 
 static int drmGetMinorType(int major, int minor)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
     char name[SPECNAMELEN];
     int id;
 
@@ -2791,7 +2791,7 @@ drm_public int drmIsMaster(int fd)
 
 drm_public char *drmGetDeviceNameFromFd(int fd)
 {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
     struct stat sbuf;
     int maj, min;
     int nodetype;
@@ -2838,7 +2838,7 @@ static bool drmNodeIsDRM(int maj, int mi
     snprintf(path, sizeof(path), "/sys/dev/char/%d:%d/device/drm",
              maj, min);
     return stat(path, &sbuf) == 0;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     char name[SPECNAMELEN];
 
     if (!devname_r(makedev(maj, min), S_IFCHR, name, sizeof(name)))
@@ -2951,7 +2951,7 @@ static char *drmGetMinorNameForFD(int fd
 
     closedir(sysdir);
     return NULL;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     struct stat sbuf;
     char dname[SPECNAMELEN];
     const char *mname;
@@ -3136,7 +3136,7 @@ static int drmParseSubsystemType(int maj
             return DRM_BUS_VIRTIO;
      }
     return subsystem_type;
-#elif defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__)
+#elif defined(__OpenBSD__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
     return DRM_BUS_PCI;
 #else
 #warning "Missing implementation of drmParseSubsystemType"
@@ -3162,7 +3162,7 @@ get_pci_path(int maj, int min, char *pci
 }
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 static int get_sysctl_pci_bus_info(int maj, int min, drmPciBusInfoPtr info)
 {
     char dname[SPECNAMELEN];
@@ -3271,7 +3271,7 @@ static int drmParsePciBusInfo(int maj, i
     info->func = pinfo.func;
 
     return 0;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     return get_sysctl_pci_bus_info(maj, min, info);
 #else
 #warning "Missing implementation of drmParsePciBusInfo"
@@ -3440,7 +3440,7 @@ static int drmParsePciDeviceInfo(int maj
     device->subdevice_id = pinfo.subdevice_id;
 
     return 0;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     drmPciBusInfo info;
     struct pci_conf_io pc;
     struct pci_match_conf patterns[1];
@@ -4318,7 +4318,7 @@ drm_public char *drmGetDeviceNameFromFd2
     free(value);
 
     return strdup(path);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
     return drmGetDeviceNameFromFd(fd);
 #else
     struct stat      sbuf;
