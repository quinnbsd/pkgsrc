# $NetBSD: Makefile,v 1.2 2021/01/23 14:23:04 bsiegert Exp $

GITHUB_PROJECT=	nancy
GITHUB_TAG=	v1.0.5
DISTNAME=	v1.0.5
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sonatype-nexus-community/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sonatype-nexus-community/nancy/
COMMENT=	Golang module/dep vulnerability scanner
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/nancy-1.0.5
USE_LANGUAGES=	# none

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} build -o nancy -v

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nancy ${DESTDIR}${PREFIX}/bin/

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
