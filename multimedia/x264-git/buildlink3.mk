# $NetBSD: buildlink3.mk,v 1.15 2018/02/25 21:57:43 adam Exp $
BUILDLINK_TREE+=        x264-git 

.if !defined(X264_GIT_BUILDLINK3_MK)
X264_GIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.x264-git+=        x264-git>=0.161.3039 # X264_BUILD 152
BUILDLINK_PKGSRCDIR.x264-git?=  ../../multimedia/x264-git  
pkgbase:= x264-git  

.  include "../../mk/pthread.buildlink3.mk"
.endif # X264_GIT_BUILDLINK3_MK
BUILDLINK_TREE+=	-x264-git
