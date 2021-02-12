$NetBSD$

--- ./ext/socket/option.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./ext/socket/option.c
@@ -13,7 +13,8 @@ VALUE rb_cSockOpt;
     defined(__DragonFly__) || \
     defined(__APPLE__) || \
     defined(_WIN32) || \
-    defined(__CYGWIN__)
+    defined(__CYGWIN__) || \
+    defined(__QuinnBSD__)
 # define TYPE_IP_MULTICAST_LOOP int
 # define TYPE_IP_MULTICAST_TTL int
 #else
@@ -812,7 +813,7 @@ inspect_ipv6_mreq(int level, int optname
 
 #if defined(IPPROTO_TCP) && defined(TCP_INFO) && defined(HAVE_TYPE_STRUCT_TCP_INFO)
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__QuinnBSD__)
 # ifndef HAVE_CONST_TCP_ESTABLISHED
 #  define TCP_ESTABLISHED TCPS_ESTABLISHED
 # endif
@@ -928,7 +929,7 @@ inspect_tcpi_usec(VALUE ret, const char
     rb_str_catf(ret, "%s%u.%06us", prefix, t / 1000000, t % 1000000);
 }
 
-#if !defined __FreeBSD__ && ( \
+#if !(defined __FreeBSD__ || defined __QuinnBSD__) && ( \
     defined HAVE_STRUCT_TCP_INFO_TCPI_LAST_DATA_SENT || \
     defined HAVE_STRUCT_TCP_INFO_TCPI_LAST_DATA_RECV || \
     defined HAVE_STRUCT_TCP_INFO_TCPI_LAST_ACK_SENT  || \
@@ -941,7 +942,7 @@ inspect_tcpi_msec(VALUE ret, const char
 }
 #endif
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __QuinnBSD__
 # define inspect_tcpi_rto(ret, t) inspect_tcpi_usec(ret, " rto=", t)
 # define inspect_tcpi_last_data_recv(ret, t) inspect_tcpi_usec(ret, " last_data_recv=", t)
 # define inspect_tcpi_rtt(ret, t) inspect_tcpi_usec(ret, " rtt=", t)
