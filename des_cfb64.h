/*
 * filename: des_cfb64.h
 * author: King's Way <io[AT]stdio.io>
 * date: 20170211
 */ 
#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>

#ifndef _DES_CFB64_H
#define _DES_CFB64_H
char *encrypt( char *key, char *data, int size);
char *decrypt( char *key, char *data, int size);

#endif

