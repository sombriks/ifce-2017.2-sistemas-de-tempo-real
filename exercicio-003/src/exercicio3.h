
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// https://support.sas.com/documentation/onlinedoc/sasc/doc700/html/lr2/zid-7440.htm
// http://www.skrenta.com/rt/man/pthread_mutex_init.3.html

int duplex[2][3] = {{-1, -1, -1}, {-1, -1, -1}};

struct params_s {
  int(*worker)();
  int ch;
};

typedef struct params_s params_t;

void *threadCitizen(void *);
void *threadDriver(void *);

int fA();
int fB();
int fC();
