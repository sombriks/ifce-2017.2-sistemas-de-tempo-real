
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Trabalho 2
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
#
# para compilar chamar make all na linha de comando
# espera-se gcc, make e um sistema unix-compatible pra dar certo compilar
#
# neste trabalho temos uso de mutexes porque o índice atual do vetor é
# região crítica pertencente ao contexto de todas as 5 threads. a sexta
# se encarrega apenas de dar join nas 5 anteriores, ordenar e por fim 
# pimprimir o vetor. diferente do enunciado do trabalho, não cobrimos aqui
# o uso das windows threads, e embora os contextos sejam declarados 
# globalmente, eles encontram-se na stack da função main. 
#
# fora estes dois pecados, esta resolição do exercício é uma 
# fina peça didática
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall
LIBS=-lpthread -lm

main.o: main.c trabalho2.c trabalho2.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c trabalho2.c

trabalho2: main.o trabalho2.o 
	gcc $(LDFLAGS) trabalho2.o main.o $(LIBS) -o trabalho2

all: trabalho2

clean: all
	rm -f trabalho2 *.o
