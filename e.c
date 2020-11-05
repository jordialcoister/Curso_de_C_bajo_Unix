#include <stdio.h>

#define TITOL "CÀLCUL DEL NÚMERO E AMB UNA APROXIMACIÓ DONADA PER TECLAT"
#define SUB "========================================================"
#define ERROR "Si us plau, indiqui l'error desitjat: "

int main(int argc, char *argv[])
{
  float error, e=1, sumand=1,factorial=1;

  printf("%s\n%s\n%s", TITOL, SUB, ERROR);
  scanf("%f", &error);

  for (int i=1; sumand>error; i++){
    factorial*=i;
    sumand=1/factorial;
    e = e + sumand;
  }

  printf("%f\n",e);
  return 0;
}
