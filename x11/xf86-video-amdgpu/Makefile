# $NetBSD: Makefile,v 1.19 2020/01/18 23:36:02 rillig Exp $

DISTNAME=	xf86-video-amdgpu-19.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=driver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Modular Xorg ATI (Tonga, Carrizo, Iceland, Fiji, Stoney) driver
LICENSE=	mit AND x11

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ENV.SunOS+=	DRIVER_MAN_SUFFIX=4
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "QuinnBSD"
.include "../../x11/libdrm-quinn/buildlink3.mk"
.else
.include "../../x11/libdrm/buildlink3.mk"
.endif
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
