#include <stdio.h>

#define BASE "Introdueix un número real: "
#define EXPONENT "Introdueix un número sencer: "

float potencia(float base, int exponent){
  float resultat=base;

  for (int i=1; i<exponent; i++){
    resultat*=base;
  }
  
  return resultat;
}

int main(int argc, char *argv[])
{
  float base;
  int exponent;
  
  printf("%s\n", BASE);
  scanf("%f", &base);
  printf("%s\n", EXPONENT);
  scanf("%i", &exponent);

  printf("%f^%i=%f\n",base,exponent,potencia(base,exponent) ); 

  return 0;
}
