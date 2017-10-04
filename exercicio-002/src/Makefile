
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Exercício 2
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
#
# elabore um programa concorrente em que 3 processos, p1, p2 e p3 devem fazer 
# o seguinte: os processos p1, p2, e p3 devem enviar periodicamente valores
# aleatórios para uma thread chamada 'driver'. a thread 'driver' deve receber
# os valores, e retornar para a thread que enviou o valor inteiro 1, e as 
# demais thread o valor 0. cada thread que receber o seu valor da 'driver',
# deverá imprimir "maior valor" se receber 1, e "menor valor" se receber 0.
#
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall
LIBS=-lpthread -lm

main.o: main.c exercicio2.c exercicio2.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c exercicio2.c

exercicio2: main.o exercicio2.o 
	gcc $(LDFLAGS) exercicio2.o main.o $(LIBS) -o exercicio2

all: exercicio2

clean: all
	rm -f exercicio2 *.o
