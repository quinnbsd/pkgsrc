$NetBSD$

--- hald/freebsd/hf-usb2.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/hf-usb2.c
@@ -98,10 +98,10 @@ hf_usb2_probe_interfaces(HalDevice *pare
 	  if (driver)
             {
 	      if (! strcmp(driver, "ukbd"))
-                hf_device_set_input(device, "keyboard", NULL);
+                hf_device_set_input(device, "keyboard", "keys", NULL);
 	      else if (! strcmp(driver, "ums"))
                 {
-                  hf_device_set_input(device, "mouse", devname);
+                  hf_device_set_input(device, "mouse", NULL, devname);
 	          hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
 	        }
 	      else if (! strcmp(driver, "uhid"))
