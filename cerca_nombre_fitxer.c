#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fitx;
  unsigned int dada,i=0,zeroes=0,cont=0,cerca;
  float mitjana=0.0;

  /* fitx = fopen("puntuacions.dat","w"); */
  /* for (i=0; i<100; i++){ */
  /*   dada=rand()%10; 	/\* emmagatzemem valors d'u a deu *\/ */
  /*   printf("%i\n",dada); */
  /*   fwrite(&dada,sizeof(int),1,fitx);     */
  /* } */
  /* freopen("puntuacions.dat","r",fitx); */
  printf("Nombre a buscar: ");
  scanf("%ui",&cerca);
  fitx=fopen("puntuacions.dat","r");
  fread(&dada,sizeof(int),1,fitx);
  /* dada = !EOF; */
  while(!feof(fitx)){
    fread(&dada,sizeof(unsigned int),1,fitx);
    /* printf("%ui\n",dada); */
    if (dada == cerca){
      printf("He trobat el nombre a la posició: %i\n",cont);
    }
    cont++;
  }
  /* mitjana/=cont; */
  /* printf("La mitjana és: %f\nEl nombre de zeros és %i\n", mitjana, zeroes); */
  if (fclose(fitx)){
    exit(EXIT_SUCCESS);
  } else {
    exit(EXIT_FAILURE);
  }
}
