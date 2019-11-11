# Student: Ji Soo Yim
# Description: Makefile for testme.c

CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme:
	$(CFLAGS) gcc -o testme -g testme.c
	./testme

clean:
	rm *.o testme *.gcov *.gcda *.gcno
