$NetBSD: patch-vendor_openssl-src_src_lib.rs,v 1.2 2021/02/14 08:24:31 he Exp $

Provide defaults for the various NetBSD targets.

--- vendor/openssl-src/src/lib.rs.orig	2020-12-29 03:36:31.000000000 +0000
+++ vendor/openssl-src/src/lib.rs
@@ -167,6 +167,7 @@ impl Build {
             "aarch64-unknown-freebsd" => "BSD-generic64",
             "aarch64-unknown-linux-gnu" => "linux-aarch64",
             "aarch64-unknown-linux-musl" => "linux-aarch64",
+            "aarch64-unknown-netbsd" => "BSD-generic64",
             "aarch64-pc-windows-msvc" => "VC-WIN64-ARM",
             "arm-linux-androideabi" => "linux-armv4",
             "armv7-linux-androideabi" => "linux-armv4",
@@ -178,6 +179,7 @@ impl Build {
             "armv7-unknown-freebsd" => "BSD-generic32",
             "armv7-unknown-linux-gnueabihf" => "linux-armv4",
             "armv7-unknown-linux-musleabihf" => "linux-armv4",
+            "armv7-unknown-netbsd-eabihf" => "BSD-generic32",
             "asmjs-unknown-emscripten" => "gcc",
             "i586-unknown-linux-gnu" => "linux-elf",
             "i586-unknown-linux-musl" => "linux-elf",
@@ -188,6 +190,7 @@ impl Build {
             "i686-unknown-freebsd" => "BSD-x86-elf",
             "i686-unknown-linux-gnu" => "linux-elf",
             "i686-unknown-linux-musl" => "linux-elf",
+            "i686-unknown-netbsd" => "BSD-x86-elf",
             "mips-unknown-linux-gnu" => "linux-mips32",
             "mips-unknown-linux-musl" => "linux-mips32",
             "mips64-unknown-linux-gnuabi64" => "linux64-mips64",
@@ -195,12 +198,14 @@ impl Build {
             "mipsel-unknown-linux-gnu" => "linux-mips32",
             "mipsel-unknown-linux-musl" => "linux-mips32",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
+            "powerpc-unknown-netbsd" => "BSD-generic32",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
             "powerpc64le-unknown-freebsd" => "BSD-generic64",
             "powerpc64le-unknown-linux-gnu" => "linux-ppc64le",
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
+            "sparc64-unknown-netbsd" => "BSD-generic64",
             "x86_64-apple-darwin" => "darwin64-x86_64-cc",
             "x86_64-linux-android" => "linux-x86_64",
             "x86_64-pc-windows-gnu" => "mingw64",
