# $NetBSD: Makefile,v 1.44 2020/07/31 14:41:37 maya Exp $

PKGNAME=	xf86-video-intel-2.99.917.20210115
COMMIT_ID=	31486f40f8e8f8923ca0799aea84b58799754564
DISTNAME=	xf86-video-intel-${COMMIT_ID}
CATEGORIES=	x11
#MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
MASTER_SITES=	https://gitlab.freedesktop.org/xorg/driver/xf86-video-intel/-/archive/${COMMIT_ID}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg Intel video driver

CONFLICTS+=	xf86-video-i810-[0-9]*

CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--enable-dri3

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config automake autoconf autoreconf

# Assumes platform compiler has SSE2, etc
ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "QuinnBSD"
BUILDLINK_API_DEPENDS.libdrm-quinn+=  libdrm-quinn>=2.4.104
.else
BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.7
.endif
pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.if ${OPSYS} == "QuinnBSD"
.include "../../x11/libdrm-quinn/buildlink3.mk"
.else
.include "../../x11/libdrm/buildlink3.mk"
.endif
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
