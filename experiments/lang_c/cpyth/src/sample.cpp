#define PY_SIZE_T_CLEAN
#include <Python.h>

static PyObject* add(PyObject* self, PyObject* args) {
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }
    return PyLong_FromLong(a + b);
}

static PyMethodDef MyMethods[] = {
    {"add", add, METH_VARARGS, "Adds two numbers"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef cpyth_mod = {
    PyModuleDef_HEAD_INIT,
    "cpyth_mod", // module name
    NULL, // module doc
    -1, //module state
    MyMethods // methods list
};

// module initialization
PyMODINIT_FUNC PyInit_cpyth_mod(void) {
    return PyModule_Create(&cpyth_mod);
}
