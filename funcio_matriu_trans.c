#include <stdio.h>
#include <stdlib.h>

#define TITOL "MATRIU TRANSPOSADA DE "
#define SUB "=============================="
#define INTRO "Introduexi la posició: "

#define MIDA 3

void itrans(float A[][MIDA], int row, int col){
  float *T;
  int i,j;
  
  T = (float*) malloc(sizeof(float)*row*col);

  /* La copiem tota */
  for (i=0; i<row; i++){
    for(j=0; j< col; j++){
        *(T+i*col+j) = A[i][j];
    }
  }
  /* Ara transposem A */
  for (i=0; i<row; i++){
    for(j=0; j< col; j++){
      A[i][j] = *(T+j*col+i);
    }
  }
  
}

int main(int argc, char *argv[])
{
  float matriu[MIDA][MIDA],trans[MIDA][MIDA];

  system("clear");
  printf("%s %dx%d\n", TITOL, MIDA, MIDA);
  printf("%s\n\n", SUB);

  /* Recollim les dades de la matriu */
  for (int i=0; i<MIDA; i++){
    for(int j=0; j<MIDA; j++){
      printf("%s %d,%d\n", INTRO,i,j);
      scanf("%f", &matriu[i][j]);
    }
  }
  /* Obtenim la transposada */
  itrans(matriu, MIDA, MIDA);
  for (int i=0; i<MIDA; i++){
    printf("[ ");
    for(int j=0; j<MIDA; j++){
      printf("%f ", matriu[i][j]);
    }
    printf("]\n");
  }  
  return 0;
}

