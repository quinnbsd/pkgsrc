# $NetBSD: Makefile,v 1.16 2021/01/16 13:00:27 triaxx Exp $

DISTNAME=	stun-1.0.40
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/stun/
COMMENT=	STUN and TURN library for Erlang / Elixir
LICENSE=	apache-2.0

DEPENDS+=	erlang-fast_tls>=1.1.10:../../security/erlang-fast_tls
DEPENDS+=	erlang-p1_utils>=1.0.21:../../misc/erlang-p1_utils

GITHUB_PROJECT=	stun

BUILD_TARGET=	src

# Leave a non-versioned symlink in place for net/erlang-esip to find
post-install:
	${LN} -sf ${DISTNAME} ${DESTDIR}${PREFIX}/lib/erlang/lib/stun

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
