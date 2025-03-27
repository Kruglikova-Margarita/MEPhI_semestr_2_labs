#include <stdio.h>
#include <stdlib.h>
#include "../../numbers/item.h"
#include "../../numbers/real/real.h"
#include "../../numbers/complex/complex.h"
#include "../../errorTypes/errors.h"
#include "../../matrix/matrix.h"
#include "testReal.h"

void testReal() {
    int error = 0;
    printf("\n==Testing functions of real numbers==\n\n");
    testRealZero(&error);
    testRealOne(&error);
    testRealSum(&error);
    testRealMult(&error);
    testRealReverseSum(&error);
    testRealReverseMult(&error);
    testRealDifference(&error);
    testRealDivision(&error);
    testRealCopy(&error);
    testRealCompare(&error);
    testRealEqual(&error);

    if (error == 0) printf("\nAll tests of functions of real numbers were successfully passed\n");
    else printf("\nError! Not all tests of functions of real numbers were successfulle passed\n");
}

void testRealZero(int *error) {
    item *real = realInfo.zero();
    item *zero = createReal(0);
    int check = realInfo.equal(real, zero);
    if (check == 1) printf("The test of the function of creating a real zero (zeroReal) has been successfully passed\n");
    else {
        printf("The test of the function of creating a real zero (zeroReal) has been failed\n");
        (*error) = 1;
    }
    real->info->freeItem(real);
    zero->info->freeItem(zero);
}

void testRealOne(int *error) {
    item *real = realInfo.one();
    item *one = createReal(1);
    int check = realInfo.equal(real, one);
    if (check == 1) printf("The test of the function of creating a real one (oneReal) has been successfully passed\n");
    else {
        printf("The test of the function of creating a real one (oneReal) has been failed\n");
        (*error) = 1;
    }
    real->info->freeItem(real);
    one->info->freeItem(one);
}

void testRealSum(int *error) {
    item *real1 = createReal(3);
    item *real2 = createReal(-7);
    item *correctSum = createReal(-4);
    item *sum1 = real1->info->sum(real1, real2);
    int check = real1->info->equal(correctSum, sum1);

    item *sum2 = real1->info->sum(real1, NULL);

    if ((check == 1) && (sum2 == NULL)) printf("The test of the function of summation of two real numbers (sumReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of summation of two real numbers (sumReal) has been failed\n");
    }

    real1->info->freeItem(real1);
    real2->info->freeItem(real2);
    correctSum->info->freeItem(correctSum);
    sum1->info->freeItem(sum1);
}

void testRealMult(int *error) {
    item *real1 = createReal(3);
    item *real2 = createReal(-7);
    item *correctMult = createReal(-21);
    item *mult1 = real1->info->mult(real1, real2);
    int check = real1->info->equal(correctMult, mult1);

    item *mult2 = real1->info->mult(real1, NULL);

    if ((check == 1) && (mult2 == NULL)) printf("The test of the function of multiplication of two real numbers (multReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of multiplication of two real numbers (multReal) has been failed\n");
    }

    real1->info->freeItem(real1);
    real2->info->freeItem(real2);
    correctMult->info->freeItem(correctMult);
    mult1->info->freeItem(mult1);
}

void testRealReverseSum(int *error) {
    item *real = createReal(4);
    item *correctRev = createReal(-4);
    item *rev1 = real->info->reverseSum(real);
    int check = real->info->equal(correctRev, rev1);

    item *rev2 = real->info->reverseSum(NULL);

    if ((check == 1) && (rev2 == NULL)) printf("The test of the function of finding the inverse real number relative zero (reverseSumReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the inverse real number relative zero (reverseSumReal) has been failed\n");
    }

    real->info->freeItem(real);
    correctRev->info->freeItem(correctRev);
    rev1->info->freeItem(rev1);
}

void testRealReverseMult(int *error) {
    item *real = createReal(4);
    item *correctRev = createReal(0.25);
    item *rev1 = real->info->reverseMult(real);
    int check = real->info->equal(correctRev, rev1);

    item *rev2 = real->info->reverseMult(NULL);

    if ((check == 1) && (rev2 == NULL)) printf("The test of the function of finding the inverse real number relative one (reverseMultReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the inverse real number relative one (reverseMultReal) has been failed\n");
    }

    real->info->freeItem(real);
    correctRev->info->freeItem(correctRev);
    rev1->info->freeItem(rev1);
}

void testRealDifference(int *error) {
    item *real1 = createReal(3);
    item *real2 = createReal(-7);
    item *correctDif = createReal(10);
    item *dif1 = real1->info->difference(real1, real2);
    int check = real1->info->equal(correctDif, dif1);

    item *dif2 = real1->info->difference(real1, NULL);

    if ((check == 1) && (dif2 == NULL)) printf("The test of the function of finding the difference between two real numbers (differenceReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the difference between two real numbers (differenceReal) has been failed\n");
    }

    real1->info->freeItem(real1);
    real2->info->freeItem(real2);
    correctDif->info->freeItem(correctDif);
    dif1->info->freeItem(dif1);
}

void testRealDivision(int *error) {
    item *real1 = createReal(2);
    item *real2 = createReal(-4);
    item *correctDiv = createReal(-0.5);
    item *div1 = real1->info->division(real1, real2);
    int check = real1->info->equal(correctDiv, div1);

    item *div2 = real1->info->division(real1, NULL);

    if ((check == 1) && (div2 == NULL)) printf("The test of the function of finding the quotient of two real numbers (divisionReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the quotient of two real numbers (divisionReal) has been failed\n");
    }

    real1->info->freeItem(real1);
    real2->info->freeItem(real2);
    correctDiv->info->freeItem(correctDiv);
    div1->info->freeItem(div1);
}

void testRealCopy(int *error) {
    item *real = createReal(-10);
    item *copy1 = real->info->copy(real);
    int check = real->info->equal(real, copy1);

    item *copy2 = real->info->copy(NULL);

    if ((check == 1) && (copy2 == NULL)) printf("The test of the function of copying a real number (copyReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of copying a real number (copyReal) has been failed\n");
    }

    real->info->freeItem(real);
    copy1->info->freeItem(copy1);
}

void testRealCompare(int *error) {
    item *real1 = createReal(2);
    item *real2 = createReal(-4);
    int check1 = real1->info->compare(real1, real2);
    int check2 = real1->info->compare(real2, real1);
    int check3 = real1->info->compare(real1, real1);
    int check4 = real1->info->compare(real1, NULL);

    if ((check1 == 1) && (check2 == -1) && (check3 == 0) && (check4 == 0)) printf("The test of the function of comparing two real numbers (compareReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of comparing two real numbers (compareReal) has been failed\n");
    }

    real1->info->freeItem(real1);
    real2->info->freeItem(real2);
}

void testRealEqual(int *error) {
    item *real1 = createReal(2);
    item *real2 = createReal(-4);
    int check1 = real1->info->equal(real1, real2);
    int check2 = real1->info->equal(real1, real1);
    int check3 = real1->info->equal(real1, NULL);

    if ((check1 == 0) && (check2 == 1) && (check3 == 0)) printf("The test of the function of checking the equality of two real numbers (equalReal) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of checking the equality of two real numbers (equalReal) has been failed\n");
    }

    real1->info->freeItem(real1);
    real2->info->freeItem(real2);
}