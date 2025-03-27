#include <stdio.h>
#include <stdlib.h>
#include "../item.h"
#include "../../errorTypes/errors.h"

void *getDataComplex(item *comp);
void printComplex(item *comp);
void freeComplex(item *comp);
item *zeroComplex();
item *oneComplex();
item *sumComplex(item *comp1, item *comp2);
item *multComplex(item *comp1, item *comp2);
item *reverseSumComplex(item *comp);
item *reverseMultComplex(item *comp);
item *differenceComplex(item *comp1, item *comp2);
item *divisionComplex(item *comp1, item *comp2);
item *copyComplex(item *comp);
int compareComplex(item *comp1, item *comp2);
int equalComplex(item *comp1, item *comp2);

const itemInfo complexInfo = {
    sizeof(item),
    getDataComplex,
    freeComplex,
    zeroComplex,
    oneComplex,
    sumComplex,
    multComplex,
    reverseSumComplex,
    reverseMultComplex,
    differenceComplex,
    divisionComplex,
    copyComplex,
    compareComplex,
    equalComplex
};

item *createComplex(float re, float im) {
    item *comp = malloc(sizeof(item));
    if (comp == NULL) {
        setError(errorList.allocation); //memory allocation error
        return NULL;
    }
    comp->info = &complexInfo;
    comp->printItem = printComplex;
    comp->data = malloc(2 * sizeof(float));
    if (comp->data == NULL) {
        setError(errorList.allocation); //memory allocation error
        free(comp);
        return NULL;
    }
    ((float *)(comp->data))[0] = re;
    ((float *)(comp->data))[1] = im;

    return comp;
}

void *getDataComplex(item *comp) {
    if (comp == NULL) {
        setError(errorList.nullPointer); //using a null pointer
        return NULL;
    }
    float *data = malloc(2 * sizeof(float));
    if (data == NULL) {
        setError(errorList.allocation); //memory allocation error
        return NULL;
    }
    data[0] = ((float *)(comp->data))[0];
    data[1] = ((float *)(comp->data))[1];

    return data;
}

void printComplex(item *comp) {
    if (comp == NULL) {
        setError(errorList.nullPointer); //using a null pointer
        printf("Impossible to print item");
    } else {
        printf("%f + %f * i", ((float *)(comp->data))[0], ((float *)(comp->data))[1]);
    }
}

void freeComplex(item *comp) {
    if (comp != NULL) {
    	free(comp->data);
        free(comp);
    }
}

item *zeroComplex() {
	item *comp = createComplex(0, 0);

    return comp;
}

item *oneComplex() {
	item *comp = createComplex(1, 0);

    return comp;
}

item *sumComplex(item *comp1, item *comp2) {
    if ((comp1 == NULL) || (comp2 == NULL)) {
        setError(errorList.nullPointer); //using a null pointer
        return NULL;
    }
    float Re = ((float *)(comp1->data))[0] + ((float *)(comp2->data))[0];
    float Im = ((float *)(comp1->data))[1] + ((float *)(comp2->data))[1];
    item *comp = createComplex(Re, Im);

    return comp;
}

item *multComplex(item *comp1, item *comp2) {
    if ((comp1 == NULL) || (comp2 == NULL)) {
        setError(errorList.nullPointer); //using a null pointer
        return NULL;
    }
    float Re1 = ((float *)(comp1->data))[0];
    float Im1 = ((float *)(comp1->data))[1];
    float Re2 = ((float *)(comp2->data))[0];
    float Im2 = ((float *)(comp2->data))[1];
    float Re = Re1 * Re2 - Im1 * Im2;
    float Im = Re1 * Im2 + Re2 * Im1;
    item *comp = createComplex(Re, Im);

    return comp;
}

item *reverseSumComplex(item *comp) {
    if (comp == NULL) {
        setError(errorList.nullPointer); //using a null pointer
        return NULL;
    }
    item *rev = createComplex((-1) * ((float *)(comp->data))[0], (-1) * ((float *)(comp->data))[1]);

    return rev;
}

item *reverseMultComplex(item *comp) {
    if (comp == NULL) {
        setError(errorList.nullPointer); //using a null pointer
        return NULL;
    }
    if ((((float *)(comp->data))[0] == 0) && (((float *)(comp->data))[1] == 0)) {
        setError(errorList.invalidItem); //impossible to do action with this item
        return NULL;
    }
    float Re = ((float *)(comp->data))[0];
    float Im = ((float *)(comp->data))[1];
    item *rev = createComplex(Re / (Re * Re + Im * Im), (-1) * Im / (Re * Re + Im * Im));

    return rev;
}

item *differenceComplex(item *comp1, item *comp2) {
    item *rev = reverseSumComplex(comp2);
    if (rev == NULL) return NULL;
    item *dif = sumComplex(comp1, rev);
    freeComplex(rev);

    return dif;
}

item *divisionComplex(item *comp1, item *comp2) {
    item *rev = reverseMultComplex(comp2);
    if (rev == NULL) return NULL;
    item *div = multComplex(comp1, rev);
    freeComplex(rev);

    return div;
}

item *copyComplex(item *comp) {
    if ((comp == NULL) || (comp->data == NULL)) {
        setError(errorList.nullPointer); //using a null pointer
        return NULL;
    }
    item *copy = createComplex(((float *)(comp->data))[0], ((float *)(comp->data))[1]);

    return copy;
}

int compareComplex(item *comp1, item *comp2) {
    setError(errorList.invalidType); //impossible to do action with this type of item
    return 0;
}

int equalComplex(item *comp1, item *comp2) {
    if ((comp1 == NULL) || (comp1->data == NULL) || (comp2 == NULL) || (comp2->data == NULL)) {
        setError(errorList.nullPointer); //using a null pointer
        return 0;
    }
    float Re1 = ((float *)(comp1->data))[0];
    float Im1 = ((float *)(comp1->data))[1];
    float Re2 = ((float *)(comp2->data))[0];
    float Im2 = ((float *)(comp2->data))[1];
    if ((Re1 == Re2) && (Im1 == Im2)) return 1;
    else return 0;
}
