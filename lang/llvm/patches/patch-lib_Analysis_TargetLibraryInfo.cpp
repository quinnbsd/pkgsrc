$NetBSD$

--- lib/Analysis/TargetLibraryInfo.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ lib/Analysis/TargetLibraryInfo.cpp
@@ -60,7 +60,7 @@ static bool hasBcmp(const Triple &TT) {
     return TT.isGNUEnvironment() || TT.isMusl();
   // Both NetBSD and OpenBSD are planning to remove the function. Windows does
   // not have it.
-  return TT.isOSFreeBSD() || TT.isOSSolaris();
+  return TT.isOSFreeBSD() || TT.isOSSolaris() || TT.isOSQuinnBSD();
 }
 
 /// Initialize the set of available library functions based on the specified
@@ -414,6 +414,7 @@ static void initialize(TargetLibraryInfo
   case Triple::TvOS:
   case Triple::WatchOS:
   case Triple::FreeBSD:
+  case Triple::QuinnBSD:
   case Triple::Linux:
     break;
   default:
@@ -430,6 +431,7 @@ static void initialize(TargetLibraryInfo
   case Triple::TvOS:
   case Triple::WatchOS:
   case Triple::FreeBSD:
+  case Triple::QuinnBSD:
   case Triple::Linux:
     break;
   default:
@@ -440,7 +442,7 @@ static void initialize(TargetLibraryInfo
   // http://svn.freebsd.org/base/head/lib/libc/string/fls.c
   // http://svn.freebsd.org/base/head/lib/libc/string/flsl.c
   // http://svn.freebsd.org/base/head/lib/libc/string/flsll.c
-  if (!T.isOSFreeBSD()) {
+  if (!T.isOSFreeBSD() && !T.isOSQuinnBSD()) {
     TLI.setUnavailable(LibFunc_fls);
     TLI.setUnavailable(LibFunc_flsl);
     TLI.setUnavailable(LibFunc_flsll);
