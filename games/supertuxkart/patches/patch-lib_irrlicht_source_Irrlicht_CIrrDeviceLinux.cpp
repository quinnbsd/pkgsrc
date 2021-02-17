$NetBSD$

--- lib/irrlicht/source/Irrlicht/CIrrDeviceLinux.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/CIrrDeviceLinux.cpp
@@ -48,7 +48,7 @@ extern bool GLContextDebugBit;
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/joystick.h>
 #elif defined(__linux__)
 
@@ -2675,7 +2675,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		if (-1 == info.fd)
 			continue;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 		info.axes=2;
 		info.buttons=2;
 #elif defined(__linux__)
@@ -2700,7 +2700,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		returnInfo.Axes = info.axes;
 		returnInfo.Buttons = info.buttons;
 
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__QuinnBSD__)
 		char name[80] = {0};
 		ioctl( info.fd, JSIOCGNAME(80), name);
 		returnInfo.Name = name;
@@ -2736,7 +2736,7 @@ void CIrrDeviceLinux::pollJoysticks()
 		JoystickInfo & info =  ActiveJoysticks[j];
 		bool event_received = false;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 		struct joystick js;
 		if (read(info.fd, &js, sizeof(js)) == sizeof(js))
 		{
