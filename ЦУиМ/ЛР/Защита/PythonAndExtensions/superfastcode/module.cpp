#include <Python.h>
#include <Windows.h>
#include <cmath>

const double e = 2.7182818284590452353602874713527;

PyObject* tanh_impl(PyObject* /* unused module reference */, PyObject* o) {
    double x = PyFloat_AsDouble(o);
    double tanh_x = (sin(x) / cos(x) + sin(x))/powf(e,x);
    return PyFloat_FromDouble(tanh_x);
}

static PyMethodDef superfastcode_methods[] = {
    { "fast_function", (PyCFunction)tanh_impl, METH_O, nullptr },
    { nullptr, nullptr, 0, nullptr }
};

static PyModuleDef superfastcode_module = {
    PyModuleDef_HEAD_INIT,
    "superfastcode",                        // Module name to use with Python import statements
    "Provides some functions, but faster",  // Module description
    0,
    superfastcode_methods                   // Structure that defines the methods of the module
};

PyMODINIT_FUNC PyInit_superfastcode() {
    return PyModule_Create(&superfastcode_module);
}