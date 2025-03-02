#ifndef COMPITOFUNZIONI3_LEZIONE07_H
#define COMPITOFUNZIONI3_LEZIONE07_H


#define SIZE 5 // Modificabile per testare diverse matrici

int sumMatrix(int matrix[SIZE][SIZE], int size);
float averageDiagonal(int matrix[SIZE][SIZE], int size);
int countEvenNumbers(int matrix[SIZE][SIZE], int size);
int countOddNumbers(int matrix[SIZE][SIZE], int size);
int findMax(int matrix[SIZE][SIZE], int size);
int findMin(int matrix[SIZE][SIZE], int size);
void rowSums(int matrix[SIZE][SIZE], int size);
void columnSums(int matrix[SIZE][SIZE], int size);
int isSymmetric(int matrix[SIZE][SIZE], int size);

#endif // MATRIX_UTILS_H
