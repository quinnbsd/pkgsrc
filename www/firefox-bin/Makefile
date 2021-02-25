# $NetBSD$

DISTNAME=	firefox-86.0_1,2
PKGNAME=	firefox-86.0
CATEGORIES=	lang
MASTER_SITES=	http://ftp.quinnbsd.org/pub/QuinnBSD/packages/distfiles/
EXTRACT_SUFX=	.txz
PKGREVISION=	2

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://www.mozilla.org/en-US/firefox/
COMMENT=	Binary verision of firefox
LICENSE=	mpl-1.1
PKG_CONFIG=	yes

DEPENDS+=	libevent>=1.1:../../devel/libevent
DEPENDS+=	nspr>=4.26:../../devel/nspr
DEPENDS+=	icu-[0-9]*:../../textproc/icu
DEPENDS+=	nss>=3.60:../../devel/nss
DEPENDS+=	libwebp-[0-9]*:../../graphics/libwebp
DEPENDS+=	dav1d>=0.8.1:../../multimedia/dav1d
DEPENDS+=	pciutils-[0-9]*:../../sysutils/pciutils
DEPENDS+=	graphite2-[0-9]*:../../graphics/graphite2
DEPENDS+=	libvpx-[0-9]*:../../multimedia/libvpx

TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

do-extract:
	cd ${WRKSRC} && tar -xzvf ${DISTDIR}/${DISTFILES}

do-build:
	patchelf --set-rpath /usr/pkg/lib:/usr/pkg/lib/nspr:/usr/pkg/lib/nss ${WRKSRC}/usr/local/lib/firefox/libxul.so
	patchelf --set-rpath /usr/pkg/lib ${WRKSRC}/usr/local/lib/firefox/libmozgtk.so
	patchelf --set-rpath /usr/pkg/lib:/usr/pkg/lib/ffmpeg4 ${WRKSRC}/usr/local/lib/firefox/firefox

do-install:
	rm ${WRKSRC}/usr/local/bin/firefox
	ln -s /usr/pkg/lib/firefox/firefox ${WRKSRC}/usr/local/bin/firefox
	cp -a ${WRKSRC}/usr/local/* ${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
