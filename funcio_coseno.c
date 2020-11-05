#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define ERROR 0.00000001

float deg2rad(float degrees){
  return degrees*2*PI/360;
}

float coseno(float radians){
  int i,j;
  float cos, num, denom, iter;

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

  return cos;
}

int main(int argc, char *argv[])
{
  float radians;
  char graus;

  for(graus=0; graus<=20; graus++){
    /* radians=2*PI/360*graus; */
    radians=deg2rad(graus);
    printf("cos(%d)=%f\n",graus,coseno(radians));
  }  
  return 0;
}
