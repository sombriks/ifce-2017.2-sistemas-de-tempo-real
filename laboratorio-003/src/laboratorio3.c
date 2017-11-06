
#include "laboratorio3.h"

void *sender(void *params) {
  time_t t;
  srand((unsigned)time(&t));

  param_sender_t *p = (param_sender_t *)params;
  while (1) {
    // vamos chutar um período
    int periodo = 2 + ((int)rand() % 5);
    // intervalo de tempo
    unsigned long t1 = time(&t);
    unsigned long t2 = t1 + periodo;
    // busy timer
    while (t2 > t1) t1 = time(&t);

    unsigned short msg = encodebits(p->destination, p->value);
    post_message(msg);
  }
  return NULL;
}

void *manager(void *params) {
  unsigned short msg[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int i = 0;
  while (1) {
    int payload;
    receive(0, &payload);
    printf("queue size: %d\n", i);
    msg[i++] = payload;
    if (i == 12) {
      // fila cheia, hora de disparar os envios
      int channel;
      int value;
      while (i--) {
        decodebits(msg[i], &channel, &value);
        send_sync(channel, value);
      }
      i = 0;
    }
  }
  return NULL;
}

void *receiver(void *params) {
  param_receiver_t *p = (param_receiver_t *)params;
  int val;
  while (1) {
    receive(p->channel, &val);
    printf("receiver %d got %d\n", p->channel, val);
  }
  return NULL;
}

void param_init(param_sender_t *p, int ch, int val) {
  p->destination = ch;
  p->value = val;
}

void showbits(unsigned short message) {
  int i = 8 * sizeof(short);
  while (i--) {
    printf("%d", message & 1 ? 1 : 0);
    message = message >> 1;
  }
  printf("\n");
  // 00000000 00000000
  // 00000000 11000000
  // 00101000 01000000
  // 00010100 00100000
  // 01010000 10000000
  // 01010000 10000000
  // 00010100 00100000
  // 01111000 11000000
  // 00101000 01000000
}

unsigned short encodebits(int channel, int value) {
  unsigned short msg = 0;
  msg |= channel;
  msg <<= 8;
  msg |= value;
  return msg;
}

void decodebits(unsigned short message, int *channel, int *value) {
  *value = message & 0x0f;
  message >>= 8;
  *channel = message & 0x0f;
}

void post_message(unsigned short message) { send_sync(0, message); }

void send_sync(int ch, int val) {
  channel[ch] = val;
  while (channel[ch] != -1)
    ;
}

void receive(int ch, int *val) {
  while (channel[ch] == -1) {
  };
  *val = channel[ch];
  channel[ch] = -1;
}