#include <stdio.h>

#define DEMANA_NUM "Si us plau, introdueixi el número del qual vol obtindre l'arrel quadrada: "
#define DEMANA_TOLERANCIA "Quina és la tolerància admissible?: "

int main(int argc, char *argv[])
{
  int A;
  float tolerancia,n=5,m,dif;

  printf("%s\n", DEMANA_NUM);
  scanf("%d", &A);
  printf("%s\n", DEMANA_TOLERANCIA);
  scanf("%f", &tolerancia);

  do{
    m=(n+A/n)/2;
    dif=m-n;
    if (dif < 0)
      dif=-dif;
    n=m;
  } while (dif>tolerancia);
  printf("L'arrel quadrada de %d és %f\n",A,m);
		  
  return 0;
}
