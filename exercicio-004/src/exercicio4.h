
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// https://support.sas.com/documentation/onlinedoc/sasc/doc700/html/lr2/zid-7440.htm
// http://www.skrenta.com/rt/man/pthread_mutex_init.3.html
// http://www.csc.villanova.edu/~mdamian/threads/posixsem.html

sem_t resource, mutex;

typedef struct {
  int num;
  int id;
} parameter_t;

void *th(void *);

void ex_wait(int);
void ex_signal(int);

