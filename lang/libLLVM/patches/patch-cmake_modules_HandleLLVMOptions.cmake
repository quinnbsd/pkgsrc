$NetBSD$

--- cmake/modules/HandleLLVMOptions.cmake.orig	2019-12-11 19:15:30.000000000 +0000
+++ cmake/modules/HandleLLVMOptions.cmake
@@ -191,7 +191,7 @@ endif()
 
 # Pass -Wl,-z,defs. This makes sure all symbols are defined. Otherwise a DSO
 # build might work on ELF but fail on MachO/COFF.
-if(NOT (${CMAKE_SYSTEM_NAME} MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|AIX" OR
+if(NOT (${CMAKE_SYSTEM_NAME} MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|AIX|QuinnBSD" OR
         WIN32 OR CYGWIN) AND
    NOT LLVM_USE_SANITIZER)
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
