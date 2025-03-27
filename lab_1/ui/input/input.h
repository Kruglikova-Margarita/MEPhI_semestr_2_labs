#include "../../matrix/matrix.h"

#ifndef input_h
#define input_h

int chooseAction();
int chooseType();
item *inputReal();
item *inputComplex();
int inputNatural();
matrix *inputMatrix(int type);

#endif