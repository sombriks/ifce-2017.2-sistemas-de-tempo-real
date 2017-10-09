
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// globals

int vetor[3];
int duplex[2][3];

// struct and types

struct guessinfo {
  int ch;
  time_t* t;
};

typedef struct guessinfo guessinfo_t;

// function prototypes

void* pguesser(void*);
void* pdriver(void*);

// helpers de transmissão. teremos transmissão bidirecional,
// mas os canais são unidirecionais. então montamos canais de
// ida e canais de volta, doravante batizados de duplex.
// para envio, indicamos qual o duplex em uso (0 ou 1), qual 
// canal (0,1,2) e qual o valor a enviar. 
// para recepção, que é síncrona, indicamos o duplex 
// e o canal, o valor é o retorno da função de recepção

void send_async(int,int,int);
int receive(int,int);
