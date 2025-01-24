#include <stdio.h>

int main() {
    int N;

    // Richiesta del numero intero positivo
    do {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &N);

        if (N <= 0) {
            printf("Per favore, inserisci un numero positivo!\n");
        }
    } while (N <= 0);  // Continuare a chiedere finché N non è positivo

    // Ciclo per stampare il triangolo di numeri
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");  // Vai a capo dopo ogni riga
    }

    return 0;
}
