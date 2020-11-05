#include <stdio.h>

#define PROMPT "Escriga un nombre senzer i invertiré les xifres"

int main(int argc, char *argv[])
{
  int num,digit,divisor=10,invertit=0,pos=0;
  
  printf("%s\n",PROMPT);
  scanf("%i", &num);

  while(num > 0){
    digit=num%divisor;
    num/=10;
    invertit=invertit*divisor+digit;
  }
  printf("%i\n", invertit);
    
  return 0;
}
