
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Exercício 3
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
#
# para compilar, chamar make all na linha de comando
# espera-se gcc, make e um sistema 'unix-compatible' 
#
# o exercício visa praticar o conceito de canais com envio síncrono para
# criar um programa 'N-versão'. pretende ainda exercitar a criação de 
# subprocessos em vez de threads, que foi a abordagem negligenciada nos
# exercícios anteriores.
#
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall
LIBS=-lpthread -lm

exercicio3: main.o exercicio3.o 
	gcc $(LDFLAGS) exercicio3.o main.o $(LIBS) -o exercicio3

main.o: main.c exercicio3.c exercicio3.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c exercicio3.c

all: exercicio3

clean: all
	rm -f exercicio3 *.o
