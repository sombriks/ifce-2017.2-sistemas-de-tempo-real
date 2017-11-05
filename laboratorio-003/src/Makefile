
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Laboratorio 3
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com> 
#
# para compilar, chamar make all na linha de comando
# espera-se gcc, make e um sistema 'unix-compatible' 
#
# @see ../src/README.md 
#
##############################################################################

CFLAGS=-Wall
LDFLAGS=-Wall
LIBS=-lpthread -lm

all: laboratorio3

main.o: main.c laboratorio3.c laboratorio3.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c laboratorio3.c

laboratorio3: main.o laboratorio3.o 
	gcc $(LDFLAGS) laboratorio3.o main.o $(LIBS) -o laboratorio3

clean: all
	rm -f laboratorio3 *.o
