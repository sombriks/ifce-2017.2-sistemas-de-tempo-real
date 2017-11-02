
#include "exercicio3.h"

int main(int argc, char** argv) {
  int i = 2;
  int j = 3;
  while (i-- > 0)
    while (j-- > 0) duplex[i][j] = -1;
  srand((unsigned)time(&t));

  pthread_t thread_a, thread_b, thread_c, thread_driver;
  params_t p_a, p_b, p_c;

  p_a.worker = &fA;
  p_b.worker = &fB;
  p_c.worker = &fC;

  p_a.ch = 0;
  p_b.ch = 1;
  p_c.ch = 2;

  int channels = 3;
  pthread_create(&thread_a, NULL, threadCitizen, &p_a);
  pthread_create(&thread_b, NULL, threadCitizen, &p_b);
  pthread_create(&thread_c, NULL, threadCitizen, &p_c);
  pthread_create(&thread_driver, NULL, threadDriver, &channels);

  pthread_join(thread_c, NULL);
  pthread_join(thread_b, NULL);
  pthread_join(thread_a, NULL);
  pthread_join(thread_driver, NULL);


  return 0;
}