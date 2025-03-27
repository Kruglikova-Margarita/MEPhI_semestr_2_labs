#include <stdio.h>
#include <stdlib.h>
#include "../../numbers/item.h"
#include "../input/input.h"
#include "../../errorTypes/errors.h"
#include "../../numbers/real/real.h"
#include "../../numbers/complex/complex.h"
#include "../../matrix/matrix.h"

void action1() {
    int type = chooseType();
    item *num1 = NULL;
    item *num2 = NULL;
    item *sum = NULL;
    if (exitLabel.code == 0) {
        switch(type) {
            case(1):
                printf("Input first real number: ");
                num1 = inputReal();
                if (exitLabel.code == 0) {
                    printf("Input second real number: ");
                    num2 = inputReal();
                }
                break;
            case(2):
                printf("Input first complex number:\n");
                num1 = inputComplex();
                if (exitLabel.code == 0) {
                    printf("Input second complex number:\n");
                    num2 = inputComplex();
                }
                break;
        }
        if (exitLabel.message != NULL) {
            printf("Error: %s\n", exitLabel.message);
        } else {
            sum = num1->info->sum(num1, num2);
            printf("Sum of two numbers: ");
            sum->printItem(sum);
            printf("\n");
        }
    }
    if (num1 != NULL) num1->info->freeItem(num1);
    if (num2 != NULL) num2->info->freeItem(num2);
    if (sum != NULL) sum->info->freeItem(sum);
}

void action2() {
    int type = chooseType();
    item *num1 = NULL;
    item *num2 = NULL;
    item *mult = NULL;
    switch(type) {
        case(1):
            printf("Input first real number: ");
            num1 = inputReal();
            if (exitLabel.code == 0) {
                printf("Input second real number: ");
                num2 = inputReal();
            }
            break;
        case(2):
            printf("Input first complex number:\n");
            num1 = inputComplex();
            if (exitLabel.code == 0) {
                printf("Input second complex number:\n");
                num2 = inputComplex();
            }
            break;
    }
    if (exitLabel.message != NULL) {
        printf("Error: %s\n", exitLabel.message);
    } else {
        mult = num1->info->mult(num1, num2);
        printf("Product of two numbers: ");
        mult->printItem(mult);
        printf("\n");
    }
    if (num1 != NULL) num1->info->freeItem(num1);
    if (num2 != NULL) num2->info->freeItem(num2);
    if (mult != NULL) mult->info->freeItem(mult);
}

void action3() {
    int type = chooseType();
    item *num1 = NULL;
    item *num2 = NULL;
    item *dif = NULL;
    switch(type) {
        case(1):
            printf("Input first real number: ");
            num1 = inputReal();
            if (exitLabel.code == 0) {
                printf("Input second real number: ");
                num2 = inputReal();
            }
            break;
        case(2):
            printf("Input first complex number:\n");
            num1 = inputComplex();
            if (exitLabel.code == 0) {
                printf("Input second complex number:\n");
                num2 = inputComplex();
            }
            break;
    }
    if (exitLabel.message != NULL) {
        printf("Error: %s\n", exitLabel.message);
    } else {
        dif = num1->info->difference(num1, num2);
        printf("Difference between two numbers: ");
        dif->printItem(dif);
        printf("\n");
    }
    if (num1 != NULL) num1->info->freeItem(num1);
    if (num2 != NULL) num2->info->freeItem(num2);
    if (dif != NULL) dif->info->freeItem(dif);
}

void action4() {
    int type = chooseType();
    item *num1 = NULL;
    item *num2 = NULL;
    item *q = NULL;
    switch(type) {
        case(1):
            printf("Input first real number: ");
            num1 = inputReal();
            if (exitLabel.code == 0) {
                printf("Input second real number: ");
                num2 = inputReal();
            }
            break;
        case(2):
            printf("Input first complex number:\n");
            num1 = inputComplex();
            if (exitLabel.code == 0) {
                printf("Input second complex number:\n");
                num2 = inputComplex();
            }
            break;
    }
    if (exitLabel.message != NULL) {
        printf("Error: %s\n", exitLabel.message);
    } else {
        q = num1->info->division(num1, num2);
        printf("Quotient between two numbers: ");
        q->printItem(q);
        printf("\n");
    }
    if (num1 != NULL) num1->info->freeItem(num1);
    if (num2 != NULL) num2->info->freeItem(num2);
    if (q != NULL) q->info->freeItem(q);
}

void action5() {
    int type = chooseType();
    item *num1 = NULL;
    item *num2 = NULL;
    switch(type) {
        case(1):
            printf("Input first real number: ");
            num1 = inputReal();
            if (exitLabel.code == 0) {
                printf("Input second real number: ");
                num2 = inputReal();
            }
            if (exitLabel.message != NULL) {
                printf("Error: %s\n", exitLabel.message);
            } else {
                int cmp = num1->info->compare(num1, num2);
                if (cmp == -1) {
                    num1->printItem(num1);
                    printf(" is less than ");
                    num2->printItem(num2);
                    printf("\n");
                } else  if (cmp == 0) {
                    num1->printItem(num1);
                    printf(" is equal to ");
                    num2->printItem(num2);
                    printf("\n");
                } else {
                    num1->printItem(num1);
                    printf(" is greater than ");
                    num2->printItem(num2);
                    printf("\n");
                }
            }
            if (num1 != NULL) num1->info->freeItem(num1);
            if (num2 != NULL) num2->info->freeItem(num2);
            break;
        case(2):
            printf("Impossible to compare complex numbers\n");
            break;
    }
}

void action6() {
    int type = chooseType();
    printf("Attention! Matrices must be the same size\n");
    matrix *A1 = NULL;
    matrix *A2 = NULL;
    matrix *sum = NULL;
    if (exitLabel.code == 0) {
        printf("Input first matrix:\n");
        A1 = inputMatrix(type);
        if (exitLabel.code == 0) {
            printf("First matrix:\n");
            A1->printMatrix(A1);
            printf("Input second matrix:\n");
            A2 = inputMatrix(type);
            if (exitLabel.code == 0) {
                printf("Second matrix:\n");
                A2->printMatrix(A2);
                sum = A1->infoMatrix->sum(A1, A2);
                if (exitLabel.code == 0) {
                    printf("Sum of two matrices:\n");
                    sum->printMatrix(sum);
                }
            }
        }
    }
    if (A1 != NULL) A1->infoMatrix->freeMatrix(A1);
    if (A2 != NULL) A2->infoMatrix->freeMatrix(A2);
    if (sum != NULL) sum->infoMatrix->freeMatrix(sum);
}

void action7() {
    int type = chooseType();
    printf("Attention! The number of columns of the first matrix must be equal to the number of rows of the second matrix\n");
    matrix *A1 = NULL;
    matrix *A2 = NULL;
    matrix *mult = NULL;
    if (exitLabel.code == 0) {
        printf("Input first matrix:\n");
        A1 = inputMatrix(type);
        if (exitLabel.code == 0) {
            printf("First matrix:\n");
            A1->printMatrix(A1);
            printf("Input second matrix:\n");
            A2 = inputMatrix(type);
            if (exitLabel.code == 0) {
                printf("Second matrix:\n");
                A2->printMatrix(A2);
                mult = A1->infoMatrix->mult(A1, A2);
                if (exitLabel.code == 0) {
                    printf("Product of two matrices:\n");
                    mult->printMatrix(mult);
                }
            }
        }
    }
    if (A1 != NULL) A1->infoMatrix->freeMatrix(A1);
    if (A2 != NULL) A2->infoMatrix->freeMatrix(A2);
    if (mult != NULL) mult->infoMatrix->freeMatrix(mult);
}

void action8() {
    int type = chooseType();
    matrix *A = NULL;
    matrix *transpose = NULL;
    if (exitLabel.code == 0) {
        printf("Input matrix:\n");
        A = inputMatrix(type);
        if (exitLabel.code == 0) {
            printf("Matrix:\n");
            A->printMatrix(A);
            transpose = A->infoMatrix->transpose(A);
            if (exitLabel.code == 0) {
                printf("Transposed matrix:\n");
                transpose->printMatrix(transpose);
            }
        }
    }
    if (A != NULL) A->infoMatrix->freeMatrix(A);
    if (transpose != NULL) transpose->infoMatrix->freeMatrix(transpose);
}