# $NetBSD: Makefile,v 1.20 2021/02/03 15:44:35 taca Exp $

DISTNAME=	mechanize-2.7.7
CATEGORIES=	www

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/sparklemotion/mechanize
COMMENT=	Library to automate interaction with websites
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-http-digest_auth>=1.1.1:../../www/ruby-net-http-digest_auth
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=2.5.2:../../www/ruby-net-http-persistent
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.17.2:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-domain_name>=0.5.1<1:../../net/ruby-domain_name
DEPENDS+=	${RUBY_PKGPREFIX}-http-cookie>=1.0<2:../../www/ruby-http-cookie
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.6<2:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-ntlm-http>=0.1<1:../../www/ruby-ntlm-http
DEPENDS+=	${RUBY_PKGPREFIX}-webrobots>=0.0<0.2:../../www/ruby-webrobots
DEPENDS+=	${RUBY_PKGPREFIX}-webrick>=1.7<2:../../www/ruby-webrick

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
