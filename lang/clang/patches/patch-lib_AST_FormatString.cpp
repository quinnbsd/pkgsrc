$NetBSD$

--- ./lib/AST/FormatString.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ ./lib/AST/FormatString.cpp
@@ -762,7 +762,7 @@ bool FormatSpecifier::hasValidLengthModi
           return true;
         case ConversionSpecifier::FreeBSDrArg:
         case ConversionSpecifier::FreeBSDyArg:
-          return Target.getTriple().isOSFreeBSD() || Target.getTriple().isPS4();
+          return Target.getTriple().isOSFreeBSD() || Target.getTriple().isPS4() || Target.getTriple().isOSQuinnBSD();
         default:
           return false;
       }
@@ -797,7 +797,7 @@ bool FormatSpecifier::hasValidLengthModi
           return true;
         case ConversionSpecifier::FreeBSDrArg:
         case ConversionSpecifier::FreeBSDyArg:
-          return Target.getTriple().isOSFreeBSD() || Target.getTriple().isPS4();
+          return Target.getTriple().isOSFreeBSD() || Target.getTriple().isPS4() || Target.getTriple().isOSQuinnBSD();
         default:
           return false;
       }
