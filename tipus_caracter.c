#include <stdio.h>

#define PROMPT "Escriga una caràcter i li diré de quin tipus és"
#define RES "El caràcter és"
#define MAJ "una lletra majúscula"
#define MIN "una lletra minúscula"
#define DIGIT "un dígit"
#define ESPAI "un espai"
#define PUNT "un caràcter de puntuació"
#define ESPECIAL "un caràcter especial"

int main(int argc, char *argv[])
{
  char caracter;

  printf("%s\n", PROMPT);
  scanf("%c", &caracter);

  if (caracter > 64 && caracter < 91)
    printf("%s %s\n", RES, MAJ);
  else {
    if (caracter > 96 && caracter < 123)
      printf("%s %s\n", RES, MIN);
    else {
      if (caracter > 47 && caracter < 58)
	printf("%s %s\n", RES, DIGIT);
      else {
	if (caracter == 32 )
	  printf("%s %s\n", RES, ESPAI);
	else {
	  if (caracter == 44 || caracter == 46)
	    printf("%s %s\n", RES, PUNT);
	  else {
	    if (caracter < 32 || caracter == 127)
	      printf("%s %s\n", RES, ESPECIAL );
	  }
	}
      }
    }
  }
  return 0;
}
