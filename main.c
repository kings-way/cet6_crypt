#include<stdio.h>
#include<string.h>
#include<fcntl.h>

#include "des_cfb64.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		return 0;

	// the 2 keys here are not a pair or something...
	// the 'encrypt_key' is to encrypt the data before sent to the server.
	// the 'decrypt_key' is to decrypt the data from the server.
//	char *encrypt_key = "QghdW;O;";
//	char *decrypt_key = "121yO7d=";
	char *encrypt_key = "test1234";
	char *decrypt_key = "test1234";
	char *result = NULL;

	printf("Len of input:%d\n", strlen(argv[2]));
	if(strcmp("encrypt",argv[1])==0)
		result = cipher(encrypt_key,argv[2],strlen(argv[2]));
	else if(strcmp("decrypt",argv[1])==0)
		result = cipher(decrypt_key,argv[2],strlen(argv[2]));
	
	int j=0;
	for(j=0;j<strlen(result);j++)
		printf("%c", result[j]);
	
	// 
	//printf("\n\n");
	//for(j=0;j<strlen(result);j++)
	//	printf("%02x", result[j]&0xff);
	
	return 0;
}
