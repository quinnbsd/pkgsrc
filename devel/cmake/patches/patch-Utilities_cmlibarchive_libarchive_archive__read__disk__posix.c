$NetBSD$

--- Utilities/cmlibarchive/libarchive/archive_read_disk_posix.c.orig	2021-01-28 15:28:45.000000000 +0000
+++ Utilities/cmlibarchive/libarchive/archive_read_disk_posix.c
@@ -2168,7 +2168,7 @@ tree_reopen(struct tree *t, const char *
 #elif defined(O_SEARCH)
 	/* SunOS */
 	const int o_flag = O_SEARCH;
-#elif defined(__FreeBSD__) && defined(O_EXEC)
+#elif (defined(__FreeBSD__) || defined(__QuinnBSD__))  && defined(O_EXEC)
 	/* FreeBSD */
 	const int o_flag = O_EXEC;
 #endif
@@ -2195,7 +2195,7 @@ tree_reopen(struct tree *t, const char *
 	t->maxOpenCount = t->openCount = 1;
 	t->initial_dir_fd = open(".", O_RDONLY | O_CLOEXEC);
 #if defined(O_PATH) || defined(O_SEARCH) || \
- (defined(__FreeBSD__) && defined(O_EXEC))
+ ((defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(O_EXEC))
 	/*
 	 * Most likely reason to fail opening "." is that it's not readable,
 	 * so try again for execute. The consequences of not opening this are
