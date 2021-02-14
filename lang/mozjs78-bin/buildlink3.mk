# $NetBSD: buildlink3.mk,v 1.2 2020/11/10 11:31:25 nia Exp $

BUILDLINK_TREE+=	mozjs78-bin

.if !defined(MOZJS78-BIN_BUILDLINK3_MK)
MOZJS78-BIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozjs78-bin+=	mozjs78-bin>=78.3.0
BUILDLINK_ABI_DEPENDS.mozjs78-bin?=	mozjs78-bin>=78.3.0
BUILDLINK_PKGSRCDIR.mozjs78-bin?=	../../lang/mozjs78-bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.endif	# MOZJS78-BIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozjs78-bin
