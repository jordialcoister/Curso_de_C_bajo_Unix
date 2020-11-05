#include <stdio.h>

#define PETICIO "Introdueix un número positiu: "
#define ERR_NEGATIU "Error: El número no és positiu."

#define A 1.0
#define TOLERANCIA 0.000001

double newton(int X){
  double arrel, aprox=A, dif;

  do {
    arrel = (aprox+(X/aprox))/2;
    dif = arrel-aprox;
    if (dif < 0)
      dif=-dif;
    aprox=arrel;
    printf("%lf\n",dif );
  } while (dif > TOLERANCIA );
  
  return arrel;
}

int main(int argc, char *argv[])
{
  int numero;

  printf("%s\n", PETICIO);
  scanf("%i", &numero);
  if (numero<0){
    printf("%s\n", ERR_NEGATIU);
  }
  else {
    printf("L'arrel quadrada de %i mitjançant el mètode de Newton és: %lf\n", numero, newton(numero));
  }
  return 0;
}
