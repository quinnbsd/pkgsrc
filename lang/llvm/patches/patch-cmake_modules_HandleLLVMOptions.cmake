$NetBSD$

--- cmake/modules/HandleLLVMOptions.cmake.orig	2020-07-07 16:21:37.000000000 +0000
+++ cmake/modules/HandleLLVMOptions.cmake
@@ -181,7 +181,7 @@ endif()
 
 # Pass -Wl,-z,defs. This makes sure all symbols are defined. Otherwise a DSO
 # build might work on ELF but fail on MachO/COFF.
-if(NOT (${CMAKE_SYSTEM_NAME} MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|AIX|SunOS" OR
+if(NOT (${CMAKE_SYSTEM_NAME} MATCHES "Darwin|FreeBSD|OpenBSD|DragonFly|AIX|SunOS|QuinnBSD" OR
         WIN32 OR CYGWIN) AND
    NOT LLVM_USE_SANITIZER)
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-z,defs")
