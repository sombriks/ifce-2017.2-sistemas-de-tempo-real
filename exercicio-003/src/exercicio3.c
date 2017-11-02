
#include "exercicio3.h"

void *threadCitizen(void *params) {
  int result = -1, error = 0;
  params_t *par = (params_t *)params;
  result = par->worker();
  send_sync(0, par->ch, result);
  receive(1, par->ch, &error);
  if (error)
    printf("Thread %d finalizando\n", par->ch);
  else {
    printf("Thread %d ativa\n", par->ch);
    while (1)
      ;
  }
  return NULL;
}

void *threadDriver(void *params) {
  int *numchannels = (int *)params;
  int out = 0;
  int vresult[*numchannels];
  int verr = -1;
  int i = *numchannels;
  while (i--) vresult[i] = -1;
  i = *numchannels;
  while (i--) {
    receive(0, i, &out);
    vresult[i] = out;
  }
  verr = compara(vresult, *numchannels);
  i = *numchannels;
  while (i--) {
    send_sync(1, i, verr == i ? 1 : 0);
  }
  return NULL;
}

int fA() {
  int i = rand() % 100;
  return i > 30 ? 10 : 0;
}

int fB() {
  int i = rand() % 100;
  return i > 40 ? 10 : 0;
}

int fC() {
  int i = rand() % 100;
  return i > 50 ? 10 : 0;
}

int compara(int val[], int size) {
  int i = size;
  int j = size;
  while (i--) {
    j = size;
    while (j--)
      if (val[i] != val[j]) return j;
  }
  return -1;
}

void send_sync(int inout, int ch, int val) {
  // 0 we'll use to receive
  // 1 we'll use to send
  duplex[inout][ch] = val;
  while (duplex[0][ch] != -1)
    ;
  // busy wait because yes
}

void receive(int inout, int ch, int *out) {
  while (duplex[inout][ch] == -1)
    ;
  *out = duplex[inout][ch];
  duplex[inout][ch] = -1;
}
