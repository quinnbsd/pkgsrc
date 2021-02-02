$NetBSD$

--- Modules/socketmodule.c.orig	2020-12-21 16:25:24.000000000 +0000
+++ Modules/socketmodule.c
@@ -489,7 +489,7 @@ remove_unusable_flags(PyObject *m)
 
 #if (defined(HAVE_BLUETOOTH_H) || defined(HAVE_BLUETOOTH_BLUETOOTH_H)) && !defined(__NetBSD__) && !defined(__DragonFly__)
 #define USE_BLUETOOTH 1
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 #define BTPROTO_L2CAP BLUETOOTH_PROTO_L2CAP
 #define BTPROTO_RFCOMM BLUETOOTH_PROTO_RFCOMM
 #define BTPROTO_HCI BLUETOOTH_PROTO_HCI
@@ -1429,7 +1429,7 @@ makesockaddr(SOCKET_T sockfd, struct soc
 #endif /* !(__NetBSD__ || __DragonFly__) */
         }
 
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
         case BTPROTO_SCO:
         {
             struct sockaddr_sco *a = (struct sockaddr_sco *) addr;
@@ -1954,7 +1954,7 @@ getsockaddrarg(PySocketSockObject *s, Py
             *len_ret = sizeof *addr;
             return 1;
         }
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
         case BTPROTO_SCO:
         {
             struct sockaddr_sco *addr;
@@ -2405,7 +2405,7 @@ getsockaddrlen(PySocketSockObject *s, so
         case BTPROTO_HCI:
             *len_ret = sizeof (struct sockaddr_hci);
             return 1;
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
         case BTPROTO_SCO:
             *len_ret = sizeof (struct sockaddr_sco);
             return 1;
@@ -7291,7 +7291,7 @@ PyInit__socket(void)
 #if !defined(__NetBSD__) && !defined(__DragonFly__)
     PyModule_AddIntMacro(m, HCI_FILTER);
 #endif
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 #if !defined(__NetBSD__) && !defined(__DragonFly__)
     PyModule_AddIntMacro(m, HCI_TIME_STAMP);
 #endif
@@ -7700,6 +7700,20 @@ PyInit__socket(void)
     PyModule_AddIntConstant(m, "CAN_BCM_CAN_FD_FRAME", CAN_FD_FRAME);
 #endif
 #endif
+#ifdef HAVE_NETCAN_CAN_H
+    PyModule_AddIntMacro(m, CAN_EFF_FLAG);
+    PyModule_AddIntMacro(m, CAN_RTR_FLAG);
+    PyModule_AddIntMacro(m, CAN_ERR_FLAG);
+
+    PyModule_AddIntMacro(m, CAN_SFF_MASK);
+    PyModule_AddIntMacro(m, CAN_EFF_MASK);
+    PyModule_AddIntMacro(m, CAN_ERR_MASK);
+
+    PyModule_AddIntMacro(m, CAN_RAW_FILTER);
+    /* PyModule_AddIntMacro(m, CAN_RAW_ERR_FILTER); */
+    PyModule_AddIntMacro(m, CAN_RAW_LOOPBACK);
+    PyModule_AddIntMacro(m, CAN_RAW_RECV_OWN_MSGS);
+#endif
 #ifdef SOL_RDS
     PyModule_AddIntMacro(m, SOL_RDS);
 #endif
