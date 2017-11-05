
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Exercício 4
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
# @date 2017-10-23
#
# para compilar, chamar make all na linha de comando
# espera-se gcc, make e um sistema 'unix-compatible' 
#
# vide ../README.md para resumo do exercício
#
# mais uma vez os printf's concorrentes disparam deadlocks ocasionais.
#
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall
LIBS=-lpthread -lm -lrt

exercicio4: main.o exercicio4.o 
	gcc $(LDFLAGS) exercicio4.o main.o $(LIBS) -o exercicio4

main.o: main.c exercicio4.c exercicio4.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c exercicio4.c

all: exercicio4

clean: all
	rm -f exercicio4 *.o
