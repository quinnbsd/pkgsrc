# $NetBSD$

DISTNAME=	libdrm-2.4.104
PKGNAME=        ${DISTNAME:S/libdrm-/libdrm-quinn-/}
CATEGORIES=	x11
MASTER_SITES=	https://dri.freedesktop.org/libdrm/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	apamment@yandex.com
HOMEPAGE=	https://dri.freedesktop.org/libdrm/
COMMENT=	Userspace interface to kernel DRM services
LICENSE=	mit

USE_TOOLS+=	pkg-config
CONFLICTS+=     libdrm-[0-9]*
TOOL_DEPENDS+=	libpthread-stubs>=0.4:../../devel/libpthread-stubs

PKGCONFIG_OVERRIDE+=	amdgpu/libdrm_amdgpu.pc.in
PKGCONFIG_OVERRIDE+=	etnaviv/libdrm_etnaviv.pc.in
PKGCONFIG_OVERRIDE+=	exynos/libdrm_exynos.pc.in
PKGCONFIG_OVERRIDE+=	freedreno/libdrm_freedreno.pc.in
PKGCONFIG_OVERRIDE+=	intel/libdrm_intel.pc.in
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
PKGCONFIG_OVERRIDE+=	libkms/libkms.pc.in
PKGCONFIG_OVERRIDE+=	nouveau/libdrm_nouveau.pc.in
PKGCONFIG_OVERRIDE+=	omap/libdrm_omap.pc.in
PKGCONFIG_OVERRIDE+=	radeon/libdrm_radeon.pc.in
PKGCONFIG_OVERRIDE+=	tegra/libdrm_tegra.pc.in
PKGCONFIG_OVERRIDE+=	vc4/libdrm_vc4.pc.in

.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
