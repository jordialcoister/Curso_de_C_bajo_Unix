#include <stdio.h>

#define peticio1 "Escriga el primer número"
#define peticio2 "Escriga el segon número"

int main(int argc, char *argv[])
{
  int x,y;
  
  printf("%s\n", peticio1);
  scanf("%i", &x);
  printf("%s\n", peticio2);
  scanf("%i", &y);

  return 0;
}
