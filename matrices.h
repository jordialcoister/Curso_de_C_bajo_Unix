/* typedef enum t_matrixops{ addition, substraction }; */
#define ERR_PROD_1 "La mida de les columnes d'A no es correspon amb la de les files de B\n"

typedef struct
{
  int rows;
  int columns;
  int *values;
} t_imatrix;

typedef struct
{
  float rows;
  float columns;
  float *values;
} t_fmatrix;

/* im_create creates a zero matrix of the size specified */
t_imatrix *im_create(int rows, int cols);

t_imatrix *im_identity_create(int rows, int cols);

int im_insert(t_imatrix *A, int value, int x, int y);

/* Basic row operations */
/* type 1, interchange two rows*/
int im_row_x(t_imatrix *A, int row1, int row2);
/* type 2, multiply a row by a nonzero constant */
int im_row_multiply(t_imatrix *A, int row1, int m);
/* type 3 add a multiple of a row to another row  */
int im_row_add_another_multi(t_imatrix *A, int row1, int m, int row2);

/* t_imatrix *im_operate(t_imatrix *A, t_imatrix *B, t_matrixops op); */
    
t_imatrix *im_add(t_imatrix *A, t_imatrix *B);

t_imatrix *im_sub(t_imatrix *A, t_imatrix *B);

t_imatrix *im_mult(t_imatrix *A, t_imatrix *B);

void im_scalarprod(t_imatrix *A, int m);

t_imatrix *im_trans(t_imatrix *A);

/* not implemented yet */
t_imatrix *im_inverse(t_imatrix *A);

int im_destroy(t_imatrix *A);

void im_print(t_imatrix *A);
