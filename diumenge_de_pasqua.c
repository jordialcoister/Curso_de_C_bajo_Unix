#include <stdio.h>

#define DEMANA1 "Introuïsca l'any"
#define RESULTAT1 "La data del Diumenge de Pasqua és: "

int diumenge_pasqua(int a){
  int dia;
  int A,B,C,D,E,F;

  A = (a % 19);
  B = (a % 14);
  C = (a % 7);
  D = (19*A + 24) % 30;
  E = (2*B + 4*C + 6*D + 5) % 7;
  F = 22 + D + E;
 
  return F;
}

int main(int argc, char *argv[])
{
  int any,dia;

  printf("%s\n", DEMANA1);
  scanf("%i", &any);
  dia=diumenge_pasqua(any);
  if ( dia > 31 ) 
    printf("%s%i d'Abril\n", RESULTAT1, diumenge_pasqua(any)%31);
  else
    printf("%s%i de Març\n", RESULTAT1, diumenge_pasqua(any));
  return 0;
}
