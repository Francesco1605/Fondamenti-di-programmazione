#include <stdio.h>
#include <stdlib.h>
#include "Compitofunzioni1_lezione07.h"

int main() {

    do {

        printf("Inserisci un numero: ");
    scanf("%d", &num1);
    printf("Inseriscri un secondo numero: ");
    scanf("%d", &num2);
    printf("\n");
    printf("1. Addizione\n2. Sottrazione\n3. Moltiplicazione\n4. Divisione\n5. Esci\n");
    printf("\n");
    printf("Inserisci l'operazione da 1 a 5 da eseguire: ");
    scanf("%d", &operazione);
    printf("\n");

    switch (operazione) {
    case 1:
    risultato = add(num1, num2);
        printf("\nIl risultato dell'addizione è: %d\n\n\n", risultato);
        break;
    case 2:
    risultato = sub(num1, num2);
        printf("Il risultato della sottrazione è: %d\n\n\n", risultato);
        break;
    case 3:
    risultato = mul(num1, num2);
        printf("Il risultato della moltiplicazione è: %d\n\n\n", risultato);
        break;
    case 4:
    if (num2 != 0) {
        float risultato_div = divi((float)num1, (float)num2);
        printf("Il risultato della divisione è: %.2f\n\n\n", risultato_div);
    } else {
        printf("Non puoi dividere per 0\n\n\n");
    }
        break;
    case 5: 
        printf("Hai scelto di uscire\n\n\n");
        break;

        default:
        printf("Operazione non valida\n\n\n");
        break;
    } 
    } while (operazione != 5);

    return 0;
}