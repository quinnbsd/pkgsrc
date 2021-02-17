$NetBSD$

--- lib/irrlicht/source/Irrlicht/CIrrDeviceWayland.cpp.orig	2020-01-03 18:47:06.000000000 +0000
+++ lib/irrlicht/source/Irrlicht/CIrrDeviceWayland.cpp
@@ -28,7 +28,7 @@
 #include <unistd.h>
 #include <time.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <dev/evdev/input.h>
 #else
 #include <linux/input.h>
@@ -37,7 +37,7 @@
 #if defined _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #include <sys/joystick.h>
 #else
 #include <linux/joystick.h>
@@ -1674,7 +1674,7 @@ bool CIrrDeviceWayland::activateJoystick
         if (info.fd == -1)
             continue;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
         info.axes=2;
         info.buttons=2;
 #else
@@ -1700,7 +1700,7 @@ bool CIrrDeviceWayland::activateJoystick
         returnInfo.Axes = info.axes;
         returnInfo.Buttons = info.buttons;
 
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
         char name[80];
         ioctl( info.fd, JSIOCGNAME(80), name);
         returnInfo.Name = name;
@@ -1735,7 +1735,7 @@ void CIrrDeviceWayland::pollJoysticks()
     {
         JoystickInfo& info = m_active_joysticks[i];
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
         struct joystick js;
         if (read(info.fd, &js, sizeof(js)) == sizeof(js))
         {
