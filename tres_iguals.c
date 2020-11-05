#include <stdio.h>

#define PETICIO1 "Si us plau, escriga el primer nombre: "
#define PETICIO2 "Ara el segon: "
#define PETICIO3 "I per a acabar, el tercer "
#define TRES_IGUALS "Els tres nombres són iguals"
#define DOS_IGUALS "Hi ha dos nombres iguals"
#define DIFERENTS "Tots els nombres són diferents"

int main(int argc, char *argv[])
{
  int a,b,c;
  
  printf("%s\n", PETICIO1);
  scanf("%i", &a);
  printf("%s\n", PETICIO2);
  scanf("%i", &b);
  printf("%s\n", PETICIO3);
  scanf("%i", &c);

  if (a == b)
    if (b == c)
      printf("%s\n", TRES_IGUALS);
    else
      printf("%s\n", DOS_IGUALS);
  else
    if (b == c || a == c) 
      printf("%s\n", DOS_IGUALS);
    else
      printf("%s\n",DIFERENTS );      
  return 0;
}
