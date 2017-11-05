
#include "trabalho3.h"

void *th(void *params) {
  // https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
  time_t t;
  srand((unsigned)time(&t));

  pchannels_t *p = (pchannels_t *)params;
  printf("thread %d started\n", p->chin);
  if (p->starter) {
    int val = mkmsg();
    printf("[starter] t[%d]->t[%d]:%d\n", p->chin, p->chmain, val);
    send_sync(0, p->chmain, val);
  }
  int ok = 1, aux = 0;
  while (ok) {
    // vamos chutar um período
    int periodo = 2 + ((int)rand() % 5);
    // intervalo de tempo
    unsigned long t1 = time(&t);
    unsigned long t2 = t1 + periodo;
    // busy timer
    while (t2 > t1) t1 = time(&t);

    // recebendo mensagem
    int msg = 0;
    receive(0, p->chin, &msg);
    printf("t[%d]:%d\n", p->chin, msg);

    // avisando se a mensagem é aceitável
    send_async(1, p->chin, msg >= 5 ? 0 : 1);

    // enviando a mensagem
    int val = mkmsg();
    printf("t[%d]->t[%d]:%d\n", p->chin, aux ? p->chaux : p->chmain, val);
    send_sync(0, aux ? p->chaux : p->chmain, val);

    // recebendo o feedback da mensagem
    receive(1, aux ? p->chaux : p->chmain, &val);
    printf("feedback t[%d]:%d\n", p->chin, val);

    if (val && aux) {
      ok = 0;
    } else if (val) {
      aux = 1;
    }
  }
  return NULL;
}

int mkmsg() { return 3 + rand() % 10; }

void send_sync(int inout, int ch, int val) {
  duplex[inout][ch] = val;
  while (duplex[0][ch] != -1)
    ;
}

void send_async(int inout, int ch, int val) { duplex[inout][ch] = val; }

void receive(int inout, int ch, int *out) {
  while (duplex[inout][ch] == -1)
    ;
  *out = duplex[inout][ch];
  duplex[inout][ch] = -1;
}
