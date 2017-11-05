
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// https://support.sas.com/documentation/onlinedoc/sasc/doc700/html/lr2/zid-7440.htm
// http://www.skrenta.com/rt/man/pthread_mutex_init.3.html
// http://www.csc.villanova.edu/~mdamian/threads/posixsem.html

sem_t sem;

typedef struct {
  int howmany;
} parameter;

void *th(void *);


