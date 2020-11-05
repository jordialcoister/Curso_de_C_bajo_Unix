#include <stdio.h>
#include <stdlib.h>

#define TITOL "CALCULA LA MATRIUS RESULTANT DE RESTAR A CADA ELEMENT DE LA MATRIU LA MITJANA DE LA SEUA COLUMNA"
#define SUB "================================================================================================"
#define M 4
#define N 3 

#define INTRO "Introduexi la posició: "

int main(int argc, char *argv[])
{
  float matriu[M][N], mitjana_cols[N];

  system("clear");
  
  printf("%s \n", TITOL);
  printf("%s\n\n", SUB);

  /* inicialitzem els vectors de les sumes a zero */
  for(int i=0; i<M; i++){
    mitjana_cols[i]=0.0;
  }
  
  /* Recollim les dades */
  for (int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      printf("%s %d,%d\n", INTRO,i,j);
      scanf("%f", &matriu[i][j]);
    }
  }
  
  /* Imprimim la matriu per pantalla */
  for (int i=0; i<M; i++){
    printf("[ ");
    for(int j=0; j<N; j++){
      printf("%f ", matriu[i][j]);
    }
    printf("]\n");
  }

  /* una vegada introduides totes les dades, obtenim la mitjana aritmètica de les de les columnes */
  for (int j=0; j<N; j++){
    for (int i=0; i<M; i++){
      mitjana_cols[j]+=matriu[i][j];
    }
    mitjana_cols[j]/=M;
    printf("Mitjana columa %i = %f\n",j,mitjana_cols[j]);
  }
  
  /* Imprimim, la matriu resultant de restar a cada element la mitjana de la seua columna */
  for (int i=0; i<M; i++){
    printf("[ ");
    for(int j=0; j<N; j++){
      printf("%f ", matriu[i][j]-mitjana_cols[j]);
    }
    printf("]\n");
  }
  return 0;
}

