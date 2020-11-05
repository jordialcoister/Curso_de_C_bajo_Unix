#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define DEMANA_NUM "Si us plau, introdueixi el número del qual vol obtindre l'arrel cubica: "
#define DEMANA_TOLERANCIA "Quina és la tolerància admissible?: "

int main(int argc, char *argv[])
{
  int A;
  double tolerancia,n,m=1.0;

  printf("%s\n", DEMANA_NUM);
  scanf("%d", &A);
  printf("%s\n", DEMANA_TOLERANCIA);
  scanf("%lf", &tolerancia);

  do{
    n=m;
    m=(A/(n*n)+2*n)/3;
    //resultat+=m;
    printf("m=%lf,n=%lf\n",m,n);
  } while (fabs(m-n)>tolerancia);
  printf("L'arrel cubica de %d és %f\n",A,m);
		  
  return 0;
}
