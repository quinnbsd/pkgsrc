$NetBSD$

--- source/Irrlicht/CIrrDeviceLinux.cpp.orig	2016-05-26 10:09:34.000000000 +0000
+++ source/Irrlicht/CIrrDeviceLinux.cpp
@@ -32,7 +32,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/joystick.h>
 #else
 
@@ -1673,7 +1673,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		if (-1 == info.fd)
 			continue;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 		info.axes=2;
 		info.buttons=2;
 #else
@@ -1697,7 +1697,7 @@ bool CIrrDeviceLinux::activateJoysticks(
 		returnInfo.Axes = info.axes;
 		returnInfo.Buttons = info.buttons;
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 		char name[80];
 		ioctl( info.fd, JSIOCGNAME(80), name);
 		returnInfo.Name = name;
@@ -1732,7 +1732,7 @@ void CIrrDeviceLinux::pollJoysticks()
 	{
 		JoystickInfo & info =  ActiveJoysticks[j];
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && !defined(__QuinnBSD__)
 		struct joystick js;
 		if (read(info.fd, &js, sizeof(js)) == sizeof(js))
 		{
