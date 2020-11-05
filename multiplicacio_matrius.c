#include <stdio.h>
#include <stdlib.h>

#define TITOL "CALCULA EL PRODUCTE DE DUES MATRTIUS "
#define SUB "========================================"
#define MIDA 4

#define INTRO "Introduexi la posició: "


int main(int argc, char *argv[])
{
  int matrius[3][MIDA][MIDA], producte[MIDA][MIDA], i,j,k,z;

  system("clear");
  
  printf("%s %dx%d\n", TITOL, MIDA,MIDA);
  printf("%s\n\n", SUB);

  /* Recollim les dades */
  for (z=0; z<2; z++){ 
    printf("Matriu %i\n==========\n",z);
    for (i=0; i<MIDA; i++){
      for(j=0; j<MIDA; j++){
	printf("%s %d,%d\n", INTRO,i,j);
	scanf("%d", &matrius[z][i][j]);
      }
    }
  }
  
  for (i=0; i<MIDA; i++){
    for (j=0; j<MIDA; j++){
      matrius[2][i][j]=0;
    }
  }

  /*** Calculem el producte ***/
  
  /* recorrem cada fila */
  for (k=0; k< MIDA; k++){
    /* ara recorrem files i columnes, de la manera habitual */
    for (i=0; i<MIDA; i++){
      for (j=0; j<MIDA; j++){
	matrius[2][k][i]+=matrius[0][j][i]*matrius[1][i][j];
      }
    }
  }
  /* Imprimim les dues matrius i el producte*/
  for (i=0; i<MIDA; i++){
    printf("[ ");
    for(j=0; j<MIDA; j++){
      printf("%d ", matrius[0][i][j]);
    }
    if (i == 1)
      printf("]*[ ");
    else
      printf("] [ ");
    for(j=0; j<MIDA; j++){
      printf("%d ", matrius[1][i][j]);
    }
    if (i == 1)
      printf("]=[ ");
    else
      printf("] [ ");
    for(j=0; j<MIDA; j++){
      printf("%d ", matrius[2][i][j]);
    }
    printf("]\n");
  }
}
