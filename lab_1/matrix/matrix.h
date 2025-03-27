#include <stdlib.h>
#include "../numbers/item.h"
#include "../numbers/real/real.h"
#include "../numbers/complex/complex.h"

#ifndef matrix_h
#define matrix_h

typedef struct matrix {
    const struct matrixInfo *infoMatrix;
    const struct itemInfo *infoItem;
    int rows;
    int columns;
    void (*printMatrix)();
    item **data;
} matrix;

typedef struct matrixInfo {
	size_t size;
	item **(*getData)(matrix *A);
    void (*freeMatrix)(matrix *A);
	matrix *(*sum)(matrix *A, matrix *B);
	matrix *(*mult)(matrix *A, matrix *B);
	matrix *(*transpose)(matrix *A);
    int (*equal)(matrix *A, matrix *B);
} matrixInfo;

extern const matrixInfo information;
matrix *createMatrix(int m, int n, item **data);

#endif
