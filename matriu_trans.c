#include <stdio.h>
#include <stdlib.h>

#define TITOL "MATRIU TRANSPOSADA DE "
#define SUB "=============================="
#define INTRO "Introduexi la posició: "

#define MIDA 5

int main(int argc, char *argv[])
{
  float matriu[MIDA][MIDA],trans[MIDA][MIDA];

  system("clear");
  printf("%s %dx%d\n", TITOL, MIDA, MIDA);
  printf("%s\n\n", SUB);

  /* Anem transposant la matriu a mesura que recollim les dades */
  for (int i=0; i<MIDA; i++){
    for(int j=0; j<MIDA; j++){
      printf("%s %d,%d\n", INTRO,i,j);
      scanf("%f", &matriu[i][j]);
      trans[j][i]=matriu[i][j];
    }
  }
  for (int i=0; i<MIDA; i++){
    printf("[ ");
    for(int j=0; j<MIDA; j++){
      printf("%f ", matriu[i][j]);
    }
    if (i == 3)
      printf("]=>[ ");
    else
      printf("]  [ ");
    for(int j=0; j<MIDA; j++){
      printf("%f ", trans[i][j]);
    }
    printf("]\n");
  }  
  return 0;
}

