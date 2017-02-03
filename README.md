# DES CFB64

## Intruduction
-----
		This is a demo of the encryption method 'des cfb64' which is used in 99宿舍 client.
		It's written in C language using the openssl library, and we could not find an implemention in nodejs 、python or java.

### How to run
---
	1）apt-get install libssl-dev
		# make sure you have openssl library installed

	2）make c
		# build the C program 'main'
 
	3）make test
		# I offer a sample text to be encrypted...
	
	4) make py
		# to make the python module 'desdemo', just 'import desdemo' and then call the two function with key and data.
