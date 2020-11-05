#include <stdio.h>

#define PROMPT "Quants nombres triangulars vol obtindre?: "

int main(int argc, char *argv[])
{
  int N=0,suma=0;
  
  printf("%s\n", PROMPT);
  scanf("%i", &N);

  /* for (int i=1; i<=N; i++){ */
  /*   suma=0 */
  /*   for (int j=1; j<=i; j++){ */
  /*     suma= */
  /*   } */
  /* } */
  for (int i=1; i<=N; i++){
    suma+=i;
    printf("%i\n", suma);
  }
  return 0;
}
