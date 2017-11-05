
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Exercício 4
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
# @date 2017-11-05
#
# para compilar, chamar make all na linha de comando
# espera-se gcc, make e um sistema 'unix-compatible' 
#
# vide ../README.md para resumo do exercício
#
#
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall
LIBS=-lpthread -lm -lrt

trabalho3: main.o trabalho3.o 
	gcc $(LDFLAGS) trabalho3.o main.o $(LIBS) -o trabalho3

main.o: main.c trabalho3.c trabalho3.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c trabalho3.c

all: trabalho3

clean: all
	rm -f trabalho3 *.o
