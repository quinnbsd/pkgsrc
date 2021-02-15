# $NetBSD$

DISTNAME=	MagiTerm-1.1.2
CATEGORIES=	net
MASTER_SITES=	https://gitlab.com/magickabbs/MagiTerm/-/archive/5536c938e0525eb9e9eb60762d3a4fa1ad0fe1f0/

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://blog.talismanbbs.com/magiterm/
COMMENT=	Telnet / SSH BBS Terminal
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/MagiTerm-5536c938e0525eb9e9eb60762d3a4fa1ad0fe1f0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../security/libssh/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
