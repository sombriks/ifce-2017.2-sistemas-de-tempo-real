

#include <stdio.h>
#include <pthread.h>
#include <string.h>

// function prototypes

struct par {
  char array[30];
  int len;
};

typedef struct par par_t;

void *threadA(void*);

void *threadB(void*);

void *threadC(void*);

void printArray(char *array, int len);
