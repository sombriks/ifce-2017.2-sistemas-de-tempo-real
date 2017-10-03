
#include "trabalho1.h"

int main(int argc, char** argv) {

  printf("process start\n");

  pthread_t thread_a, thread_b, thread_c;
  struct par p;

  p.len = 30;
  memset(p.array, ' ', p.len * sizeof(char));

  pthread_create(&thread_a, NULL, threadA, &p);
  pthread_create(&thread_b, NULL, threadB, &p);
  pthread_create(&thread_c, NULL, threadC, &p);

  pthread_join(thread_a,NULL);
  pthread_join(thread_b,NULL);
  pthread_join(thread_c,NULL);

  printf("process end\n");
  return 0;
}