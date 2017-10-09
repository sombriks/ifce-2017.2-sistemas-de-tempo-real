
#include "exercicio2.h"

void* pguesser(void*params) {

  guessinfo_t *info = (guessinfo_t*) params;

  int channel = info->ch;

  printf("guesser %d started\n", channel);

  while(1){
    // vamos chutar um período
    int periodo = 5 + ((int) rand() % 10);

    unsigned long t1 = time(info->t);
    unsigned long t2 = t1 + periodo;

    // busy timer
    while(t2 > t1)
      t1 = time(info->t);

    int guess = (int) rand() % 100;

    printf("guesser %d says %d \n",channel,guess);

    send_async(0,channel,guess);

    int result = receive(1,channel);

    printf("guesser %d got '%s valor'\n",channel, result ? "maior" : "menor");

  }

  return NULL;
};

void* pdriver(void*_) {

  printf("driver started\n");
  
  while(1) {
    int i = 3, maior = 0, val = -1, lval = -1;
    while(i-->0) {
      val = receive(0, i);
      if(val > lval){
        maior = i;
        lval = val;
      }
    }
    i = 3;
    while(i-->0) 
      send_async(1,i, i == maior ? 1 : 0);
  }

  return NULL;
};

void send_async(int inout,int channel,int value){
  // while(duplex[inout][channel] != -1); // aí seria síncrono
  duplex[inout][channel]=value;
}

int receive(int inout,int channel){
  while(duplex[inout][channel] == -1);
  int val = duplex[inout][channel];
  duplex[inout][channel] = -1;
  return val;
}