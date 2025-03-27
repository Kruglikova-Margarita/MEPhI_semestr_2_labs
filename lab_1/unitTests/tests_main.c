#include <stdio.h>
#include <stdlib.h>
#include "../numbers/item.h"
#include "../numbers/real/real.h"
#include "../numbers/complex/complex.h"
#include "../errorTypes/errors.h"
#include "../matrix/matrix.h"
#include "testReal/testReal.h"
#include "testComplex/testComplex.h"
#include "testMatrix/testMatrix.h"

int main() {
    testReal();
    testComplex();
    testMatrix();

    return 0;
}