# $NetBSD: Makefile,v 1.11 2021/02/09 10:06:43 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-nsone-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-nsone/}

COMMENT=	NS1 DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=0.31.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=1.1.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=2.2.1:../../net/py-lexicon
DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.0.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
