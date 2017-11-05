
#include "exercicio4.h"

void *th(void *param) {
  parameter_t *p = (parameter_t *)param;
  ex_wait(p->num);
  printf("thread %d using %d resources\n", p->id, p->num);
  ex_signal(p->num);
  return NULL;
}

void ex_wait(int num) {
  sem_wait(&mutex);
  while (num--) sem_wait(&resource);
  sem_post(&mutex);
}

void ex_signal(int num) {
  sem_wait(&mutex);
  while (num--) sem_post(&resource);
  sem_post(&mutex);
}