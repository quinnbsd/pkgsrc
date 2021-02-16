$NetBSD$

--- ./boost/asio/detail/impl/socket_ops.ipp.orig	2020-12-03 05:01:06.000000000 +0000
+++ ./boost/asio/detail/impl/socket_ops.ipp
@@ -118,7 +118,7 @@ socket_type accept(socket_type s, socket
   if (new_s == invalid_socket)
     return new_s;
 
-#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
   int optval = 1;
   int result = ::setsockopt(new_s, SOL_SOCKET,
       SO_NOSIGPIPE, &optval, sizeof(optval));
@@ -1823,7 +1823,7 @@ socket_type socket(int af, int type, int
   }
 
   return s;
-#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__) || defined(__QuinnBSD__)
   socket_type s = ::socket(af, type, protocol);
   get_last_error(ec, s < 0);
 
@@ -1915,7 +1915,7 @@ int setsockopt(socket_type s, state_type
   {
 #if defined(__MACH__) && defined(__APPLE__) \
   || defined(__NetBSD__) || defined(__FreeBSD__) \
-  || defined(__OpenBSD__) || defined(__QNX__)
+  || defined(__OpenBSD__) || defined(__QNX__) || defined(__QuinnBSD__)
     // To implement portable behaviour for SO_REUSEADDR with UDP sockets we
     // need to also set SO_REUSEPORT on BSD-based platforms.
     if ((state & datagram_oriented)
@@ -2125,7 +2125,7 @@ int ioctl(socket_type s, state_type& sta
 #if defined(BOOST_ASIO_WINDOWS) || defined(__CYGWIN__)
   int result = ::ioctlsocket(s, cmd, arg);
 #elif defined(__MACH__) && defined(__APPLE__) \
-  || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+  || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
   int result = ::ioctl(s, static_cast<unsigned int>(cmd), arg);
 #else
   int result = ::ioctl(s, cmd, arg);
