
#include "exercicio4.h"

void *th(void *param) {
  parameter_t *p = (parameter_t *)param;
  printf("thread %d will use %d resources\n", p->id, p->num);
  ex_wait(p->num);
  printf("consuming resource\n");
  ex_signal(p->num);
  printf("thread %d ending\n", p->id);
  return NULL;
}

void ex_wait(int num) {
  // sem_wait(&mutex);
  while (num--) sem_wait(&resource);
  int val;
  sem_getvalue(&resource, &val);
  printf("semaphore have %d resources left\n", val);
  // sem_post(&mutex);
}

void ex_signal(int num) {
  // sem_wait(&mutex);
  while (num--) sem_post(&resource);
  int val;
  sem_getvalue(&resource, &val);
  printf("semaphore have %d resources available\n", val);
  // sem_post(&mutex);
}