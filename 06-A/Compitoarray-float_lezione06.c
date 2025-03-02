#include <stdio.h>
#include <math.h>  // Per la funzione fabs() per il valore assoluto (se necessario)

int main() {
    // Definizione e inizializzazione statica della matrice 3x4
    float matrix[3][4] = {
        {1.5, -6.8, 10.0, 0.0},
        {-3.2, 7.1, -11.3, 0.0},
        {4.0, -8.4, 12.6, 0.0}
    };

    // Variabili per le somme, min, max, e contatori
    float positiveSum = 0, negativeSum = 0;
    float max = matrix[0][0], min = matrix[0][0];
    int evenCount = 0, oddCount = 0;
    int allPositive = 1, allNegative = 1;
    int multipleOfFive = 0;

    // Iterazione sulla matrice 3x4
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            float num = matrix[i][j];

            // Calcolare la somma dei numeri positivi e negativi
            if (num > 0) {
                positiveSum += num;
                allNegative = 0;  // Se trovi un numero positivo, non sono tutti negativi
            } else if (num < 0) {
                negativeSum += num;
                allPositive = 0;  // Se trovi un numero negativo, non sono tutti positivi
            }

            // Calcolare il massimo e minimo della matrice
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }

            // Contare i numeri pari e dispari considerando solo la parte intera
            int intPart = (int)num;  // Estrarre la parte intera del numero
            if (intPart % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }

            // Verifica se almeno un numero è multiplo di 5
            if ((int)num % 5 == 0) {
                multipleOfFive = 1;
            }
        }
    }

    // Stampa dei risultati calcolati
    printf("Somma dei numeri positivi: %.2f\n", positiveSum);
    printf("Somma dei numeri negativi: %.2f\n", negativeSum);
    printf("Valore massimo: %.2f\n", max);
    printf("Valore minimo: %.2f\n", min);
    printf("Numero di numeri pari: %d\n", evenCount);
    printf("Numero di numeri dispari: %d\n", oddCount);

    // Verifica se tutti i numeri sono positivi o negativi
    if (allPositive) {
        printf("Tutti i numeri sono positivi.\n");
    } else if (allNegative) {
        printf("Tutti i numeri sono negativi.\n");
    }

    // Verifica se almeno un numero è multiplo di 5
    if (multipleOfFive) {
        printf("Almeno un numero è multiplo di 5.\n");
    }

    return 0;
}
