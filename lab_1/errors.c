#include <stdlib.h>
#include "string.h"
#include "errors.h"

error exitLabel = {0, NULL};

error allocation = {
    1,
    "Memory allocation error"
};

error nullPointer = {
    2,
    "Using a null pointer"
};

error invalidItem = {
    3,
    "Impossible to do action with this item"
};

error invalidType = {
    4,
    "Impossible to do action with this type of item"
};

error differentTypesInMatrix = {
    5,
    "Attempt to create a matrix with different types of items"
};

error matricesContainDifferentTypes = {
    6,
    "Impossible to do action with matrices containing items of different types"
};

error invalidMatrixSize = {
    7,
    "Impossible to do action with matrices of this size"
};

error eof = {
    8,
    "EOF"
};

listOfErrors errorList = {
    &allocation,
    &nullPointer,
    &invalidItem,
    &invalidType,
    &differentTypesInMatrix,
    &matricesContainDifferentTypes,
    &invalidMatrixSize,
    &eof
};

void setError(error *bug) {
    exitLabel.code = (*bug).code;
    exitLabel.message = (*bug).message;
}
