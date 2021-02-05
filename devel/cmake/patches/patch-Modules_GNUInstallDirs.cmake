$NetBSD$

--- Modules/GNUInstallDirs.cmake.orig	2021-01-28 15:28:45.000000000 +0000
+++ Modules/GNUInstallDirs.cmake
@@ -288,7 +288,7 @@ _GNUInstallDirs_cache_path(CMAKE_INSTALL
 _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_DATADIR "${CMAKE_INSTALL_DATAROOTDIR}"
   "Read-only architecture-independent data (DATAROOTDIR)")
 
-if(CMAKE_SYSTEM_NAME MATCHES "^(([^kF].*)?BSD|DragonFly)$")
+if(CMAKE_SYSTEM_NAME MATCHES "^(([^kF].*)?BSD|DragonFly|QuinnBSD)$")
   _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_INFODIR "info"
     "Info documentation (info)")
 else()
@@ -296,7 +296,7 @@ else()
     "Info documentation (DATAROOTDIR/info)")
 endif()
 
-if(CMAKE_SYSTEM_NAME MATCHES "^(([^k].*)?BSD|DragonFly)$")
+If(CMAKE_SYSTEM_NAME MATCHES "^(([^k].*)?BSD|DragonFly|QuinnBSD)$")
   _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_MANDIR "man"
     "Man documentation (man)")
 else()
