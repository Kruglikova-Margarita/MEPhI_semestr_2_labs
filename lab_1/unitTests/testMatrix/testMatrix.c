#include <stdio.h>
#include <stdlib.h>
#include "../../numbers/item.h"
#include "../../numbers/real/real.h"
#include "../../numbers/complex/complex.h"
#include "../../errorTypes/errors.h"
#include "../../matrix/matrix.h"
#include "testMatrix.h"

void testMatrix() {
    int error = 0;
    printf("\n==Testing functions of real numbers==\n\n");
    testMatrixSum(&error);
    testMatrixMult(&error);
    testMatrixTranspose(&error);
    testMatrixEqual(&error);

    if (error == 0) printf("\nAll tests of functions of matrices were successfully passed\n");
    else printf("\nError! Not all tests of functions of matrices were successfulle passed\n");
}

void testMatrixSum(int *error) {
    item **data1 = malloc(6 * sizeof(item *));
    item **data2 = malloc(6 * sizeof(item *));
    item **data3 = malloc(6 * sizeof(item *));
    item **dataCorrectSum = malloc(6 * sizeof(item *));
    for (int i = 0; i < 6; i++) {
        data1[i] = createReal(i);
        data2[i] = createReal(3 * i - 2);
        data3[i] = createComplex(-i, 2 * i + 1);
        dataCorrectSum[i] = createReal(4 * i - 2);
    }
    matrix *A1 = createMatrix(2, 3, data1);
    matrix *A2 = createMatrix(2, 3, data2);
    matrix *A3 = createMatrix(3, 2, data2);
    matrix *A4 = createMatrix(2, 3, data3);
    matrix *correctSum = createMatrix(2, 3, dataCorrectSum);
    matrix *sum1 = A1->infoMatrix->sum(A1, A2);
    matrix *sum2 = A1->infoMatrix->sum(A1, NULL);
    matrix *sum3 = A1->infoMatrix->sum(A1, A4);
    matrix *sum4 = A1->infoMatrix->sum(A1, A3);

    int check = A1->infoMatrix->equal(correctSum, sum1);

    if ((check == 1) && (sum2 == NULL) && (sum3 == NULL) && (sum4 == NULL)) printf("The test of the function of summation of two matrices (sumMatrix) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of summation of two matrices (sumMatrix) has been failed\n");
    }

    for (int i = 0; i < 6; i++) {
        data1[i]->info->freeItem(data1[i]);
        data2[i]->info->freeItem(data2[i]);
        dataCorrectSum[i]->info->freeItem(dataCorrectSum[i]);
        data3[i]->info->freeItem(data3[i]);
    }
    free(data1);
    free(data2);
    free(data3);
    free(dataCorrectSum);
    A1->infoMatrix->freeMatrix(A1);
    A2->infoMatrix->freeMatrix(A2);
    A3->infoMatrix->freeMatrix(A3);
    A4->infoMatrix->freeMatrix(A4);
    correctSum->infoMatrix->freeMatrix(correctSum);
    sum1->infoMatrix->freeMatrix(sum1);
}

void testMatrixMult(int *error) {
    item **data1 = malloc(6 * sizeof(item *));
    item **data2 = malloc(6 * sizeof(item *));
    for (int i = 0; i < 6; i++) {
        data1[i] = createReal(i + 1);
        data2[i] = createComplex(2 * i, i - 3);
    }
    matrix *A1 = createMatrix(2, 3, data1);
    matrix *A2 = createMatrix(3, 2, data1);
    matrix *A3 = createMatrix(3, 2, data2);
    item **dataCorrectMult = malloc(4 * sizeof(item *));
    dataCorrectMult[0] = createReal(22);
    dataCorrectMult[1] = createReal(28);
    dataCorrectMult[2] = createReal(49);
    dataCorrectMult[3] = createReal(64);
    matrix *correctMult = createMatrix(2, 2, dataCorrectMult);
    matrix *mult1 = A1->infoMatrix->mult(A1, A2);
    int check = A1->infoMatrix->equal(correctMult, mult1);
    matrix *mult2 = A1->infoMatrix->mult(A1, NULL);
    matrix *mult3 = A1->infoMatrix->mult(A1, A1);
    matrix *mult4 = A1->infoMatrix->mult(A1, A3);

    if ((check == 1) && (mult2 == NULL) && (mult3 == NULL) && (mult4 == NULL)) printf("The test of the function of multiplication of two matrices (multMatrix) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of multiplication of two matrices (multMatrix) has been failed\n");
    }

    for (int i = 0; i < 6; i++) {
        data1[i]->info->freeItem(data1[i]);
        data2[i]->info->freeItem(data2[i]);
    }
    for (int i = 0;i < 4; i++) {
        dataCorrectMult[i]->info->freeItem(dataCorrectMult[i]);
    }
    free(data1);
    free(data2);
    free(dataCorrectMult);
    A1->infoMatrix->freeMatrix(A1);
    A2->infoMatrix->freeMatrix(A2);
    A3->infoMatrix->freeMatrix(A3);
    correctMult->infoMatrix->freeMatrix(correctMult);
    mult1->infoMatrix->freeMatrix(mult1);
}

void testMatrixTranspose(int *error) {
    item **data = malloc(6 * sizeof(item *));
    item **dataCorrectTranspose = malloc(6 * sizeof(item *));
    for (int i = 0; i < 6; i++) {
        data[i] = createReal(i + 1);
    }
    dataCorrectTranspose[0] = createReal(1);
    dataCorrectTranspose[1] = createReal(4);
    dataCorrectTranspose[2] = createReal(2);
    dataCorrectTranspose[3] = createReal(5);
    dataCorrectTranspose[4] = createReal(3);
    dataCorrectTranspose[5] = createReal(6);
    matrix *A = createMatrix(2, 3, data);
    matrix *correctTranspose = createMatrix(3, 2, dataCorrectTranspose);
    matrix *transpose1 = A->infoMatrix->transpose(A);
    int check = A->infoMatrix->equal(correctTranspose, transpose1);
    matrix *transpose2 = A->infoMatrix->transpose(NULL);

    if ((check == 1) && (transpose2 == NULL)) printf("The test of the function of matrix transposition (transposeMatrix) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of matrix transposition (transposeMatrix) has been failed\n");
    }

    for (int i = 0; i < 6; i++) {
        data[i]->info->freeItem(data[i]);
        dataCorrectTranspose[i]->info->freeItem(dataCorrectTranspose[i]);
    }
    free(data);
    free(dataCorrectTranspose);
    A->infoMatrix->freeMatrix(A);
    correctTranspose->infoMatrix->freeMatrix(correctTranspose);
    transpose1->infoMatrix->freeMatrix(transpose1);
}

void testMatrixEqual(int *error) {
    item **data1 = malloc(6 * sizeof(item *));
    item **data2 = malloc(6 * sizeof(item *));
    item **data3 = malloc(6 * sizeof(item *));
    for (int i = 0; i < 6; i++) {
        data1[i] = createReal(i);
        data2[i] = createComplex(-i, i + 2);
        data3[i] = createReal(3 * i);
    }
    matrix *A1 = createMatrix(2, 3, data1);
    matrix *A2 = createMatrix(2, 3, data2);
    matrix *A3 = createMatrix(2, 3, data3);
    matrix *A4 = createMatrix(3, 2, data3);

    int check1 = A1->infoMatrix->equal(A1, A2); //invalid types of items
    int check2 = A1->infoMatrix->equal(A1, A4); //invalid sizes of matrices
    int check3 = A1->infoMatrix->equal(A1, A3); //invalid values
    int check4 = A1->infoMatrix->equal(A1, A1);
    int check5 = A1->infoMatrix->equal(A1, NULL);

    if ((check1 == 0) && (check2 == 0) && (check3 == 0) && (check4 == 1) && (check5 == 0)) printf("The test of the function of checking the equality of two matrices (equalMatrix) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of checking the equality of two matrices (equalMatrix) has been failed\n");
    }

    for (int i = 0; i < 6; i++) {
        data1[i]->info->freeItem(data1[i]);
        data2[i]->info->freeItem(data2[i]);
        data3[i]->info->freeItem(data3[i]);
    }
    free(data1);
    free(data2);
    free(data3);
    A1->infoMatrix->freeMatrix(A1);
    A2->infoMatrix->freeMatrix(A2);
    A3->infoMatrix->freeMatrix(A3);
    A4->infoMatrix->freeMatrix(A4);
}
