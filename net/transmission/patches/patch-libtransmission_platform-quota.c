$NetBSD$

--- libtransmission/platform-quota.c.orig	2020-05-22 11:04:23.390804854 +0000
+++ libtransmission/platform-quota.c
@@ -15,7 +15,7 @@
 #ifndef _WIN32
 #include <unistd.h> /* getuid() */
 #include <sys/types.h> /* types needed by quota.h */
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QuinnBSD__)
 #include <ufs/ufs/quota.h> /* quotactl() */
 #elif defined(__DragonFly__)
 #include <vfs/ufs/quota.h> /* quotactl */
@@ -324,7 +324,7 @@ static int64_t getquota(char const* devi
     int64_t freespace;
     int64_t spaceused;
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__) || defined(__QuinnBSD__)
     if (quotactl(device, QCMD(Q_GETQUOTA, USRQUOTA), getuid(), (caddr_t)&dq) == 0)
     {
 #elif defined(__sun)
@@ -362,7 +362,7 @@ static int64_t getquota(char const* devi
             return -1;
         }
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__QuinnBSD__)
         spaceused = (int64_t)dq.dqb_curblocks >> 1;
 #elif defined(__APPLE__)
         spaceused = (int64_t)dq.dqb_curbytes;
