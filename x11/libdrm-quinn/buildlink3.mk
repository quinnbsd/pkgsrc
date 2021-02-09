# $NetBSD: buildlink3.mk,v 1.7 2013/05/16 05:43:14 richard Exp $

BUILDLINK_TREE+=	libdrm-quinn

.if !defined(LIBDRM_BUILDLINK3_MK)
LIBDRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdrm-quinn+=	libdrm-quinn>=2.4.104
BUILDLINK_PKGSRCDIR.libdrm-quinn?=	../../x11/libdrm-quinn
BUILDLINK_INCDIRS.libdrm-quinn?=	include/libdrm
.endif # LIBDRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdrm-quinn
