# $NetBSD: Makefile,v 1.17 2021/02/26 18:02:24 ryoon Exp $

DISTNAME=	link-grammar-5.8.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://www.abisource.com/downloads/link-grammar/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.abisource.com/projects/link-grammar/
COMMENT=	Syntactic parsing library
LICENSE=	modified-bsd AND gnu-lgpl-v2.1

USE_LANGUAGES=	c99 c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-java-bindings
CONFIGURE_ARGS+=	--disable-python-bindings

PKGCONFIG_OVERRIDE+=	link-grammar.pc.in

# Not all currently supported compilers provide this option.
# The configure script purports to check whether the compiler
# supports it, but doesn't do so correctly.
BUILDLINK_TRANSFORM+=	rm:-Wformat-signedness

.include "../../mk/bsd.pkg.mk"
