#include <stdio.h>
#include "matrices.h"

int main()
{
  t_imatrix *A,*T;

  A=im_create(3,3);
  for (int i=0; i<A->rows; i++){
    for (int j=0; j<A->rows; j++){
      *((A->values)+i*A->rows+j)=i+j;
      /* printf("%d\n",*((A->values)+i*A->rows+j)); */
    }
  }
  im_print(A);
  T=im_trans(A);
  im_scalarprod(T,3);
  im_print(T);
  im_row_add_another_multi(A,1,2,5);
  im_print(A);
  im_row_x(A,1,2);
  im_print(A);
  
  im_destroy(A);
  im_destroy(T);
  return 0;
}
