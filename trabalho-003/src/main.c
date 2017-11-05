
#include "trabalho3.h"

int main(int argc, char **argv) {
  printf("process started\n");

  int i = 2, j;

  while (i--) {
    j = 3;
    while (j--) duplex[i][j] = -1;
  }

  pchannels_t c1, c2, c3;

  // sou o 0 e mando pro 1
  c1.chin = 0;
  c1.chmain = 1;
  c1.chaux = 2;
  c1.starter = 1;

  // sou o 1 e mando pro 2
  c2.chin = 1;
  c2.chmain = 2;
  c2.chaux = 0;
  c2.starter = 0;

  // sou o 2 e mando pro 0
  c3.chin = 2;
  c3.chmain = 0;
  c3.chaux = 1;
  c3.starter = 0;

  pthread_t thread_a, thread_b, thread_c;

  pthread_create(&thread_a, NULL, th, &c1);
  pthread_create(&thread_b, NULL, th, &c2);
  pthread_create(&thread_c, NULL, th, &c3);

  pthread_join(thread_c, NULL);
  pthread_join(thread_b, NULL);
  pthread_join(thread_a, NULL);

  return 0;
}
