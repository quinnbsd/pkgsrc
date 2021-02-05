$NetBSD$

--- src/util/futex.h.orig	2020-04-29 22:48:25.000000000 +0000
+++ src/util/futex.h
@@ -51,7 +51,7 @@ static inline int futex_wait(uint32_t *a
                     FUTEX_BITSET_MATCH_ANY);
 }
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__QuinnBSD__)
 
 #include <assert.h>
 #include <errno.h>
