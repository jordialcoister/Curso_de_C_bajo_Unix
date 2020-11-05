#include <stdio.h>

#define DEMANA_ALT "Introdueixi el número alt: "
#define DEMANA_BAIX "Introdueixi el númeo baix: "

int main(int argc, char *argv[])
{
  int alt1, baix1, alt2, baix2;
  
  printf("%s\n", DEMANA_ALT);
  scanf("%i", &alt1);
  printf("%s\n", DEMANA_BAIX);
  scanf("%i", &baix1);

  printf("%s\n", DEMANA_ALT);
  scanf("%i", &alt2);
  printf("%s\n", DEMANA_BAIX);
  scanf("%i", &baix2);
  
  
  return 0;
}
