#ifndef testsMatrix_h
#define testsMatrix_h

void testsMatrix();
void testGetRowsCount(bool *check);
void testGetColumnsCount(bool *check);
void testOperator1Matrix(bool *check);
void testOperator2Matrix(bool *check);
void testOperator3Matrix(bool *check);
void testOperator4Matrix(bool *check);
void testGetNormRow(bool *check);
void testGetNormColumn(bool *check);
void testGetNormSquare(bool *check);
void testSet(bool *check);
void testSwapRows(bool *check);
void testSwapColumns(bool *check);
void testMultRowOnScalar(bool *check);
void testMultColumnOnScalar(bool *check);
void testLineCombRow(bool *check);
void testLineCombColumn(bool *check);
void testOperator5Matrix(bool *check);

#endif