# $NetBSD$

GITHUB_PROJECT=	mlogind
GITHUB_TAG=	v1.3.8
DISTNAME=	v1.3.8
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=MidnightBSD/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://github.com/MidnightBSD/mlogind/
COMMENT=	mlogind is a fork of SLiM maintained by MidnightBSD
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/mlogind-1.3.8
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DUSE_PAM=1
CMAKE_ARGS+=	-DUSE_CONSOLEKIT=1

post-install:
	install -m755 -d ${DESTDIR}${PREFIX}/share/examples/mlogind
	cp ${WRKSRC}/pam.conf.freebsd.sample ${DESTDIR}${PREFIX}/share/examples/mlogind/mlogind.pam.conf
	cp ${FILESDIR}/mlogind.theme ${DESTDIR}${PREFIX}/share/mlogind/themes/default/mlogind.theme
	cp ${FILESDIR}/background.png ${DESTDIR}${PREFIX}/share/mlogind/themes/default/background.png
	cp ${FILESDIR}/panel.png ${DESTDIR}${PREFIX}/share/mlogind/themes/default/panel.png
	rm ${DESTDIR}${PREFIX}/share/mlogind/themes/default/background.jpg

.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
