
#include "trabalho2.h"

void *thread_plus(void *params) {
  thctx *th = (thctx *) params;
  pthread_mutex_trylock(&(th->context->mutex));
  printf("thread body locked, value %d\n",th->value);
  int i = th->context->vecidx;
  th->context->vec[i] = th->value + 5;
  th->context->vecidx++;
  pthread_mutex_unlock(&(th->context->mutex));
  return NULL;
}

void *thread_print(void *params) {
  ctx *c = (ctx*) params;
  printf("thread print started\n");
  pthread_join(c->thread_a,NULL);
  pthread_join(c->thread_b,NULL);
  pthread_join(c->thread_c,NULL);
  pthread_join(c->thread_d,NULL);
  pthread_join(c->thread_e,NULL);
  printf("vetor resultado:\n[");
  int i = -1;
  while(++i<5)
    printf("%d,",c->vec[i]);
  printf("]\n");
  printf("thread print finished\n");
  return NULL;
}