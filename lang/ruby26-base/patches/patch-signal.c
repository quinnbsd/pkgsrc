$NetBSD$

--- ./signal.c.orig	2020-03-31 11:23:13.000000000 +0000
+++ ./signal.c
@@ -824,7 +824,7 @@ NORETURN(void rb_ec_stack_overflow(rb_ex
 #   define USE_UCONTEXT_REG 1
 # elif defined __APPLE__
 #   define USE_UCONTEXT_REG 1
-# elif defined __FreeBSD__
+# elif defined __FreeBSD__ || defined __QuinnBSD__
 #   define USE_UCONTEXT_REG 1
 # endif
 #if defined(HAVE_PTHREAD_SIGMASK)
@@ -874,7 +874,7 @@ check_stack_overflow(int sig, const uint
     const uintptr_t sp = mctx->MCTX_SS_REG(esp);
     const uintptr_t bp = mctx->MCTX_SS_REG(ebp);
 #   endif
-# elif defined __FreeBSD__
+# elif defined __FreeBSD__ || defined __QuinnBSD__
 #   if defined(__amd64__)
     const __register_t sp = mctx->mc_rsp;
     const __register_t bp = mctx->mc_rbp;
