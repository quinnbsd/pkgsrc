$NetBSD$

--- Modules/socketmodule.c.orig	2020-04-19 21:13:39.000000000 +0000
+++ Modules/socketmodule.c
@@ -272,7 +272,7 @@ http://cvsweb.netbsd.org/bsdweb.cgi/src/
 /* Irix 6.5 fails to define this variable at all. This is needed
    for both GCC and SGI's compiler. I'd say that the SGI headers
    are just busted. Same thing for Solaris. */
-#if (defined(__sgi) || defined(sun)) && !defined(INET_ADDRSTRLEN)
+#if (defined(__sgi) || defined(sun) || defined(_SCO_DS)) && !defined(INET_ADDRSTRLEN)
 #define INET_ADDRSTRLEN 16
 #endif
 
@@ -410,7 +410,7 @@ const char *inet_ntop(int af, const void
 
 #if (defined(HAVE_BLUETOOTH_H) || defined(HAVE_BLUETOOTH_BLUETOOTH_H)) && !defined(__NetBSD__) && !defined(__DragonFly__)
 #define USE_BLUETOOTH 1
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)/
 #define BTPROTO_L2CAP BLUETOOTH_PROTO_L2CAP
 #define BTPROTO_RFCOMM BLUETOOTH_PROTO_RFCOMM
 #define BTPROTO_HCI BLUETOOTH_PROTO_HCI
@@ -1169,7 +1169,7 @@ makesockaddr(int sockfd, struct sockaddr
 #endif /* !(__NetBSD__ || __DragonFly__) */
         }
 
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
         case BTPROTO_SCO:
         {
             struct sockaddr_sco *a = (struct sockaddr_sco *) addr;
@@ -1479,7 +1479,7 @@ getsockaddrarg(PySocketSockObject *s, Py
             *len_ret = sizeof *addr;
             return 1;
         }
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
         case BTPROTO_SCO:
         {
             struct sockaddr_sco *addr;
@@ -1677,7 +1677,7 @@ getsockaddrlen(PySocketSockObject *s, so
         case BTPROTO_HCI:
             *len_ret = sizeof (struct sockaddr_hci);
             return 1;
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
         case BTPROTO_SCO:
             *len_ret = sizeof (struct sockaddr_sco);
             return 1;
@@ -4821,7 +4821,7 @@ init_socket(void)
 #if !defined(__NetBSD__) && !defined(__DragonFly__)
     PyModule_AddIntConstant(m, "HCI_FILTER", HCI_FILTER);
 #endif
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__QuinnBSD__)
 #if !defined(__NetBSD__) && !defined(__DragonFly__)
     PyModule_AddIntConstant(m, "HCI_TIME_STAMP", HCI_TIME_STAMP);
 #endif
