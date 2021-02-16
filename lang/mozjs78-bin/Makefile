# $NetBSD$

DISTNAME=	spidermonkey78-78.6.0_1
PKGNAME=	mozjs78-bin-78.6.0
CATEGORIES=	lang
MASTER_SITES=	http://ftp.quinnbsd.org/pub/QuinnBSD/packages/distfiles/
EXTRACT_SUFX=	.txz

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://mozilla-spidermonkey.github.io/
COMMENT=	Binary verision of mozjs48
LICENSE=	mpl-1.1
PKG_CONFIG=	yes

TOOL_DEPENDS+=  patchelf-[0-9]*:../../devel/patchelf

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

do-extract:
	cd ${WRKSRC} && tar -xzvf ${DISTDIR}/${DISTFILES}

do-build:
	rm -rf ${WRKSRC}/usr/local/libdata
	mkdir ${WRKSRC}/usr/local/lib/pkgconfig
	cp ${FILESDIR}/mozjs-78.pc ${WRKSRC}/usr/local/lib/pkgconfig
	patchelf --set-rpath /usr/pkg/lib:/usr/pkg/lib/nspr ${WORKSRC}/usr/local/lib/libmozjs-78.so

do-install:
	cp -a ${WRKSRC}/usr/local/* ${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
