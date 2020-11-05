#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TITOL "SUMA NOMBRES NATURALS DE FINS A 40 XIFRES"
#define SUB "========================================="

#define INTRO_1 "Introdueixi el primer nombre, de fins a 40 digits:\n"
#define INTRO_2 "Introdueixi el segon nombre, de fins a 40 digits:\n"

#define MAX_DIGITS 41

int main(int argc, char *argv[])
{
  char num1[MAX_DIGITS], num2[MAX_DIGITS], suma[MAX_DIGITS+1];
  char suma_digit=0, portes=0, i, tam1, tam2;

  system("clear");

  printf("%s\n", TITOL);
  printf("%s\n", SUB);

  printf("%s", INTRO_1);
  scanf("%s", num1);
  len1 = strlen(num1);

  printf("%s", INTRO_2);
  scanf("%s", num2);
  len2 = strlen(num2);

  /* Farcim els números a l'esquerra amb zeros */
  for (int i=MAX_DIGITS; i>=strlen(num1); i--){
    num1[i]='0';
  }
  for (int i=strlen(num2); i<MAX_DIGITS-1; i++){
    num2[i]='0';
  }
  

  
  /* if (len1 >= len2) */
  /*   max_len=len1; */
  /* else */
  /*   max_len=len2; */

  /* calculem la suma */
  for (i=MAX_DIGITS-1;i>=0; i--){
    /* if (isdigit(num1[i]) && (isdigit(num2[i])){ */
    printf("Posició %i => %c + %c\n",i, num1[i],num2[i]);
    suma_digit=(num1[i]||'0')+(num2[i]||'0')+portes-48;
    if (suma_digit > 57){
      suma_digit=suma_digit%58+30;
      portes='1';
    } else {
      portes=0;
    }
    printf("unitat: %c desena:%c\n", suma_digit, portes);
    suma[i]=suma_digit;
  }
  /* printf("S'ha produit un desbordament"); */
  suma[i]=0;
  printf("%s + %s = %s\n",num1,num2,suma );
      
  return 0;
}

