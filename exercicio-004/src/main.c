
#include "exercicio4.h"

int main(int argc, char **argv) {
  sem_init(&sem, 0, 5);// 5 blocos de 2k

  pthread_t thread_a, thread_b, thread_c;
  
  int how_many_a = 3;
  int how_many_b = 3;
  int how_many_c = 2;

  

  return 0;
} 