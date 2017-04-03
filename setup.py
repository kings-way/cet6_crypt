from distutils.core import setup, Extension
setup(
	name = 'desdemo', 
	version = '0.1', 
	description='DES_CFB64 Encrypt/Decrypt Function From OpenSSL',
	author='King\'s Way',
	author_email='io[AT]stdio.io',
	url='https://github.com/kings-way/cet6_crypt',
	ext_modules = [
		Extension(
				'desdemo', 
				['desdemo.c', 'des_cfb64.c'],
#				include_dirs=['/usr/include/openssl'],
				libraries=['crypto']
		)
	]	
)
