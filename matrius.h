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

t_imatrix *im_create(int rows, int cols);

void im_insert(t_imatrix *A, int value, int x, int y);

t_imatrix *im_add(t_imatrix *A, t_imatrix *B);

int im_destroy(t_imatrix *A);
