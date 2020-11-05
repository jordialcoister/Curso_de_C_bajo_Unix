#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  FILE *fitx;
  int paraules=0;
  char nom_fitxer[60];
  char caracter;

  printf("Introdueixi el nom del fitxer a llegir: ");
  scanf("%s", nom_fitxer);
  fitx = fopen(nom_fitxer, "r");
  if (fitx != NULL){
    fscanf(fitx,"%c",&caracter);
    while (!feof(fitx)){
      if((caracter=='\n') || (caracter == '\r') || isblank(caracter)){
	paraules++;
	/* printf("%d\n",caracters); */
      }
      fscanf(fitx,"%c",&caracter);
      printf("%c",caracter);
    }
    printf("El fitxer té: %d paraules\n", paraules);
    fclose(fitx);
  } else {
    printf("El fitxer no existeix\n");
    exit(1);
  }
  exit(0);
}
