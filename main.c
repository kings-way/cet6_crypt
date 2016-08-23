#include<stdio.h>
#include<string.h>
#include<fcntl.h>

#include "des_cfb64.h"

int main(int argc, char **argv)
{
	if (argc < 3)
		return 0;
	char *encrypt_key = "QghdW;O;";
	char *decrypt_key = "121yO7d=";
	char *result = NULL;

	if(strcmp("encrypt",argv[1])==0)
		result = Encrypt(encrypt_key,argv[2],strlen(argv[2]));
	else if(strcmp("decrypt",argv[1])==0)
		result = Decrypt(decrypt_key,argv[2],strlen(argv[2]));
	
	int j=0;
	for(j=0;j<strlen(result);j++)
		printf("%c", result[j]);
	
	// 
	//printf("\n\n");
	//for(j=0;j<strlen(result);j++)
	//	printf("%02x", result[j]&0xff);
	
	return 0;
}
