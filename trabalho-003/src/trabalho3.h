
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

// https://support.sas.com/documentation/onlinedoc/sasc/doc700/html/lr2/zid-7440.htm
// http://www.skrenta.com/rt/man/pthread_mutex_init.3.html
// http://www.csc.villanova.edu/~mdamian/threads/posixsem.html

 typedef struct {
   int chin;
   int chmain;
   int chaux;
   int starter;
 } pchannels_t;

int duplex[2][3];

void *th(void *);
int mkmsg();

void send_async(int, int, int);
void send_sync(int, int, int);
void receive(int, int, int *);
