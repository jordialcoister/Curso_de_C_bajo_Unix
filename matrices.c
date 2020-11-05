#include <stdlib.h>
#include <stdio.h>
#include "matrices.h"

t_imatrix *im_create(int rows, int cols){
  t_imatrix *matrix;
  int i;

  if ((rows >= 0) && (cols>=0)){
    /* resevem memòria per a la matriu */
    matrix = (t_imatrix*) malloc(sizeof(t_imatrix));
    
    /* assignem els paràmetres i reservem memòria per a les dades de la matriu */
    /* L'assignament de files i columnes funciona bé */
    matrix->rows=rows;
    matrix->columns=cols;
    
    matrix->values = (int *) malloc(sizeof(int)*rows*cols);
    for (i=0; i<rows*cols; i++){
      *(matrix->values+i)=0;
    }
    return matrix;
  }
}

t_imatrix *im_identity_create(int rows, int cols){
  t_imatrix *I;
  int i,j;

  I=im_create(rows, cols);
  for (i=0;i<rows;i++){
    for (j=0;j<cols;j++){
      if(i==j)
	im_insert(I,1,i,j);
      else
	im_insert(I,0,i,j);
    }
  }
  return I;
}

int im_insert(t_imatrix *A, int value, int row, int col){
  int pos = (A->columns)*row + col;
  
  *(A->values+pos)=value;
  return *(A->values+pos);
}

int im_row_x(t_imatrix *A, int row1, int row2){
  int i, temp;

  if (A && (row1 <= A->rows) && (row1 <= A->rows) && (row1 != row2)){
    for (i = 0; i < A->columns; i++) {
      temp=*(A->values+(row1-1)*A->columns+i);
      *(A->values+(row1-1)*A->columns+i)=*(A->values+(row2-1)*A->columns+i);
      *(A->values+(row2-1)*A->columns+i)=temp;
    }
    return 0;
  } else {
    return 1;
  }
}

int im_row_multiply(t_imatrix *A, int row, int m){
  int i;
 
  if (A && (row <= A->rows) && (m != 0)){
    for (i = 0; i < A->columns; i++) {
      *(A->values+(row-1)*A->columns+i)*=m;
    }
    return 0;
  } else {
    return 1;
  }
}

int im_row_add_another_multi(t_imatrix *A, int row1, int row2, int m){
  int i,n;

  if (A && (row1 <= A->rows) && (row2 <= A->rows) && (m!=0)){
    for (i=0; i<A->columns; i++){
      *(A->values+(row1-1)*A->columns+i)=
	*(A->values+(row1-1)*A->columns+i)+
	*(A->values+(row2-1)*A->columns+i)*m;
    }
    return 0;
  } else {
    return 1;
  }
}

t_imatrix *im_add(t_imatrix *A, t_imatrix *B){
  t_imatrix *S;
  int a,b;

  /* Per a poder-les sumar, han de ser de la mateixa mida */
  if ((A->columns == B->columns) && (A->rows == B->rows)){
    /* Reservem memòria per a ells */
    S=im_create(A->rows,A->columns);
    
    for (int i=0; i<A->rows; i++){
      for (int j=0; j<A->columns; j++){
	a=*(A->values+i*B->columns+j);
	b=*(B->values+i*B->columns+j);
	*(S->values+i*(S->columns)+j) = a + b;
      }
    }
  }
  return S;
}

t_imatrix *im_sub(t_imatrix *A, t_imatrix *B){
  t_imatrix *S;
  /* int a,b; */

  /* Tot i que es podria haver implementar mitjançant la suma de
     matrius i el producte escalar (A+(-1)*B), no era una opció gens
     òptima */
  
  /* Per a poder-les restar, han de ser de la mateixa mida */
  if ((A->columns == B->columns) && (A->rows == B->rows)){
    /* Reservem memòria per a ells */
    S=im_create(A->rows,A->columns);
    
    for (int i=0; i<A->rows; i++){
      for (int j=0; j<A->columns; j++){
	/* a=*(A->values+i*B->columns+j); */
	/* b=*(B->values+i*B->columns+j); */
	/* *(S->values+i*(S->columns)+j) = a + b; */
	*(S->values+i*(S->columns)+j) = *(A->values+i*B->columns+j) - *(B->values+i*B->columns+j); 
      }
    }
  }
  return S;
}

t_imatrix *im_mult(t_imatrix *A, t_imatrix *B){
  t_imatrix *M;
  int i,j,k,a,b,c;

  if ( A->columns != B->rows){
    M=NULL;
    printf("%s\n", ERR_PROD_1);
    /* print an error with perror */
  } else {
    M = im_create(A->rows,B->columns);
    printf("El producte tindrà %d files i %d column\n",M->rows,M->columns);
    for (k=0; k<A->rows; k++){
      /* ara recorrem files i columnes, de la manera habitual */
      for (i=0; i<A->rows; i++){
	for (j=0; j<A->columns; j++){
	  a = *(A->values+i*A->columns+j);
	  b = *(B->values+j*B->columns+i);
	  c = *(M->values+M->columns*k+i);
	  /* printf("M[%d]+=A[%d,%d]*B[%d,%d]",i,i,j,j,i); */
	  /* printf("M[%d]+=A[%d]*B[%d]",i,i*A->columns+j,j*B->columns+i); */
	  /* printf("a=%d,b=%d,c=%d\n",a,b,c); */
	  *(M->values+M->columns*k+i) += c + a * b;
	}
      }
    }
  }

  return M;
}

void im_scalarprod(t_imatrix *A, int m){
  int rows,cols;
  rows=A->rows;
  cols=A->columns;
  int *values;
  
  values = A->values;
  
  for (int i=0; i<rows*cols; i++){
    *(values+i)=*(values+i)*m;
  }
}

t_imatrix *im_trans(t_imatrix *A){
  t_imatrix *T;

  if ((A->rows>0) && (A->columns>0)){
    T=im_create(A->columns,A->rows);
    
    for (int j=0; j<T->columns; j++){
      for (int i=0; i<T->rows; i++){
	/* printf("%d->%d\n",j*T->rows+i,i*A->rows+j); */
	*(T->values+j*T->columns+i)=*(A->values+i*A->columns+j);
      }
    }
  }
  return T;
}

int im_destroy(t_imatrix *A){
  int ret;

  free(A->values);
  free(A);
  /* if (A->values == NULL){ */
  /*     free(A); */
  /*     if (A == NULL) */
  /* 	ret = 0; */
  /*     else */
  /* 	ret = 1; */
  /* } else { */
  /*   ret = 1; */
  /* } */
  
  return ret;
}

void im_print(t_imatrix *M){
  for (int i=0; i<M->rows; ++i){
    printf(" [ ");
    for (int j=0; j<M->columns; ++j){
      printf("%d ", *(M->values+i*(M->columns)+j));
    }
    printf("]\n");
  }
  printf("\n");
}
