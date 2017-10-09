
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Exercício 2
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
#
# para compilar, chamar make all na linha de comando
# espera-se gcc, make e um sistema 'unix-compatible' 
#
# o exercício visa praticar o conceito de canais e de 
# memória compartilhada. é usada a técnica 'busy-wait loop' para
# aguardar comunicação de dados.
#
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall
LIBS=-lpthread -lm

exercicio2: main.o exercicio2.o 
	gcc $(LDFLAGS) exercicio2.o main.o $(LIBS) -o exercicio2

main.o: main.c exercicio2.c exercicio2.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c exercicio2.c

all: exercicio2

clean: all
	rm -f exercicio2 *.o
