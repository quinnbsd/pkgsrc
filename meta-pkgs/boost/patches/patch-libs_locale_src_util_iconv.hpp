$NetBSD$

--- ./libs/locale/src/util/iconv.hpp.orig	2020-12-03 05:01:47.000000000 +0000
+++ ./libs/locale/src/util/iconv.hpp
@@ -12,7 +12,7 @@
 
 namespace boost {
     namespace locale {
-#if defined(__ICONV_F_HIDE_INVALID) && defined(__FreeBSD__)
+#if defined(__ICONV_F_HIDE_INVALID) && (defined(__FreeBSD__) || defined(__QuinnBSD__))
         extern "C" {
             typedef size_t (*const_iconv_ptr_type)(iconv_t d,char const **in,size_t *insize,char **out,size_t *outsize,uint32_t,size_t *);
             typedef size_t (*nonconst_iconv_ptr_type)(iconv_t d,char **in,size_t *insize,char **out,size_t *outsize,uint32_t,size_t *);
