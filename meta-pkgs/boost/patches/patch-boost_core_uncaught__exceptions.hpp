$NetBSD$

--- ./boost/core/uncaught_exceptions.hpp.orig	2020-12-03 05:01:17.000000000 +0000
+++ ./boost/core/uncaught_exceptions.hpp
@@ -79,7 +79,7 @@
 // command line arguments (-V and/or -Y; http://www.qnx.com/developers/docs/7.0.0/#com.qnx.doc.neutrino.utilities/topic/q/qcc.html). The LLVM libc++abi is missing the declaration
 // of __cxa_get_globals but it is also patched by QNX developers to not define _LIBCPPABI_VERSION. Older QNX SDP versions, up to and including 6.6, don't provide LLVM and libc++abi.
 // See https://github.com/boostorg/core/issues/59.
-#if !defined(__FreeBSD__) && \
+#if !(defined(__FreeBSD__) || defined(__QuinnBSD__)) && \
     ( \
         (defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR__) < 407) || \
         defined(__OpenBSD__) || \
@@ -88,7 +88,7 @@
     )
 namespace __cxxabiv1 {
 struct __cxa_eh_globals;
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || (defined(__NetBSD__) && defined(_LIBCPP_VERSION))
 extern "C" __cxa_eh_globals* __cxa_get_globals();
 #else
 extern "C" __cxa_eh_globals* __cxa_get_globals() BOOST_NOEXCEPT_OR_NOTHROW __attribute__((__const__));
