# $NetBSD: Makefile,v 1.2 2021/02/27 20:14:02 ryoon Exp $

DISTNAME=	libime-1.0.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/libime/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/libime
COMMENT=	Generic inputmethod implementation library
LICENSE=	gnu-lgpl-v2.1

DIST_SUBDIR=	${PKGNAME_NOREV}

DICTDISTFILES+=	lm_sc.3gm.arpa-20140820.tar.bz2
DICTDISTFILES+=	dict.utf8-20200715.tar.xz
DICTDISTFILES+=	table.tar.gz

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}
.for f in ${DICTDISTFILES}
DISTFILES+=	${f}
SITES.${f}=	https://download.fcitx-im.org/data/
.endfor

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

post-extract:
.for f in ${DICTDISTFILES}
	cd ${WRKSRC}/data && \
		${LN} -sf ${DISTDIR}/${DIST_SUBDIR}/${f} ${f}
.endfor

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
