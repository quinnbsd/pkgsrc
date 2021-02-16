$NetBSD$

--- ./libs/asio/test/ip/multicast.cpp.orig	2020-12-03 05:01:07.000000000 +0000
+++ ./libs/asio/test/ip/multicast.cpp
@@ -145,16 +145,19 @@ void test()
 
 #if (defined(__MACH__) && defined(__APPLE__)) \
   || defined(__FreeBSD__) \
+  || defined(__QuinnBSD__) \
   || defined(__NetBSD__) \
   || defined(__OpenBSD__)
   const ip::address multicast_address_v6 = ip::make_address("ff02::1%lo0", ec);
 #else // (defined(__MACH__) && defined(__APPLE__))
       //   || defined(__FreeBSD__)
+      //   || defined(__QuinnBSD__) 
       //   || defined(__NetBSD__)
       //   || defined(__OpenBSD__)
   const ip::address multicast_address_v6 = ip::make_address("ff01::1", ec);
 #endif // (defined(__MACH__) && defined(__APPLE__))
        //   || defined(__FreeBSD__)
+       //   || defined(__QuinnBSD__)
        //   || defined(__NetBSD__)
        //   || defined(__OpenBSD__)
   BOOST_ASIO_CHECK(!have_v6 || !ec);
