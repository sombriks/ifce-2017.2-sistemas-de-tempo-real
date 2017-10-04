

#include <stdio.h>
#include <pthread.h>
#include <string.h>

// types

struct par {
  char array[30];
  int len;
};

typedef struct par par_t;

// function prototypes

void *threadA(void*);

void *threadB(void*);

void *threadC(void*);

void printArray(char *array, int len);
