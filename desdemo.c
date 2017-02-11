/*
 * filename: desdemo.c
 * author: King's Way <root#kings-way.info>
 * date: 20170211
 */ 
#include <stdio.h>
#include <string.h>
#include "des_cfb64.h"
#include <python2.7/Python.h>

char *hello()
{
	return "Hello, World";
}

static PyObject* __hello(PyObject* self, PyObject* args)
{
	return Py_BuildValue("s", hello());
}


static PyObject* __des_cfb64_encrypt(PyObject* self, PyObject* args)
{		
	char *key;
	char *data;
	int size;

	PyArg_ParseTuple(args, "ss", &key, &data); 
	size=strlen(data);
//	printf("Key:%s, Data:%s\n", key,data);
	char *result = encrypt(key, data, size);

	return Py_BuildValue("s", result);
}

static PyObject* __des_cfb64_decrypt(PyObject* self, PyObject* args)
{		
	char *key;
	char *data;
	int size;

	PyArg_ParseTuple(args, "ss", &key, &data);
	size=strlen(data);
	char *result = decrypt(key, data, size);

	return Py_BuildValue("s", result);
}


static PyMethodDef ExtendMethods[] = 
{
	{"hello", __hello, METH_VARARGS, "HelloWorld() from C"},
	{"des_cfb64_encrypt", __des_cfb64_encrypt, METH_VARARGS, "DES_CFB64_Encrypt() from OpenSSL"},
	{"des_cfb64_decrypt", __des_cfb64_decrypt, METH_VARARGS, "DES_CFB64_Decrypt() from OpenSSL"},
	{NULL, NULL, 0, NULL},
};

PyMODINIT_FUNC initdesdemo(){
	Py_InitModule("desdemo", ExtendMethods);
}

