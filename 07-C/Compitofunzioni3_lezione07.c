#include <stdio.h>
#include "compitofunzioni3_lezione07.h"

#define SIZE 5 // Modificabile per testare diverse matrici

int sumMatrix(int matrix[SIZE][SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

float averageDiagonal(int matrix[SIZE][SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return (float)sum / size;
}

int countEvenNumbers(int matrix[SIZE][SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    return count;
}

int countOddNumbers(int matrix[SIZE][SIZE], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] % 2 != 0) {
                count++;
            }
        }
    }
    return count;
}

int findMax(int matrix[SIZE][SIZE], int size) {
    int max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int findMin(int matrix[SIZE][SIZE], int size) {
    int min = matrix[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

void rowSums(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
        printf("Somma riga %d: %d\n", i, sum);
    }
}

void columnSums(int matrix[SIZE][SIZE], int size) {
    for (int j = 0; j < size; j++) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += matrix[i][j];
        }
        printf("Somma colonna %d: %d\n", j, sum);
    }
}

int isSymmetric(int matrix[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    printf("Somma di tutti gli elementi: %d\n", sumMatrix(matrix, SIZE));
    printf("Media della diagonale principale: %.2f\n", averageDiagonal(matrix, SIZE));
    printf("Numero di elementi pari: %d\n", countEvenNumbers(matrix, SIZE));
    printf("Numero di elementi dispari: %d\n", countOddNumbers(matrix, SIZE));
    printf("Valore massimo: %d\n", findMax(matrix, SIZE));
    printf("Valore minimo: %d\n", findMin(matrix, SIZE));

    rowSums(matrix, SIZE);
    columnSums(matrix, SIZE);

    if (isSymmetric(matrix, SIZE)) {
        printf("La matrice è simmetrica.\n");
    } else {
        printf("La matrice non è simmetrica.\n");
    }

    return 0;
}
