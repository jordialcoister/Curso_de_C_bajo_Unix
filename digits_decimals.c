#include <stdio.h>

#define PETICIO "Si us plau, introduïu un nombre i us diré quants dígits ocupa: "

int main(int argc, char *argv[])
{
  int num,digits=0,pos=1;

  printf("%s\n", PETICIO);
  scanf("%i", &num);

  while(num/pos!=0){
      digits++;
      pos*=10;
  }
  printf("El nombre ocupa %i digits\n",digits);
  return 0;
}
