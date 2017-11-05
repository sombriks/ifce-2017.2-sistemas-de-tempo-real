
#include "exercicio4.h"

int main(int argc, char **argv) {
  printf("Process start\n");
  sem_init(&resource, 0, 5);    // 5 blocos de 2k
  sem_init(&mutex, 0, 1);  // mutex para não dar zebra

  pthread_t thread_a, thread_b, thread_c;

  parameter_t how_many_a, how_many_b, how_many_c;
  
  how_many_a.id = 1;
  how_many_b.id = 2;
  how_many_c.id = 3;
  how_many_a.num = 3;
  how_many_b.num = 3;
  how_many_c.num = 2;

  pthread_create(&thread_a, NULL, th, &how_many_a);
  pthread_create(&thread_b, NULL, th, &how_many_b);
  pthread_create(&thread_c, NULL, th, &how_many_c);

  pthread_join(thread_a, NULL);
  pthread_join(thread_b, NULL);
  pthread_join(thread_c, NULL);

  printf("Process finish\n");

  return 0;
}