
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Trabalho 1
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
#
# para compilar chamar make all na linha de comando
# espera-se gcc, make e um sistema unix-compatible pra dar certo compilar
#
# a ordem das mensagens de debug não necessariamente representa a ordem das
# coisas, mas ela varia de uma execução para outra, evidenciando a natureza
# concorrente das threads
# o exercício não usa mutexes porque, lendo com cuidado o enunciado, não foi
# pedido
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall

main.o: main.c trabalho1.c trabalho1.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c trabalho1.c

trabalho1: main.o trabalho1.o 
	gcc $(LDFLAGS) trabalho1.o main.o -lpthread -o trabalho1

all: trabalho1

clean: all
	rm -f trabalho1 *.o
