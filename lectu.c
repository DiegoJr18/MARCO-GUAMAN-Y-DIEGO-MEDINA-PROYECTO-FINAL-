#include <stdio.h>
#include "lectu.h"

int leerEnteroEntre(char* mensaje,int min,int max){
  int valor;
  do{
    printf("%s",mensaje);
    scanf("%d",&valor);

  }while(valor<min || valor>max);
  return valor;

}

