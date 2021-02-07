$NetBSD$

--- include/llvm/MC/MCELFObjectWriter.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ include/llvm/MC/MCELFObjectWriter.h
@@ -78,6 +78,7 @@ public:
         return ELF::ELFOSABI_STANDALONE;
       case Triple::PS4:
       case Triple::FreeBSD:
+      case Triple::QuinnBSD:
         return ELF::ELFOSABI_FREEBSD;
       default:
         return ELF::ELFOSABI_NONE;
