#include<stdio.h>
#include<string.h>
#include<fcntl.h>

#include "des_cfb64.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return 0;
	//int fd = open("input.txt", O_RDONLY);	
	//char msg[100] = {};
	//read(fd, msg, 100);
	
	//char *key = "> buvOQ^";
	char *key = "QghdW;O;";

	char *result = Encrypt(key,argv[1],strlen(argv[1]));
	
	int j=0;
	for(j=0;j<strlen(result);j++)
		printf("%c", result[j]);
	
	printf("\n\n");
	
	for(j=0;j<strlen(result);j++)
		printf("%02x", result[j]&0xff);
	
	return 0;
}
