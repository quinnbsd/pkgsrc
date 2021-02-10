$NetBSD: patch-rts_ProfHeap.c,v 1.1 2021/02/09 13:18:36 ryoon Exp $

--- rts/ProfHeap.c.orig	2021-01-25 16:30:28.000000000 +0000
+++ rts/ProfHeap.c
@@ -69,7 +69,7 @@ static locale_t prof_locale = 0, saved_l
 STATIC_INLINE void
 init_prof_locale( void )
 {
-#if !defined(mingw32_HOST_OS)
+#if !defined(mingw32_HOST_OS) && !defined(netbsd_HOST_OS)
     if (! prof_locale) {
         prof_locale = newlocale(LC_NUMERIC_MASK, "POSIX", 0);
         if (! prof_locale) {
@@ -83,7 +83,7 @@ init_prof_locale( void )
 STATIC_INLINE void
 free_prof_locale( void )
 {
-#if !defined(mingw32_HOST_OS)
+#if !defined(mingw32_HOST_OS) && !defined(netbsd_HOST_OS)
     if (prof_locale) {
         freelocale(prof_locale);
         prof_locale = 0;
@@ -98,6 +98,9 @@ set_prof_locale( void )
     prof_locale_per_thread = _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);
     saved_locale = setlocale(LC_NUMERIC, NULL);
     setlocale(LC_NUMERIC, "C");
+#elif defined(netbsd_HOST_OS)
+    saved_locale = setlocale(LC_NUMERIC, NULL);
+    setlocale(LC_NUMERIC, "C");
 #else
     saved_locale = uselocale(prof_locale);
 #endif
@@ -106,9 +109,11 @@ set_prof_locale( void )
 STATIC_INLINE void
 restore_locale( void )
 {
-#if defined(mingw32_HOST_OS)
+#if !defined(mingw32_HOST_OS) && !defined(netbsd_HOST_OS)
     _configthreadlocale(prof_locale_per_thread);
     setlocale(LC_NUMERIC, saved_locale);
+#elif defined(netbsd_HOST_OS)
+    setlocale(LC_NUMERIC, saved_locale);
 #else
     uselocale(saved_locale);
 #endif
