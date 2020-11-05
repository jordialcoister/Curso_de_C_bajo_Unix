#include <stdio.h>
#include <stdlib.h>

#define TITOL "SUMA DE MATRIUS QUADRADES DE"
#define SUB "================================"
#define INTRO "Introduexi la posició: "
#define PRIMERA "PRIMERA MATRIU\n=============\n"
#define SEGONA "SEGONA MATRIU\n=============\n"

#define MIDA 5

int main()
{
  float matriu[2][MIDA][MIDA];
  
  system("clear");
  printf("%s %dx%d\n", TITOL, MIDA, MIDA);
  printf("%s\n\n", SUB);

  /* Recollim les dades */
  for (int z=0; z<2; z++){ 
    printf("Matriu %i\n==========\n",z);
    for (int i=0; i<MIDA; i++){
      for(int j=0; j<MIDA; j++){
	printf("%s %d,%d\n", INTRO,i,j);
	scanf("%f", &matriu[z][i][j]);
      }
    }
  }
  
  /* Imprimim les dues matrius i la suma*/
    for (int i=0; i<MIDA; i++){
      printf("[ ");
      for(int j=0; j<MIDA; j++){
	printf("%f ", matriu[0][i][j]);
      }
      if (i == 1)
	printf("]+[ ");
      else
	printf("] [ ");
      for(int j=0; j<MIDA; j++){
	printf("%f ", matriu[1][i][j]);
      }
      if (i == 1)
	printf("]=[ ");
      else
	printf("] [ ");
      for(int j=0; j<MIDA; j++){
	printf("%f ", matriu[1][i][j]+matriu[0][i][j]);
      }
      printf("]\n");
    }
  return 0;
}
