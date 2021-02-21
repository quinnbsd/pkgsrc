$NetBSD$

--- exempi/exempi.cpp.orig	2019-07-28 02:00:48.000000000 +0000
+++ exempi/exempi.cpp
@@ -70,7 +70,7 @@ static void set_error(int err)
 #include <pthread.h>
 
 /* Portable thread local storage using pthreads */
-static pthread_key_t key = NULL;
+static pthread_key_t key = 0;
 static pthread_once_t key_once = PTHREAD_ONCE_INIT;
 
 /* Destructor called when a thread exits - ensure to delete allocated int
