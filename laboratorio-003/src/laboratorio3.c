
#include "laboratorio3.h"

void param_init(param_t *p, int ch, int val) {
  p->destination = ch;
  p->value = val;
}

void *sender(void *params) {
  time_t t;
  srand((unsigned)time(&t));

  param_t *p = (param_t *)params;
  while (1) {
    // vamos chutar um período
    int periodo = 2 + ((int)rand() % 5);
    // intervalo de tempo
    unsigned long t1 = time(&t);
    unsigned long t2 = t1 + periodo;
    // busy timer
    while (t2 > t1) t1 = time(&t);

    int msg;  // TODO montar a mensagem com maskbits

    send_sync(0, msg);
  }
  return NULL;
}

void *receiver(void *params) { return NULL; }

void *manager(void *params) { return NULL; }

void send_sync(int ch, int val) {
  channel[ch] = val;
  while (channel[ch] != -1)
    ;
}

void receive(int ch, int *val) {
  while (channel[ch] == -1){}
    ;
  *val = channel[ch];
  channel[ch] = -1;
}