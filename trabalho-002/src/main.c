
#include "trabalho2.h"

int main(int argc, char** argv) {

  printf("process start\n");

  ctx c;
  c.vecidx=0;
  c.veclen=5;
  pthread_mutex_init(&c.mutex, NULL);
  int i = 5;
  while(i-->0)
    c.vec[i]=-1;

  time_t t; // https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
  srand((unsigned) time(&t));

  thctx c1, c2, c3, c4, c5;
  c1.context = c2.context = c3.context = c4.context = c5.context = &c;
  c1.value = round(rand() % 20);
  c2.value = round(rand() % 20);
  c3.value = round(rand() % 20);
  c4.value = round(rand() % 20);
  c5.value = round(rand() % 20);

  pthread_create(&c.thread_a, NULL, thread_plus, &c1);
  pthread_create(&c.thread_b, NULL, thread_plus, &c2);
  pthread_create(&c.thread_c, NULL, thread_plus, &c3);
  pthread_create(&c.thread_d, NULL, thread_plus, &c4);
  pthread_create(&c.thread_e, NULL, thread_plus, &c5);
  pthread_create(&c.thread_f, NULL, thread_print, &c);

  pthread_join(c.thread_f,NULL);

  printf("process end\n");
  return 0;
}