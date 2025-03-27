#ifndef errors_h
#define errors_h

typedef struct error {
    int code;
    char *message;
} error;

typedef struct listOfErrors {
    error *allocation;
    error *nullPointer;
    error *invalidItem;
    error *invalidType;
    error *differentTypesInMatrix;
    error *matricesContainDifferentTypes;
    error *invalidMatrixSize;
    error *eof;
} listOfErrors;

extern error exitLabel;
extern listOfErrors errorList;

void setError(error *bug);

#endif

// 1 - memory allocation error
// 2 - using a null pointer
// 3 - impossible to do action with this item
// 4 - impossible to do action with this type of item
// 5 - attempt to create a matrix with different types of items
// 6 - impossible to do action with matrices containing items of different types
// 7 - impossible to do action with matrices of this size
// 8 - EOF