# $NetBSD$

DISTNAME=	libpthread-stubs-0.4
CATEGORIES=	devel
MASTER_SITES=	https://xcb.freedesktop.org/dist/

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://xcb.freedesktop.org/dist/
COMMENT=	Weak aliases for pthread functions
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	pthread-stubs.pc.in

.include "../../mk/bsd.pkg.mk"
