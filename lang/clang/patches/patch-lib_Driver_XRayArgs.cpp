$NetBSD$

--- ./lib/Driver/XRayArgs.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/Driver/XRayArgs.cpp
@@ -50,6 +50,7 @@ XRayArgs::XRayArgs(const ToolChain &TC,
             << (std::string(XRayInstrumentOption) + " on " + Triple.str());
       }
     } else if (Triple.isOSFreeBSD() ||
+               Triple.isOSQuinnBSD() ||
                Triple.isOSOpenBSD() ||
                Triple.isOSNetBSD() ||
                Triple.isMacOSX()) {
