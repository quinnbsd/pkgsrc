$NetBSD$

--- tools/specialize_node_d.py.orig	2021-01-04 13:59:36.000000000 +0000
+++ tools/specialize_node_d.py
@@ -22,7 +22,7 @@ arch = sys.argv[4]
 model = r'curpsinfo->pr_dmodel == PR_MODEL_ILP32'
 
 for line in infile:
-  if flavor == 'freebsd':
+  if flavor == 'freebsd' or flavor == 'quinnbsd':
     line = re.sub('procfs.d', 'psinfo.d', line)
     if arch == 'x64':
       line = re.sub(model, '0', line)
