
#include "trabalho1.h"

void *threadA(void *params) {

  printf("thread A started\n");

  par_t* p = (par_t*) params;

  int len = p->len;
  char *array = p->array;

  char letra = 'a'; 
  int i = 0;
  while(i < len){
    array[i] = letra;
    i += 3;
  }
  
  printf("thread A finished\n");
  return NULL;
}

void *threadB(void *params) {
  
  printf("thread B started\n");
  
  par_t* p = (par_t*) params;

  int len = p->len;
  char *array = p->array;
  
  char letra = 'b'; 
  int i = 1;
  while(i < len){
    array[i] = letra;
    i += 3;
  }
  
  printf("thread B finished\n");
  return NULL;
}

void *threadC(void *params) {
  
  printf("thread C started\n");

  par_t* p = (par_t*) params;
  
  int len = p->len;
  char *array = p->array;

  char letra = 'c'; 
  int i = 2;
  while(i < len){
    array[i] = letra;
    i += 3;
  }
  printArray(array, len);
  
  printf("thread C finished\n");
  return NULL;
}

void printArray(char *array, int len) {
  
  printf("printing array\n");
  
  int i = -1;
  printf("\n");
  while(++i<len){
    printf("%c", array[i]);
  }
  printf("\n");
  printf("\n");
}