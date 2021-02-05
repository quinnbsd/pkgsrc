$NetBSD$

--- src/common_init.c.orig	2019-07-17 16:25:27.000000000 +0000
+++ src/common_init.c
@@ -57,7 +57,7 @@ pci_system_init( void )
 
 #ifdef __linux__
     err = pci_system_linux_sysfs_create();
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
     err = pci_system_freebsd_create();
 #elif defined(__NetBSD__)
     err = pci_system_netbsd_create();
@@ -79,7 +79,7 @@ pci_system_init( void )
 void
 pci_system_init_dev_mem(int fd)
 {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
     pci_system_freebsd_init_dev_mem(fd);
 #elif defined(__OpenBSD__)
     pci_system_openbsd_init_dev_mem(fd);
