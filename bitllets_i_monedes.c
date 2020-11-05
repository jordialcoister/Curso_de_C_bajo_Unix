#include <stdio.h>

#define PETICIO "Per favor, introdueix l'import a pagar:"
#define RESPOSTA 

int main(int argc, char *argv[])
{
  int sum,resta,divisio;
  
  printf("%s\n", PETICIO);
  scanf("%i", &sum);

  resta=sum%500;
  divisio=sum/500;
  printf("Necessita %i bitllets de %i€\n",divisio,500);
  divisio=resta/200;
  resta=resta%200;
  printf("Necessita %i bitllets de %i€\n",divisio,200);
  divisio=resta/100;
  resta=resta%100;
  printf("Necessita %i bitllets de %i€\n",divisio,100);
  divisio=resta/50;
  resta=resta%50;
  printf("Necessita %i bitllets de %i€\n",divisio,50);
  divisio=resta/20;
  resta=resta%20;
  printf("Necessita %i bitllets de %i€\n",divisio,20);
  divisio=resta/10;
  resta=resta%10;
  printf("Necessita %i bitllets de %i€\n",divisio,10);
  divisio=resta/5;
  resta=resta%5;
  printf("Necessita %i bitllets de %i€\n",divisio,5);
  divisio=resta/2;
  resta=resta%2;
  printf("Necessita %i mondedes de %i€\n",divisio,2);
  printf("Necessita %i mondedes de %i€\n",resta,1);
  return 0;
}
