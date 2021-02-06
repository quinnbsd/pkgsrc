# $NetBSD$

GITHUB_PROJECT=	xf86-video-scfb
GITHUB_TAG=	0.0.6
DISTNAME=	0.0.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=rayddteam/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://github.com/rayddteam/xf86-video-scfb/
COMMENT=	Video driver for FreeBSD syscons framebuffer device
LICENSE=	x11

WRKSRC=		${WRKDIR}/xf86-video-scfb-0.0.6
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
