# $NetBSD: Makefile,v 1.33 2020/01/18 23:36:04 rillig Exp $

DISTNAME=	xf86-video-nv-2.1.21
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg NVIDIA video driver
LICENSE=	mit AND modified-bsd

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4

.include "../../x11/modular-xorg-server/buildlink3.mk"

.if ${OPSYS} == "QuinnBSD"
.include "../../x11/libdrm-quinn/buildlink3.mk"
.else
.include "../../x11/libdrm/buildlink3.mk"
.endif
BUILDLINK_DEPMETHOD.libXext?=	build
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
