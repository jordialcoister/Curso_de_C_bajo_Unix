#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fitx;
  int caracters=0,linies=0;
  char nom_fitxer[60];
  char caracter;

  printf("Introdueixi el nom del fitxer a llegir: ");
  scanf("%s", nom_fitxer);
  fitx = fopen(nom_fitxer, "r");
  if (fitx != NULL){
    fscanf(fitx,"%c",&caracter);
    while (!feof(fitx)) {
      if(caracter!='\n'){
	caracters++;
	/* printf("%d\n",caracters); */
	fscanf(fitx,"%c",&caracter);
      } else {
	linies++;
	fscanf(fitx,"%c",&caracter);
	/* printf("Nova línia: %d\n",linies ); */
      }
    }
    printf("Línies: %d, caràcters: %d\n", linies,caracters);
    fclose(fitx);
  } else {
    printf("El fitxer no existeix\n");
    exit(1);
  }
  exit(0);
}
