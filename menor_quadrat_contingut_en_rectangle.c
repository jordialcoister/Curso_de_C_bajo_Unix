#include <stdio.h>

#define frase1 "Escriga un costat del rectangle"
#define frase2 "Escriga l'altre costat del rectangle"
#define frase3 "El costat del menor quadrat contingut en el rectangle definit és:"

int main(int argc, char *argv[])
{
  int a, b, c;
  
  printf("%s\n",frase1);
  scanf("%i", &a);
  printf("%s\n",frase2);
  scanf("%i", &b);
  if ( a > b ){
    c=b;
  } else {
    c=a;
  }
  printf("%s %i\n",frase3,c);
  return 0;
}
