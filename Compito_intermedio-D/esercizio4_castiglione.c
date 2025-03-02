#include <stdio.h>
#include "esercizio4_castiglione.h"

// Funzione per stampare la matrice 3D:
void print_matrix(int matrix[2][3][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Funzione per modificare gli elementi pari e dispari:
void modify_even_odd(int matrix[2][3][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (matrix[i][j][k] % 2 == 0) {
                    matrix[i][j][k] = -1;  // Sostituisci i numeri pari con -1
                } else {
                    matrix[i][j][k] = 1;   // Sostituisci i numeri dispari con 1
                }
            }
        }
    }
}

// Funzione per verificare se una sottostruttura 3x3 è un Sudoku perfetto:
int is_perfect_sudoku(int matrix[3][3]) {
    int numbers[9] = {0};  // Array per tracciare i numeri da 1 a 9

    // Controlla ogni elemento nella matrice 3x3:
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = matrix[i][j];
            if (num < 1 || num > 9 || numbers[num - 1] != 0) {
                return 0; // Non è un Sudoku perfetto se il numero è fuori range o ripetuto
            }
            numbers[num - 1] = 1; // Segna il numero come già visto
        }
    }
    return 1;  // Se tutti i numeri sono unici e tra 1 e 9
}

int main() {

    // Inizializzazione matrice 3D:
    int matrix[2][3][3] = {
        {
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9}
        },
        {
            {1, 4, 7},
            {2, 5, 8},
            {3, 5, 9}  // Il numero 5 è ripetuto volutamente
        }
    };

    printf("Matrice originale:\n");
    print_matrix(matrix);

    // Modifica della matrice sostituendo i pari con -1 e i dispari con 1:
    modify_even_odd(matrix);
    printf("Dopo sostituzione pari/dispari:\n");
    print_matrix(matrix);

    // Verifica se le sottostrutture 3x3 sono Sudoku perfetti:
    for (int i = 0; i < 2; i++) {
        if (is_perfect_sudoku(matrix[i])) {
            printf("La matrice %d 3x3 è un Sudoku perfetto.\n", i + 1);
        } else {
            printf("La matrice %d 3x3 non è un Sudoku perfetto.\n", i + 1);
        }
    }

    return 0;
}
