#include <stdio.h>
#include <stdlib.h>

#define TITOL "CERCA UNA CADENA DINS D'UNA ALTRA"
#define SUB "================================"
#define INTRO_TEXT "Introduexi el text: "
#define INTRO_CADENA "Introduexi la cadena cercar: "

char *cerca_cadena(char *text, char *str){
  int  i=0, j=0, n=0;

  while ((text[i] != '\0') && (str[j] != '\0')){
    /* printf("%i, %i \n",i,j); */
    if(text[i]==str[j]){
      j++;
      i++;
      n++;
    }
    else{
      i++;
      j=0;
      n=0;
    }
  }
  if ( n > 0 ){
    return text+i-n;
  }
  else{
    return NULL;
  }
}

int main(int argc, char *argv[])
{
  char text[50],cadena[50];
  char *pos;
    
  printf("%s\n", TITOL);
  printf("%s\n", SUB);
  printf("\n%s\n", INTRO_TEXT);
  fgets(text, sizeof(text), stdin);
  printf("\n%s\n", INTRO_CADENA);
  fgets(cadena, sizeof(cadena), stdin);

  pos=cerca_cadena(text,cadena);

  if (pos){
    printf("He trobat la cadena\n");
  } else {
    printf("No l'he trobat\n");
  }
  
  return 0;
}
