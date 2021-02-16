$NetBSD$

--- ./boost/asio/detail/config.hpp.orig	2020-12-03 05:01:06.000000000 +0000
+++ ./boost/asio/detail/config.hpp
@@ -1067,7 +1067,9 @@
 #  if defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#    if __has_include(<experimental/string_view>)
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#    endif // __has_include(<experimental/string_view>)
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
@@ -1339,7 +1341,7 @@
    || defined(_XOPEN_SOURCE) \
    || defined(_POSIX_SOURCE) \
    || (defined(__MACH__) && defined(__APPLE__)) \
-   || defined(__FreeBSD__) \
+   || defined(__FreeBSD__) || defined(__QuinnBSD__) \
    || defined(__NetBSD__) \
    || defined(__OpenBSD__) \
    || defined(__linux__) \
@@ -1380,7 +1382,7 @@
 
 // Mac OS X, FreeBSD, NetBSD, OpenBSD: kqueue.
 #if (defined(__MACH__) && defined(__APPLE__)) \
-  || defined(__FreeBSD__) \
+  || defined(__FreeBSD__) || defined(__QuinnBSD__) \
   || defined(__NetBSD__) \
   || defined(__OpenBSD__)
 # if !defined(BOOST_ASIO_HAS_KQUEUE)
