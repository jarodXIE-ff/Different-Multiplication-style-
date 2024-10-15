CFLAGS =  -Wall -O3
LIBS = -lm 

all: FFT_IFFT naive_poly FFT_poly

FFT_IFFT :  FFT_IFFT.c complex.c
	gcc -Wall -O3 $^ -o $@ -lm

naive_poly : naive_poly.c
	gcc -Wall -O3  $^ -o $@

FFT_poly : FFT_poly.c complex.c FFT_IFFT_lib.c
	gcc -O3 $^ -o $@ -lm