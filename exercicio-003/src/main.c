
#include "exercicio3.h"

int main(int argc, char** argv) {
  pthread_t thread_a, thread_b, thread_c, thread_driver;
  params_t p_a, p_b, p_c;

  p_a.worker = &fA;
  p_b.worker = &fB;
  p_c.worker = &fC;

  p_a.ch = 0;
  p_b.ch = 1;
  p_c.ch = 2;

  pthread_create(&thread_a, NULL, threadCitizen, &p_a);
  pthread_create(&thread_b, NULL, threadCitizen, &p_b);
  pthread_create(&thread_c, NULL, threadCitizen, &p_c);

  pthread_create(&thread_driver, NULL, threadCitizen, NULL);

  return 0;
}