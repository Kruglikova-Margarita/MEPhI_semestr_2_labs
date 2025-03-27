#include <stdio.h>
#include "../../errorTypes/errors.h"
#include "../../numbers/item.h"
#include "../../numbers/real/real.h"
#include "../../numbers/complex/complex.h"
#include "../../matrix/matrix.h"

int chooseAction() {
    int a = 0;
    int check = 0;
    printf("Choose action: ");
    while ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9)) {
        check = scanf("%d", &a);
        if (check == EOF) {
            setError(errorList.eof); //EOF
            return 0;
        }
        if ((a != 1) && (a != 2) && (a != 3) && (a != 4) && (a != 5) && (a != 6) && (a != 7) && (a != 8) && (a != 9)) {
            scanf("%*[^\n]");
            printf("Invalid action! Try again: ");
        }
    }

    return a;
}

int chooseType() {
    printf("Possible types of numbers:\n");
    printf("1 - real\n");
    printf("2 - complex\n");
    int type = 0;
    int check = 0;
    while (!((check == 1) && ((type == 1) || (type == 2)))) {
        printf("Choose type of numbers: ");
        check = scanf("%d", &type);
        if (check == EOF) {
            setError(errorList.eof); //EOF
            return 0;
        }
        if (!((check == 1) && ((type == 1) || (type == 2)))) {
            scanf("%*[^\n]");
            printf("Invalid type! Try again\n");
        }
    }

    return type;
}

item *inputReal() {
    float data = 0;
    int check = 0;
    while(check != 1) {
        check = scanf("%f", &data);
        if (check == EOF) {
            setError(errorList.eof); //EOF
            return NULL;
        }
        if (check != 1) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        } else break;
    }
    item *num = createReal(data);

    return num;
}

item *inputComplex() {
    float Re = 0;
    float Im = 0;
    while(1) {
        printf("Re = ");
        int check = scanf("%f", &Re);
        if (check == EOF) {
            setError(errorList.eof); //EOF
            return NULL;
        }
        if (check != 1) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        } else break;
    }
    if (exitLabel.code == 8) return NULL;
    while(1) {
        printf("Im = ");
        int check = scanf("%f", &Im);
        if (check == EOF) {
            setError(errorList.eof); //EOF
            return NULL;
        }
        if (check != 1) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        } else break;
    }
    if (exitLabel.code == 8) return NULL;
    item *num = createComplex(Re, Im);

    return num;
}

int inputNatural() {
    int n = 0;
    int check = 0;
    while ((check != 1) || (n <= 0)) {
        check = scanf("%d", &n);
        if (check == EOF) {
            setError(errorList.eof); //EOF
            return 0;
        }
        if ((check != 1) || (n <= 0)) {
            scanf("%*[^\n]");
            printf("Invalid value! Try again: ");
        }
    }

    return n;
}

matrix *inputMatrix(int type) {
    printf("Input number of rows in matrices: ");
    int m = inputNatural();
    if (exitLabel.code != 0) {
        printf("Error: %s\n", exitLabel.message);
        return NULL;
    }
    printf("Input number of columns in matrices: ");
    int n = inputNatural();
    if (exitLabel.code != 0) {
        printf("Error: %s\n", exitLabel.message);
        return NULL;
    }
    item **data = malloc(m * n * sizeof(item *));
    if (data == NULL) {
        setError(errorList.eof); //EOF
        return NULL;
    }
    item *(*inputNumber)();
    switch(type) {
        case(1):
            inputNumber = &inputReal;
            break;
        case(2):
            inputNumber = &inputComplex;
            break;
    }
    for (int i = 0; i < (m * n); i++) {
        printf("Element in the %d row of the %d column:\n", (i / n) + 1, (i % n) + 1);
        data[i] = inputNumber();
        if (exitLabel.code != 0) {
            for (int j = 0; j < i; j++) {
                data[j]->info->freeItem(data[j]);
            }
            free(data);
            return NULL;
        }
    }
    matrix *A = createMatrix(m, n, data);
    for (int i = 0; i < (m * n); i++) {
        data[i]->info->freeItem(data[i]);
    }
    free(data);

    return A;
}