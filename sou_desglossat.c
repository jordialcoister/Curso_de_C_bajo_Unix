#include <stdio.h>

#define BRUT "Escriga el sou brut i jo el desglossaré: "
#define NET "El sou net resultat és de: "

int main(int argc, char *argv[])
{
  float sou_brut,sindicat,impostos;

  printf(BRUT);
  scanf("%f", &sou_brut);
  sindicat = 100-sou_brut*0.01;
  printf("%f\n", sindicat);
  impostos = sou_brut*0.25;
  printf("%f\n", impostos);
    
  printf("%s%f\n",NET,sou_brut-sindicat-impostos);
  return 0;
}

