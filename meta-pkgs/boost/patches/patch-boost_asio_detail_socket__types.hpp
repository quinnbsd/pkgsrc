$NetBSD$

--- ./boost/asio/detail/socket_types.hpp.orig	2020-12-03 05:01:06.000000000 +0000
+++ ./boost/asio/detail/socket_types.hpp
@@ -60,7 +60,7 @@
 # if (defined(__MACH__) && defined(__APPLE__)) \
    || defined(__FreeBSD__) || defined(__NetBSD__) \
    || defined(__OpenBSD__) || defined(__linux__) \
-   || defined(__EMSCRIPTEN__)
+   || defined(__EMSCRIPTEN__) || defined(__QuinnBSD__)
 #  include <poll.h>
 # elif !defined(__SYMBIAN32__)
 #  include <sys/poll.h>
