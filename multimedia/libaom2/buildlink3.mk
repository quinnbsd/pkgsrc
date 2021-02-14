# $NetBSD: buildlink3.mk,v 1.1 2018/09/30 18:58:16 maya Exp $

BUILDLINK_TREE+=	libaom2

.if !defined(LIBAOM2_BUILDLINK3_MK)
LIBAOM2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libaom2+=	libaom2>=2.0.2
BUILDLINK_PKGSRCDIR.libaom2?=	../../multimedia/libaom2
.endif	# LIBAOM2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libaom2
