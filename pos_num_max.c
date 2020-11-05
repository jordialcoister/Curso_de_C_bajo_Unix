#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fitx_lec,*fitx_esc;
  unsigned int dada=EOF,pos=0,zeroes=0,max=0,i;

  fitx_esc = fopen("numero.dat","w");
  for (i=0; i<100; i++){
    dada=rand()%1000; 	/* emmagatzemem valors d'u a deu */
    printf("%i\n",dada);
    fprintf(fitx_esc,"%ui\n",dada);
  }
  fclose(fitx_esc);
  fitx_esc=fopen("maxims.dat","w");
  fitx_lec=fopen("numero.dat","r");
  fscanf(fitx_lec,"%ui",&dada);

  while(!feof(fitx_lec)){
    if (dada > max){
      max=dada;
      printf("nou max: %u",max);
    }
    fscanf(fitx_lec,"%ui",&dada);
  }
  rewind(fitx_lec);
  fscanf(fitx_lec,"%ui",&dada);

  while(!feof(fitx_lec)){
    if (dada == max){
      fprintf(fitx_esc,"%u\n",pos);
    }
    pos++;
    fscanf(fitx_lec,"%ui",&dada);
  }
  
  if (fclose(fitx_lec) && fclose(fitx_esc)){
    exit(EXIT_SUCCESS);
  } else {
    exit(EXIT_FAILURE);
  }
}
