# $NetBSD: Makefile,v 1.42 2021/03/02 03:34:36 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.9.8
DISTNAME=	xfce4-screenshooter-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/

HOMEPAGE=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/
COMMENT=	Xfce screenshoot application

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
