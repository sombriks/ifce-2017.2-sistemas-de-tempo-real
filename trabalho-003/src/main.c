
#include "trabalho3.h"

int main(int argc, char **argv) {
  int i = 2, j;

  while (i--) {
    j = 3;
    while (j--) duplex[i][j] = -1;
  }

  pchannels_t c1, c2, c3;

  c1.chmain=0;
  c1.chaux=1;
  
  c2.chmain=1;
  c2.chaux=2;
  
  c3.chmain=2;
  c3.chaux=0;
  
  pthread_t thread_a, thread_b, thread_c;

  

  return 0;
}