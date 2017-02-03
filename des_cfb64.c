#include"des_cfb64.h"

char *encrypt( char *key, char *data, int size)
{
	int n = 0;
    static char* result;
	result = (char *)malloc(size);
    des_cblock	block;
    des_key_schedule schedule;

    memcpy(block, key, 8);
    DES_set_odd_parity(&block);
    DES_set_key_checked(&block, &schedule);

    DES_cfb64_encrypt(data, result, size, &schedule, &block, &n, DES_ENCRYPT);


	return result;
}

char *decrypt( char *key, char *data, int size)
{
	int n = 0;
    static char* result;
	result = (char *)malloc(size);
    des_cblock	block;
    des_key_schedule schedule;

    memcpy(block, key, 8);
    DES_set_odd_parity(&block);
    DES_set_key_checked(&block, &schedule);

    DES_cfb64_encrypt(data, result, size, &schedule, &block, &n, DES_DECRYPT);

	return result;
}

