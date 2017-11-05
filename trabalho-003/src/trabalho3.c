
#include "trabalho3.h"

void *th(void *params) {
  pchannels_t *p = (pchannels_t *)params;
  int ok = 1;
  while(ok){
    int msg;
    receive(1,p->chmain,&msg);
  }
  return NULL;
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