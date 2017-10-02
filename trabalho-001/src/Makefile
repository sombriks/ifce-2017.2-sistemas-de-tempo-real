
CFLAGS=-Wall
LDFLAGS=-Wall

main.o: main.c trabalho1.c trabalho1.h 
	gcc $(CFLAGS) -c main.c
	gcc $(CFLAGS) -c trabalho1.c

trabalho1: main.o trabalho1.o 
	gcc $(LDFLAGS) trabalho1.o main.o -lpthread -o trabalho1

all: trabalho1

clean:
	rm -f trabalho1 *.o