#include <stdio.h>
#include <stdlib.h>

#define TITOL "SUMA DE MATRIUS QUADRADES DE"
#define SUB "================================"
#define INTRO "Introduexi la posició: "
#define PRIMERA "PRIMERA MATRIU\n=============\n"
#define SEGONA "SEGONA MATRIU\n=============\n"

#define MIDA 3

float *suma_matrius(float A[][MIDA], float B[][MIDA]){
  /* Per a poder passar una matriu bidireccional, s'ha de saber la mida de
   les columnes, i s'ha de passar així.*/

  float *C;
  /* Al fer malloc, es reserva la memòria en espai de programa i és
   accessible des de tot el programa, no només des de la funció */

  C = malloc(sizeof(float)*MIDA*MIDA);
  for (int i=0; i < MIDA; i++){
    for (int j=0; j < MIDA; j++){
      *(C + i*MIDA + j) = A[i][j] + B[i][j];
      /* *(C + i*MIDA + j) = *(A + MIDA*i + j) + *(B + MIDA*i + j); */
    }
  }
  return C;
}

int main()
{
  float A[MIDA][MIDA],B[MIDA][MIDA];
  float *C;

  system("clear");
  printf("%s %dx%d\n", TITOL, MIDA, MIDA);
  printf("%s\n\n", SUB);

  /* Recollim les dades */
  printf("Matriu 1\n==========\n");
  for (int i=0; i<MIDA; i++){
    for(int j=0; j<MIDA; j++){
      printf("%s %d,%d\n", INTRO,i,j);
      scanf("%f", &A[i][j]);
    }
  }
  printf("Matriu 2\n==========\n");
  for (int i=0; i<MIDA; i++){
    for(int j=0; j<MIDA; j++){
      printf("%s %d,%d\n", INTRO,i,j);
      scanf("%f", &B[i][j]);
    }
  }

  /* Sumem les matrius */
  C=suma_matrius(A,B);
  
  /* Imprimim les dues matrius i la suma*/
    for (int i=0; i<MIDA; i++){
      printf("[ ");
      for(int j=0; j<MIDA; j++){
	printf("%f ", A[i][j]);
      }
      if (i == 1)
	printf("]+[ ");
      else
	printf("] [ ");
      for(int j=0; j<MIDA; j++){
	printf("%f ", B[i][j]);
      }
      if (i == 1)
	printf("]=[ ");
      else
	printf("] [ ");
      for(int j=0; j<MIDA; j++){
	printf("%f ", *(C+MIDA*i+j));
      }
      printf("]\n");
    }
    return 0;
}

