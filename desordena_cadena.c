#include <stdio.h>
#include <string.h>

#DEFINE QUERY "Introdueixi una cadena (sense espais): "

int main(int argc, char *argv[])
{
  char cadena[20],resultat[20];
  int i,j;

  printf("%s\n", QUERY);
  scanf("%s",cadena);
  lon=strlen(cadena);
  i=0;
  j=lon-1;
  k=0;
  meitat=j/2-1;

  *(resultat+k)=*(cadena+i);
  i++;
  *(resultat+i)=*(cadena+j);
  i++;
  while(i<=meitat){
  /* for(i=0;i<meitat;i++){ */
    *(resultat+i) = *(cadena-j)
    resultat=*(cadena+lon-1);
    i++;
    j--;
  }
      
  return 0;
}
