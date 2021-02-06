$NetBSD$

--- src/bsd_mouse.c.orig	2018-06-19 04:36:21.000000000 +0000
+++ src/bsd_mouse.c
@@ -70,7 +70,7 @@ static void usbSigioReadInput (int fd, v
 #endif
 static const char *FindDevice(InputInfoPtr, const char *, int);
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 /* These are for FreeBSD and DragonFly */
 #define DEFAULT_MOUSE_DEV               "/dev/mouse"
 #define DEFAULT_SYSMOUSE_DEV            "/dev/sysmouse"
@@ -97,7 +97,7 @@ static const char *mouseDevs[] = {
 static int
 SupportedInterfaces(void)
 {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QuinnBSD__)
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
 #else
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_XPS2 | MSE_AUTO | MSE_MISC;
@@ -120,7 +120,7 @@ static const char *internalNames[] = {
  * main "mouse" driver.
  */
 static const char *miscNames[] = {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
         "SysMouse",
 #endif
         NULL
@@ -149,7 +149,7 @@ CheckProtocol(const char *protocol)
 static const char *
 DefaultProtocol(void)
 {
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
     return "Auto";
 #elif (defined(__OpenBSD__) || defined(__NetBSD__)) && defined(WSCONS_SUPPORT)
     return "WSMouse";
@@ -158,7 +158,7 @@ DefaultProtocol(void)
 #endif
 }
 
-#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)) && defined(MOUSE_PROTO_SYSMOUSE)
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)) && defined(MOUSE_PROTO_SYSMOUSE)
 static struct {
         int dproto;
         const char *name;
@@ -227,7 +227,7 @@ SetSysMouseRes(InputInfoPtr pInfo, const
     mode.rate = rate > 0 ? rate : -1;
     mode.resolution = res > 0 ? res : -1;
     mode.accelfactor = -1;
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
     if (pMse->autoProbe ||
         (protocol && xf86NameCmp(protocol, "SysMouse") == 0)) {
         /*
@@ -245,7 +245,7 @@ SetSysMouseRes(InputInfoPtr pInfo, const
 }
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
 
 #define MOUSED_PID_FILE "/var/run/moused.pid"
 
@@ -784,7 +784,7 @@ OSMouseInit(int flags)
     p->BuiltinNames = BuiltinNames;
     p->DefaultProtocol = DefaultProtocol;
     p->CheckProtocol = CheckProtocol;
-#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)) && defined(MOUSE_PROTO_SYSMOUSE)
+#if (defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)) && defined(MOUSE_PROTO_SYSMOUSE)
     p->SetupAuto = SetupAuto;
     p->SetPS2Res = SetSysMouseRes;
     p->SetBMRes = SetSysMouseRes;
@@ -794,7 +794,7 @@ OSMouseInit(int flags)
     p->SetupAuto = SetupAuto;
     p->SetMiscRes = SetMouseRes;
 #endif
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__QuinnBSD__)
     p->FindDevice = FindDevice;
 #endif
     p->PreInit = bsdMousePreInit;
