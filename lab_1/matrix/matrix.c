#include <stdio.h>
#include <stdlib.h>
#include "../numbers/item.h"
#include "../numbers/real/real.h"
#include "../numbers/complex/complex.h"
#include "../errorTypes/errors.h"
#include "../matrix/matrix.h"

void printMatrix(matrix *A);
item **getData(matrix *A);
void freeMatrix(matrix *A);
matrix *sumMatrix(matrix *A, matrix *B);
matrix *multMatrix(matrix *A, matrix *B);
matrix *transposeMatrix(matrix *A);
int equalMatrix(matrix *A, matrix *B);

const matrixInfo information = {
	sizeof(matrix),
	getData,
	freeMatrix,
	sumMatrix,
	multMatrix,
	transposeMatrix,
	equalMatrix
};

matrix *createMatrix(int m, int n, item **data) {
	if (data == NULL) {
		setError(errorList.nullPointer);
		return NULL;
	}
	matrix *A = malloc(sizeof(matrix));
	if (A == NULL) {
		setError(errorList.allocation);
		return NULL;
	}
	A->infoMatrix = &information;
	A->infoItem = (*data)->info;
	A->printMatrix = &printMatrix;
	A->rows = m;
	A->columns = n;
	A->data = malloc(m * n * sizeof(item *));
	if (A->data == NULL) {
		setError(errorList.allocation);
		return NULL;
	}
	for (int i = 0; i < (m * n); i++) {
		if (data[i] == NULL) {
			setError(errorList.nullPointer);
			for (int j = 0; j < i; j++) {
				A->infoItem->freeItem((A->data)[j]);
			}
			free(A->data);
			free(A);
			return NULL;
		}
		if (data[i]->info != data[0]->info) {
			setError(errorList.differentTypesInMatrix);
			for (int j = 0; j < i; j++) {
				A->infoItem->freeItem((A->data)[j]);
			}
			free(A->data);
			free(A);
			return NULL;
		}
		(A->data)[i] = A->infoItem->copy(data[i]);
	}

	return A;
}

void printMatrix(matrix *A) {
	if (A == NULL) {
		setError(errorList.nullPointer);
		printf("Impossible to print matrix");
	} else {
		int m = A->rows;
		int n = A->columns;
		for (int i = 0; i < (m * n); i++) {
			(A->data)[i]->printItem((A->data)[i]);
			printf("  ");
			if (((i + 1) % n) == 0) printf("\n");
		}
	}
}

item **getData(matrix *A) {
	if (A == NULL) {
		setError(errorList.nullPointer);
		return NULL;
	}
	return A->data;
}

void freeMatrix(matrix *A) {
	if (A != NULL) {
		int m = A->rows;
		int n = A->columns;
		for (int i = 0; i < (m * n); i++) {
			A->infoItem->freeItem((A->data)[i]);
		}
		free(A->data);
		free(A);
	}
}

matrix *sumMatrix(matrix *A, matrix *B) {
	if ((A == NULL) || (B == NULL)) {
		setError(errorList.nullPointer);
		return NULL;
	}
	if (A->infoItem != B->infoItem) {
		setError(errorList.matricesContainDifferentTypes);
		return NULL;
	}
	int Am = A->rows;
	int An = A->columns;
	int Bm = B->rows;
	int Bn = B->columns;
	if ((Am != Bm) || (An != Bn)) {
		setError(errorList.invalidMatrixSize);
		return NULL;
	}
	item **dataSum = malloc(Am * An * sizeof(item *));
	if (dataSum == NULL) {
		setError(errorList.allocation);
		return NULL;
	}
	for (int i = 0; i < (Am * An); i++) {
		dataSum[i] = A->infoItem->sum((A->data)[i], (B->data)[i]);
	}
	matrix *sum = createMatrix(Am, An, dataSum);
	for (int i = 0; i < (Am * An); i++) {
		A->infoItem->freeItem(dataSum[i]);
	}
	free(dataSum);
	
	return sum;
}

matrix *multMatrix(matrix *A, matrix *B) {
	if ((A == NULL) || (B == NULL)) {
		setError(errorList.nullPointer);
		return NULL;
	}
	if (A->infoItem != B->infoItem) {
		setError(errorList.matricesContainDifferentTypes);
		return NULL;
	}
	int Am = A->rows;
	int An = A->columns;
	int Bm = B->rows;
	int Bn = B->columns;
	if (An != Bm) {
		setError(errorList.invalidMatrixSize);
		return NULL;
	}
	item **dataMult = malloc(Am * Bn * sizeof(item *));
	if (dataMult == NULL) {
		setError(errorList.allocation);
		return NULL;
	}
	for (int i = 0; i < Am; i++) {
		for (int j = 0; j < Bn; j++) {
			item *summ = A->infoItem->zero();
			for (int k = 0; k < An; k++) {
				item *add1 = A->infoItem->copy(summ);
				A->infoItem->freeItem(summ);
				item *add2 = A->infoItem->mult((A->data)[i * An + k], (B->data)[k * Bn + j]);
				summ = A->infoItem->sum(add1, add2);
				A->infoItem->freeItem(add1);
				A->infoItem->freeItem(add2);
			}
			dataMult[i * Bn + j] = A->infoItem->copy(summ);
			A->infoItem->freeItem(summ);
		}
	}
	matrix *mult = createMatrix(Am, Bn, dataMult);
	for (int i = 0; i < (Am * Bn); i++) {
		A->infoItem->freeItem(dataMult[i]);
	}
	free(dataMult);

	return mult;
}

matrix *transposeMatrix(matrix *A) {
	if (A == NULL) {
		setError(errorList.nullPointer);
		return NULL;
	}
	int m = A->rows;
	int n = A->columns;
	item **dataTranspose = malloc(m * n * sizeof(item *));
	if (dataTranspose == NULL) {
		setError(errorList.allocation);
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dataTranspose[i * m + j] = A->infoItem->copy((A->data)[j * n + i]);
		}
	}
	matrix *transpose = createMatrix(n, m, dataTranspose);
	for (int i = 0; i < (m * n); i++) {
		A->infoItem->freeItem(dataTranspose[i]);
	}
	free(dataTranspose);
	
	return transpose;
}

int equalMatrix(matrix *A, matrix *B) {
	if ((A == NULL) || (B == NULL)) {
		setError(errorList.nullPointer);
		return 0;
	}
	if (A->infoItem != B->infoItem) return 0;
	int Am = A->rows;
	int An = A->columns;
	int Bm = B->rows;
	int Bn = B->columns;
	if ((Am != Bm) || (An != Bn)) return 0;
	for (int i = 0; i < (Am * An); i++) {
		int check = A->infoItem->equal((A->data)[i], (B->data)[i]);
		if (check == 0) return 0;
	}

	return 1;
}
