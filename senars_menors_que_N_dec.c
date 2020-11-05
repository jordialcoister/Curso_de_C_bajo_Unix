#include <stdio.h>

#define FRASE1 "Introduexi el límit superior:"

int main(int argc, char *argv[])
{
  int N;
  
  printf("%s\n", FRASE1);
  scanf("%i", &N);
  if ( N%2 != 0 )
    N--;
  for (int i=N-1; i>0; i-=2){
    printf("%i,",i);
  }
  return 0;
}
