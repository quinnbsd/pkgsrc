# $NetBSD: Makefile,v 1.2 2021/02/11 10:30:55 adam Exp $

DISTNAME=	cutadapt-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cutadapt/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cutadapt.readthedocs.io/en/stable/
COMMENT=	Find and remove adapter sequences, primers, poly-A tails, etc
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dnaio>=0.5.0:../../biology/py-dnaio
DEPENDS+=	${PYPKGPREFIX}-xopen>=1.0.0:../../devel/py-xopen

PYTHON_VERSIONS_INCOMPATIBLE=	27 36 # py-xopen, dataclasses

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} cutadapt cutadapt-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
