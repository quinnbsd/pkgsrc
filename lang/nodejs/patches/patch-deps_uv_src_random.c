$NetBSD$

--- deps/uv/src/random.c.orig	2021-01-04 13:59:33.000000000 +0000
+++ deps/uv/src/random.c
@@ -42,7 +42,7 @@ static int uv__random(void* buf, size_t
     rc = uv__random_devurandom(buf, buflen);
 #elif defined(__NetBSD__)
   rc = uv__random_sysctl(buf, buflen);
-#elif defined(__FreeBSD__) || defined(__linux__)
+#elif defined(__FreeBSD__) || defined(__linux__) || defined(__QuinnBSD__)
   rc = uv__random_getrandom(buf, buflen);
   if (rc == UV_ENOSYS)
     rc = uv__random_devurandom(buf, buflen);
