$NetBSD$

--- ./boost/wave/cpplexer/re2clex/cpp_re.hpp.orig	2020-12-03 05:02:42.000000000 +0000
+++ ./boost/wave/cpplexer/re2clex/cpp_re.hpp
@@ -373,7 +373,7 @@ boost::wave::token_id scan(Scanner<Itera
     string_type   rawstringdelim;         // for use with C++11 raw string literals
 
 // include the correct Re2C token definition rules
-#if (defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)) && defined (T_DIVIDE)
+#if (defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__) || defined(__QuinnBSD__)) && defined (T_DIVIDE)
 #undef T_DIVIDE
 #endif
 #if BOOST_WAVE_USE_STRICT_LEXER != 0
