BUILDLINK_TREE+=        libsysinfo

.if !defined(LIBSYSINFO_BUILDLINK3_MK)
LIBSYSINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsysinfo+=    libsysinfo>=0.0.3
BUILDLINK_ABI_DEPENDS.libsysinfo+=    libsysinfo>=0.0.3
BUILDLINK_PKGSRCDIR.libsysinfo?=      ../../devel/libsysinfo
.endif # LIBSYSINFO_BUILDLINK3_MK

BUILDLINK_TREE+=        -libsysinfo

