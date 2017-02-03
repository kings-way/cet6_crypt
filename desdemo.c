#include <stdio.h>
#include <string.h>
#include "des_cfb64.h"
#include <Python.h>

int main()
{
	printf("Hello\n");
	return 0;
}

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

	PyArg_ParseTuple(args, "ss", &key, &data); // TODO: Find out why we must use '&' here....
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

	PyArg_ParseTuple(args, "ss", &key, &data); // TODO: Find out why we must use '&' here....
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

