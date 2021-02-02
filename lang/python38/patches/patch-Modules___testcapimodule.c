$NetBSD$

--- Modules/_testcapimodule.c.orig	2020-12-21 16:25:24.000000000 +0000
+++ Modules/_testcapimodule.c
@@ -3271,7 +3271,7 @@ test_from_contiguous(PyObject* self, PyO
     Py_RETURN_NONE;
 }
 
-#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__GNUC__)
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(__GNUC__)
 extern PyTypeObject _PyBytesIOBuffer_Type;
 
 static PyObject *
@@ -5153,7 +5153,7 @@ static PyMethodDef TestMethods[] = {
      METH_NOARGS},
     {"test_capsule", (PyCFunction)test_capsule, METH_NOARGS},
     {"test_from_contiguous", (PyCFunction)test_from_contiguous, METH_NOARGS},
-#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__GNUC__)
+#if (defined(__linux__) || defined(__FreeBSD__) || defined(__QuinnBSD__)) && defined(__GNUC__)
     {"test_pep3118_obsolete_write_locks", (PyCFunction)test_pep3118_obsolete_write_locks, METH_NOARGS},
 #endif
     {"getbuffer_with_null_view", getbuffer_with_null_view, METH_O},
