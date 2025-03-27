#include <stdio.h>
#include <stdlib.h>
#include "../item.h"
#include "../../errorTypes/errors.h"

void *getDataReal(item *real);
void printReal(item *real);
void freeReal(item *real);
item *zeroReal();
item *oneReal();
item *sumReal(item *real1, item *real2);
item *multReal(item *real1, item *real2);
item *reverseSumReal(item *real);
item *reverseMultReal(item *real);
item *differenceReal(item *real1, item *real2);
item *divisionReal(item *real1, item *real2);
item *copyReal(item *real);
int compareReal(item *real1, item *real2);
int equalReal(item *real1, item *real2);

const itemInfo realInfo = {
    sizeof(item),
    getDataReal,
    freeReal,
    zeroReal,
    oneReal,
    sumReal,
    multReal,
    reverseSumReal,
    reverseMultReal,
    differenceReal,
    divisionReal,
    copyReal,
    compareReal,
    equalReal
};

item *createReal(float data) {
    item *real = malloc(sizeof(item));
    if (real == NULL) {
        setError(errorList.allocation); //memory allocation error
        return NULL;
    }
    real->info = &realInfo;
    real->printItem = printReal;
    real->data = malloc(sizeof(float));
    if (real->data == NULL) {
        setError(errorList.allocation); //memory allocation error
        free(real);
        return NULL;
    }
    *(float *)(real->data) = data;

    return real;
}

void *getDataReal(item *real) {
    if (real == NULL) {
        setError(errorList.nullPointer); //using a null pointer
        return NULL;
    }
    float *data = (float *)(real->data);

    return data;
}

void printReal(item *real) {
    if (real == NULL) {
        setError(errorList.nullPointer); //using a null pointer
        printf("Impossible to print item");    
    } else {
        float *data = (float *)(real->data);
        printf("%f", (*data));
    }
}

void freeReal(item *real) {
    if (real != NULL) {
        free(real->data);
        free(real);
    }
}

item *zeroReal() {
    item *real = createReal(0);

    return real;
}

item *oneReal() {
    item *real = createReal(1);

    return real;
}

item *sumReal(item *real1, item *real2) {
    float *data1 = getDataReal(real1);
    float *data2 = getDataReal(real2);
    if ((data1 == NULL) || (data2 == NULL)) return NULL;
    item *real = createReal((*data1) + (*data2));

    return real;
}

item *multReal(item *real1, item *real2) {
    float *data1 = getDataReal(real1);
    float *data2 = getDataReal(real2);
    if ((data1 == NULL) || (data2 == NULL)) return NULL;
    item *real = createReal((*data1) * (*data2));

    return real;
}

item *reverseSumReal(item *real) {
    float *realData = getDataReal(real);
    if (realData == NULL) return NULL;
    float revData =  (-1) * (*realData);
    item *rev = createReal(revData);

    return rev;
}

item *reverseMultReal(item *real) {
    float *realData = getDataReal(real);
    if (realData == NULL) {
        return NULL;
    }
    if ((*realData) == 0) {
        setError(errorList.invalidItem); //impossible to do action with this item
        return NULL;
    }
    float revData = 1 / (*realData);
    item *rev = createReal(revData);

    return rev;
}

item *differenceReal(item *real1, item *real2) {
    item *rev = reverseSumReal(real2);
    if (rev == NULL) return NULL;
    item *dif = sumReal(real1, rev);
    freeReal(rev);

    return dif;
}

item *divisionReal(item *real1, item *real2) {
    item *rev = reverseMultReal(real2);
    if (rev == NULL) return NULL;
    item *div = multReal(real1, rev);
    freeReal(rev);

    return div;
}

item *copyReal(item *real) {
    if (real == NULL) {
		setError(errorList.nullPointer); //using a null pointer
    	return NULL;
    }
    item *copy = createReal(*(float *)(real->data));

    return copy;
}

int compareReal(item *real1, item *real2) {
    float *data1 = getDataReal(real1);
    float *data2 = getDataReal(real2);
    if ((data1 == NULL) || (data2 == NULL)) return 0;
    if ((*data1) > (*data2)) return 1;
    else if ((*data1) < (*data2)) return -1;
    else return 0;
}

int equalReal(item *real1, item *real2) {
    float *data1 = getDataReal(real1);
    float *data2 = getDataReal(real2);
    if ((data1 == NULL) || (data2 == NULL)) return 0;
    if ((*data1) == (*data2)) return 1;
    else return 0;
}
