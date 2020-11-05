#include <stdio.h>
#include <stdlib.h>

#define TITOL "CALCULA LA SUMA DELS VALORS DE LES FILES I COLUMNES D'UNA MATRIU "
#define SUB "========================================================================"
#define INTRO "Introduexi la posició: "

#define MIDA 4

int main(int argc, char *argv[])
{
  float matriu[MIDA][MIDA],suma_files[MIDA],suma_cols[MIDA];

  system("clear");
  printf("%s %dx%d\n", TITOL, MIDA, MIDA);
  printf("%s\n\n", SUB);

  /* inicialitzem els vectors de les sumes a zero */
  for(int i=0; i<MIDA; i++){
    suma_files[i]=0.0;
    suma_cols[i]=0.0;
  }
  
  /* Recollim les dades i anem obtenint les suma de les files */
  for (int i=0; i<MIDA; i++){
    for(int j=0; j<MIDA; j++){
      printf("%s %d,%d\n", INTRO,i,j);
      scanf("%f", &matriu[i][j]);
      suma_files[i]+=matriu[i][j];
    }
  }
  /* una vegada obtingudes les sumes de les files, obtenim les de les columnes */
  for (int j=0; j<MIDA; j++){
    for (int i=0; i<MIDA; i++){
      suma_cols[j]+=matriu[i][j];
    }
  }

  /* Imprimim, la matriu i les sumes corresponents */
  for (int i=0; i<MIDA; i++){
    printf("[ ");
    for(int j=0; j<MIDA; j++){
      printf("%f ", matriu[i][j]);
    }
    printf(", %f]\n", suma_files[i]);
  }
  for (int i=0; i<MIDA; i++){
    printf("%f ", suma_cols[i]);
  }
  printf("\n");
  
  return 0;
}

