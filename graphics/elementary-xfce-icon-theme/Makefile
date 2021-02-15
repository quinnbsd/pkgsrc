# $NetBSD: Makefile,v 1.7 2018/05/15 21:30:55 youri Exp $

GHCOMMIT=	2e2ca316322f9c69a8fb5d555f42d121ba5412b4
DISTNAME=	${GHCOMMIT}
PKGNAME=	elementary-xfce-icon-theme-0.15.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shimmerproject/elementary-xfce/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/shimmerproject/elementary-xfce
COMMENT=	Elementary icons forked, extended and maintained for Xfce
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS=	optipng-[0-9]*:../../graphics/optipng

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/elementary-xfce-${GHCOMMIT}

FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${LOCALBASE}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${PREFIX}/share/icons"
INSTALL_TEMPLATES+=	../../graphics/elementary-xfce-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/elementary-xfce-icon-theme/files/icon-cache.tmpl
PRINT_PLIST_AWK+=	/^share\/icons\/elementary-xfce\/icon-theme.cache$$/ { next; }
PRINT_PLIST_AWK+=	/^share\/icons\/elementary-xfce-dark\/icon-theme.cache$$/ { next; }
PRINT_PLIST_AWK+=	/^share\/icons\/elemantary-xfce-darker\/icon-theme.cache$$/ { next; }

INSTALLATION_DIRS+=	share/icons

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
