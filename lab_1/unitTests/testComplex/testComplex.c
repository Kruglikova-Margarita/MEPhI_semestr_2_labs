#include <stdio.h>
#include <stdlib.h>
#include "../../numbers/item.h"
#include "../../numbers/real/real.h"
#include "../../numbers/complex/complex.h"
#include "../../errorTypes/errors.h"
#include "../../matrix/matrix.h"
#include "testComplex.h"

void testComplex() {
    int error = 0;
    printf("\n==Testing functions of complex numbers==\n\n");
    testComplexZero(&error);
    testComplexOne(&error);
    testComplexSum(&error);
    testComplexMult(&error);
    testComplexReverseSum(&error);
    testComplexReverseMult(&error);
    testComplexDifference(&error);
    testComplexDivision(&error);
    testComplexCopy(&error);
    testComplexCompare(&error);
    testComplexEqual(&error);

    if (error == 0) printf("\nAll tests of functions of complex numbers were successfully passed\n");
    else printf("\nError! Not all tests of functions of complex numbers were successfulle passed\n");
}

void testComplexZero(int *error) {
    item *comp = complexInfo.zero();
    item *zero = createComplex(0, 0);
    int check = complexInfo.equal(comp, zero);
    if (check == 1) printf("The test of the function of creating a complex zero (zeroComplex) has been successfully passed\n");
    else {
        printf("The test of the function of creating a complex zero (zeroComplex) has been failed\n");
        (*error) = 1;
    }
    comp->info->freeItem(comp);
    zero->info->freeItem(zero);
}

void testComplexOne(int *error) {
    item *comp = complexInfo.one();
    item *one = createComplex(1, 0);
    int check = realInfo.equal(comp, one);
    if (check == 1) printf("The test of the function of creating a complex one (oneComplex) has been successfully passed\n");
    else {
        printf("The test of the function of creating a complex one (oneComplex) has been failed\n");
        (*error) = 1;
    }
    comp->info->freeItem(comp);
    one->info->freeItem(one);
}

void testComplexSum(int *error) {
    item *comp1 = createComplex(3, 5);
    item *comp2 = createComplex(-7, 2);
    item *correctSum = createComplex(-4, 7);
    item *sum1 = comp1->info->sum(comp1, comp2);
    int check = comp1->info->equal(correctSum, sum1);

    item *sum2 = comp1->info->sum(comp1, NULL);

    if ((check == 1) && (sum2 == NULL)) printf("The test of the function of summation of two complex numbers (sumComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of summation of two complex numbers (sumComplex) has been failed\n");
    }

    comp1->info->freeItem(comp1);
    comp2->info->freeItem(comp2);
    correctSum->info->freeItem(correctSum);
    sum1->info->freeItem(sum1);
}

void testComplexMult(int *error) {
    item *comp1 = createComplex(3, 5);
    item *comp2 = createComplex(-7, 2);
    item *correctMult = createComplex(-31, -29);
    item *mult1 = comp1->info->mult(comp1, comp2);
    int check = comp1->info->equal(correctMult, mult1);

    item *mult2 = comp1->info->mult(comp1, NULL);

    if ((check == 1) && (mult2 == NULL)) printf("The test of the function of multiplication of two complex numbers (multComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of multiplication of two complex numbers (multComplex) has been failed\n");
    }

    comp1->info->freeItem(comp1);
    comp2->info->freeItem(comp2);
    correctMult->info->freeItem(correctMult);
    mult1->info->freeItem(mult1);
}

void testComplexReverseSum(int *error) {
    item *comp = createComplex(4, -6);
    item *correctRev = createComplex(-4, 6);
    item *rev1 = comp->info->reverseSum(comp);
    int check = comp->info->equal(correctRev, rev1);

    item *rev2 = comp->info->reverseSum(NULL);

    if ((check == 1) && (rev2 == NULL)) printf("The test of the function of finding the inverse complex number relative zero (reverseSumComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the inverse complex number relative zero (reverseSumComplex) has been failed\n");
    }

    comp->info->freeItem(comp);
    correctRev->info->freeItem(correctRev);
    rev1->info->freeItem(rev1);
}

void testComplexReverseMult(int *error) {
    item *comp = createComplex(3, 4);
    item *correctRev = createComplex(0.12, -0.16);
    item *rev1 = comp->info->reverseMult(comp);
    int check = comp->info->equal(correctRev, rev1);

    item *rev2 = comp->info->reverseMult(NULL);

    if ((check == 1) && (rev2 == NULL)) printf("The test of the function of finding the inverse complex number relative one (reverseMultComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the inverse complex number relative one (reverseMultComplex) has been failed\n");
    }

    comp->info->freeItem(comp);
    correctRev->info->freeItem(correctRev);
    rev1->info->freeItem(rev1);
}

void testComplexDifference(int *error) {
    item *comp1 = createComplex(-2, 8);
    item *comp2 = createComplex(-7, 3);
    item *correctDif = createComplex(5, 5);
    item *dif1 = comp1->info->difference(comp1, comp2);
    int check = comp1->info->equal(correctDif, dif1);

    item *dif2 = comp1->info->difference(comp1, NULL);

    if ((check == 1) && (dif2 == NULL)) printf("The test of the function of finding the difference between two complex numbers (differenceComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the difference between two complex numbers (differenceComplex) has been failed\n");
    }

    comp1->info->freeItem(comp1);
    comp2->info->freeItem(comp2);
    correctDif->info->freeItem(correctDif);
    dif1->info->freeItem(dif1);
}

void testComplexDivision(int *error) {
    item *comp1 = createComplex(-17, 19);
    item *comp2 = createComplex(1, 5);
    item *correctDiv = createComplex(3, 4);
    item *div1 = comp1->info->division(comp1, comp2);
    int check = comp1->info->equal(correctDiv, div1);

    item *div2 = comp1->info->division(comp1, NULL);

    if ((check == 1) && (div2 == NULL)) printf("The test of the function of finding the quotient of two complex numbers (divisionComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of finding the quotient of two complex numbers (divisionComplex) has been failed\n");
    }

    comp1->info->freeItem(comp1);
    comp2->info->freeItem(comp2);
    correctDiv->info->freeItem(correctDiv);
    div1->info->freeItem(div1);
}

void testComplexCopy(int *error) {
    item *comp = createComplex(-10, 4);
    item *copy1 = comp->info->copy(comp);
    int check = comp->info->equal(comp, copy1);

    item *copy2 = comp->info->copy(NULL);

    if ((check == 1) && (copy2 == NULL)) printf("The test of the function of copying a complex number (copyComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of copying a complex number (copyComplex) has been failed\n");
    }

    comp->info->freeItem(comp);
    copy1->info->freeItem(copy1);
}

void testComplexCompare(int *error) {
    item *comp1 = createComplex(-17, 19);
    item *comp2 = createComplex(1, 5);
    int check1 = comp1->info->compare(comp1, comp2);
    int check2 = comp1->info->compare(NULL, comp2);

    if ((check1 == 0) && (check2 == 0)) printf("The test of the function of comparing two complex numbers (compareComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of comparing two complex numbers (compareComplex) has been failed\n");
    }
    comp1->info->freeItem(comp1);
    comp2->info->freeItem(comp2);
}

void testComplexEqual(int *error) {
    item *comp1 = createComplex(-17, 19);
    item *comp2 = createComplex(1, 5);
    int check1 = comp1->info->equal(comp1, comp2);
    int check2 = comp1->info->equal(comp1, comp1);
    int check3 = comp1->info->equal(comp1, NULL);

    if ((check1 == 0) && (check2 == 1) && (check3 == 0)) printf("The test of the function of checking the equality of two complex numbers (equalComplex) has been successfully passed\n");
    else {
        (*error) = 1;
        printf("The test of the function of checking the equality of two complex numbers (equalComplex) has been failed\n");
    }

    comp1->info->freeItem(comp1);
    comp2->info->freeItem(comp2);
}
