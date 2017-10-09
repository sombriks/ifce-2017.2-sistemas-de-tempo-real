
#include "exercicio2.h"

int main (int argc, char **argv) {

  printf("process start\n");

  // garantindo estado inicial limpo

  int i = 3;
  while(i-->0) {
    vetor[i]=-1;
    duplex[0][i]=-1;
    duplex[1][i]=-1;
  }

  time_t t; // https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
  srand((unsigned) time(&t));

  // nossas threads

  pthread_t p1, p2, p3, driver;

  // contexto para as threads

  guessinfo_t g1, g2, g3;

  g1.ch=0;
  g2.ch=1;
  g3.ch=2;
  g1.t = g2.t = g3.t = &t;

  pthread_create(&p1, NULL, pguesser, &g1);
  pthread_create(&p2, NULL, pguesser, &g2);
  pthread_create(&p3, NULL, pguesser, &g3);

  pthread_create(&driver, NULL, pdriver, NULL);


  // pedantismo, as threads estão em laço infinito.
  pthread_join(driver, NULL);
  pthread_join(p3, NULL);
  pthread_join(p2, NULL);
  pthread_join(p1, NULL);

  printf("process end\n");
  return 0;
}