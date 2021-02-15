# $NetBSD$

DISTNAME=	x264-0.161.3039
PKGNAME=	x264-git-0.161.3039
CATEGORIES=	multimedia
MASTER_SITES=	https://code.videolan.org/videolan/x264/-/archive/544c61f082194728d0391fb280a6e138ba320a96/

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://code.videolan.org/videolan/x264/-/archive/544c61f082194728d0391fb280a6e138ba320a96/
COMMENT=	H.264/MPEG-4 AVC Video Encoding
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/x264-544c61f082194728d0391fb280a6e138ba320a96

BUILD_DEPENDS+=         nasm>=2.13.0:../../devel/nasm


HAS_CONFIGURE=	yes
USE_TOOLS+=	bash gmake
HAS_CONFIGURE=          yes
CONFIG_SHELL=           ${BASH}
CONFIGURE_ARGS+=        --enable-shared
CONFIGURE_ARGS+=        --enable-static
CONFIGURE_ARGS+=        --enable-pic
CONFIGURE_ARGS+=        --prefix=${PREFIX}
CONFIGURE_ARGS+=        --disable-opencl

BUILD_TARGET=           default
INSTALL_TARGET=         install-lib-shared install-lib-static install-cli
INSTALLATION_DIRS=      bin
REPLACE_SH=             version.sh
.include "../../mk/dlopen.buildlink3.mk"

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no

.if !empty(USE_BUILTIN.pthread:M[Yy][Ee][Ss])
X264_BUILD_THREADS_SUPPORT=     yes
.else
X264_BUILD_THREADS_SUPPORT=     ${DLOPEN_REQUIRE_PTHREADS}
.endif

.include "../../mk/bsd.pkg.mk"
