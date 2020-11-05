#include <stdio.h>
/* #include <stdlib.h> */
#include "matrices.h"

int main(int argc, char *argv[])
{
  t_imatrix *A,*B,*C,*D,*Z,*I;
  int value;
  int *A_values,*B_values,*C_values;

  A=im_create(5,3);
  D=im_create(3,5);
  Z=im_create(5,5);
  im_print(Z);
  I=im_identity_create(25,25);
  im_print(I);

  printf("Files: %d, Columnes: %d\n",A->rows,A->columns );
  for (int i=0; i<A->rows; i++){
    for (int j=0; j<A->columns; j++){
      value=im_insert(A,i+j,i,j);
    }
  }
  
  for (int i=0; i<D->rows; i++){
    for (int j=0; j<D->columns; j++){
      value=im_insert(D,i+j,i,j);
    }
  }

  im_print(A);
  im_row_multiply(A,2,-5);
  im_print(A);
  im_print(D);
  B = im_add(A,A);
  im_print(B);
  C = im_mult(A,D);
  if (C)
    im_print(C);
  B = im_sub(B,A);
  im_print(B);
  im_scalarprod(B,9);
  im_print(B);
  C = im_trans(B);
  im_print(C);

  im_destroy(A);
  im_destroy(B);  
  im_destroy(C);
  
  return 0;
}
