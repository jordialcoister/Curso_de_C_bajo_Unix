#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define ERROR 0.00000001

int main(int argc, char *argv[])
{
  float radians,cos,num,denom,iter;
  char graus;
  int i,j;

  for(graus=0; graus<=20; graus++){
    radians=2*PI/360*graus;
    i=2;
    do{
      cos=1;
      num=pow(radians,i);
      denom=1;
      for(int j=i; j>1; j--){
	denom*=j;
      }
      iter=pow(-1,j-1)*num/denom;
      cos+=iter;
    } while (iter>ERROR);
    printf("cos(%d)=%f\n",graus,cos);
  }  
  return 0;
}
