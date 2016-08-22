cc = gcc
cflags = -static
objects = main.o des_cfb64.o

main: $(objects)
	cc $(cflags) -o main $(objects) -I/usr/include/openssl -lcrypto

main.o: main.c
	cc $(cflags) -c main.c

des_cfb64.o: des_cfb64.c des_cfb64.h
	cc $(cflags) -c des_cfb64.c

test:main
	tmp=`echo -n "type=2&provice=32&school=南京信息工程大学&name=张三&examroom=&m=77-88-99-11-22-33" | iconv -t gbk | xargs ./main encrypt` ;\
	echo ;\
	echo $$tmp | xargs ./main decrypt | iconv -f gbk

.PHONY : clean
clean :
	-rm $(objects)
	rm main
