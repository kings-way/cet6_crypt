cc = gcc
cflags = -static
objects_c = des_cfb64.o main.o
objects_py = des_cfb64.o desdemo.o

main.o: main.c
	cc $(cflags) -c main.c

des_cfb64.o: des_cfb64.c des_cfb64.h
	cc $(cflags) -fPIC -c des_cfb64.c 

c: main.o des_cfb64.o
	cc $(cflags) -o main $(objects_c) -I/usr/include/openssl -lcrypto



desdemo.o: desdemo.c
	cc $(cflags) -fPIC -c desdemo.c -I/usr/include/python2.7

desdemo.so: desdemo.o des_cfb64.o
	cc -shared -fPIC $(objects_py) -I/usr/include/openssl -lcrypto -o desdemo.so

py:desdemo.so

test:c
	tmp=`echo -n "type=2&provice=32&school=北京清华大学&name=张三&examroom=&m=77-88-99-11-22-33" | iconv -t gbk | xargs ./main encrypt` ;\
	echo ;\
	echo $$tmp | xargs ./main decrypt | iconv -f gbk ;\


.PHONY : clean
clean :
	rm main *.o *.so 2>>/dev/null

