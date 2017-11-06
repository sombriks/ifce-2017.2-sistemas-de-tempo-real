
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://support.sas.com/documentation/onlinedoc/sasc/doc700/html/lr2/zid-7440.htm
// http://www.skrenta.com/rt/man/pthread_mutex_init.3.html
// http://www.csc.villanova.edu/~mdamian/threads/posixsem.html

int channel[5];  // = {-1, -1, -1, -1, -1};

typedef struct {
  int destination;
  int value;
} param_sender_t;

typedef struct {
  int channel;
} param_receiver_t;

void param_init(param_sender_t *, int, int);

void showbits(unsigned short);

unsigned short encodebits(int, int);

void decodebits(unsigned short, int *, int *);

void *sender(void *);

void *receiver(void *);

void *manager(void *);

void post_message(unsigned short); 

void send_sync(int, int);

void receive(int, int *);
