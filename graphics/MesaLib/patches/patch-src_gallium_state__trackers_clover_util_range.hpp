$NetBSD$

--- src/gallium/state_trackers/clover/util/range.hpp.orig	2020-04-29 22:48:24.000000000 +0000
+++ src/gallium/state_trackers/clover/util/range.hpp
@@ -362,6 +362,14 @@ namespace clover {
       return { i, i + n };
    }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+   namespace detail {
+      template<typename T>
+      using fixup_function_type =
+         typename std::conditional<std::is_function<T>::value, T &, T>::type;
+   }
+#endif
+
    ///
    /// Create a range by transforming the contents of a number of
    /// source ranges \a rs element-wise using a provided functor \a f.
@@ -369,7 +377,11 @@ namespace clover {
    /// \sa adaptor_range.
    ///
    template<typename F, typename... Rs>
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__QuinnBSD__)
+   adaptor_range<detail::fixup_function_type<F>, Rs...>
+#else
    adaptor_range<F, Rs...>
+#endif
    map(F &&f, Rs &&... rs) {
       return { std::forward<F>(f), std::forward<Rs>(rs)... };
    }
