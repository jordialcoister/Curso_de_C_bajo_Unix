#include <stdio.h>

#define FRASE1 "Introduexi el límit superior:"

int main(int argc, char *argv[])
{
  int N;
  
  printf("%s\n", FRASE1);
  scanf("%i", &N);
  for (int i=1; i<N; i+=2){
    printf("%i,",i);
  }
  return 0;
}
