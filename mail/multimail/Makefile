# $NetBSD$

DISTNAME=	mmail-0.52
CATEGORIES=	mail
MASTER_SITES=	https://sourceforge.net/projects/multimail/files/MultiMail/0.52/

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://sourceforge.net/projects/multimail/files/MultiMail/0.52/
COMMENT=	QWK/BlueWave offline mail reader.
LICENSE=	gnu-gpl-v3

CXX=		clang++

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

DEPENDS+=	zip-[0-9]*:../../archivers/zip
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
