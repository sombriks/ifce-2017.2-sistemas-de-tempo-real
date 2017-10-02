
#include "trabalho1.h"

int main(int argc, char** argv) {

  pthread_t thread_a, thread_b, thread_c;
  struct par p;

  p.len = 30;
  memset(p.array, ' ', p.len * sizeof(char));

  pthread_create(&thread_a, NULL, threadA, &p);
  pthread_create(&thread_b, NULL, threadB, &p);
  pthread_create(&thread_c, NULL, threadC, &p);

  return 42;
}