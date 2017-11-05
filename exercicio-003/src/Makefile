
##############################################################################
# IFCE - Instituto Federal de Educação, Ciência e Tecnologia do Ceará
# Sistemas de Tempo Real e Tolerantes a Falha 
# Exercício 3
#
# @professor Paulo Regis
# @author Leonardo Silveira <sombriks@gmail.com>
#
# Para compilar, chamar make all na linha de comando espera-se encontrar
# gcc, make e um sistema 'unix-compatible' 
#
# O exercício visa praticar o conceito de canais com envio síncrono para
# criar um programa 'N-versão'.
#
# De vez em quando o print falha, mas é inerente a como o console 
# se comporta diante de escrita concorrente mesmo.
# 
# Por fim, o programa tem a característica de ficar preso em loop infinito,
# mas como não é pedido solução alguma para isso não vamos nem mexer. 
#
# Maiores detalhes em ../20171009_162010.jpg
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
