
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// types

typedef struct { // http://www.skrenta.com/rt/man/pthread_mutex_init.3.html
  pthread_t thread_a, thread_b, thread_c, thread_d, thread_e, thread_f;
  pthread_mutex_t mutex;  
  int vec[5];
  int veclen;
  int vecidx; 
} ctx;

typedef struct {
  ctx *context;
  int value;
} thctx;

// function prototypes

void *thread_plus(void *);
void *thread_print(void *);
