#include <string.h>
#include <stdlib.h>
#include <openssl/des.h>

#ifndef _DES_CFB64_H
#define _DES_CFB64_H
extern char * Encrypt( char *Key, char *Msg, int size);
extern char * Decrypt( char *Key, char *Msg, int size);

#endif

