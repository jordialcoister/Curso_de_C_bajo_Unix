#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fitx;
  unsigned int dada,i,zeroes=0,cont=0;
  float mitjana=0.0;

  fitx = fopen("puntuacions.dat","w");
  for (i=0; i<100; i++){
    dada=rand()%10; 	/* emmagatzemem valors d'u a deu */
    printf("%i\n",dada);
    fwrite(&dada,sizeof(int),1,fitx);    
  }
  freopen("puntuacions.dat","r",fitx);
  rewind(fitx);
  fread(&dada,sizeof(int),1,fitx);
  while(!feof(fitx)){
    if (!dada || dada <0){
      zeroes++;
    } else {
      cont++;
      mitjana+=dada;
      /* printf("%i->%f,",dada,mitjana); */ 
    }
    fread(&dada,sizeof(int),1,fitx);
  }
  mitjana/=cont;
  printf("La mitjana és: %f\nEl nombre de zeros és %i\n", mitjana, zeroes);
  if (fclose(fitx)){
    exit(EXIT_SUCCESS);
  } else {
    exit(EXIT_FAILURE);
  }
}
