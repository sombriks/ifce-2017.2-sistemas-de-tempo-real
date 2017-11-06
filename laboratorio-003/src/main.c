
#include "laboratorio3.h"

int main(int argc, char **argv) {
  printf("Process started\n");

  int i = 5;
  while (i--) channel[i] = -1;

  param_sender_t pa, pb, pc, pd;
  param_receiver_t pe, pf, pg, ph;
  pthread_t ta, tb, tc, td, te, tf, tg, th, tmanager;

  param_init(&pa, 1, 10);
  param_init(&pb, 2, 20);
  param_init(&pc, 3, 30);
  param_init(&pd, 4, 40);

  pe.channel = 1;
  pf.channel = 2;
  pg.channel = 3;
  ph.channel = 4;

  pthread_create(&ta, NULL, sender, &pa);
  pthread_create(&tb, NULL, sender, &pb);
  pthread_create(&tc, NULL, sender, &pc);
  pthread_create(&td, NULL, sender, &pd);

  pthread_create(&te, NULL, receiver, &pe);
  pthread_create(&tf, NULL, receiver, &pf);
  pthread_create(&tg, NULL, receiver, &pg);
  pthread_create(&th, NULL, receiver, &ph);

  pthread_create(&tmanager, NULL, manager, NULL);

  pthread_join(ta, NULL);
  pthread_join(tb, NULL);
  pthread_join(tc, NULL);
  pthread_join(td, NULL);
  pthread_join(te, NULL);
  pthread_join(tf, NULL);
  pthread_join(tg, NULL);
  pthread_join(th, NULL);
  pthread_join(tmanager, NULL);

  printf("Process finished\n");
  return 0;
}