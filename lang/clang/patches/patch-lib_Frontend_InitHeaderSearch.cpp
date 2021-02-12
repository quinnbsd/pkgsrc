$NetBSD$

--- ./lib/Frontend/InitHeaderSearch.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Frontend/InitHeaderSearch.cpp
@@ -225,12 +225,14 @@ void InitHeaderSearch::AddDefaultCInclud
     switch (os) {
     case llvm::Triple::CloudABI:
     case llvm::Triple::FreeBSD:
+    case llvm::Triple::QuinnBSD:
     case llvm::Triple::NetBSD:
     case llvm::Triple::OpenBSD:
     case llvm::Triple::NaCl:
     case llvm::Triple::PS4:
     case llvm::Triple::ELFIAMCU:
     case llvm::Triple::Fuchsia:
+    case llvm::Triple::Solaris:
       break;
     case llvm::Triple::Win32:
       if (triple.getEnvironment() != llvm::Triple::Cygnus)
