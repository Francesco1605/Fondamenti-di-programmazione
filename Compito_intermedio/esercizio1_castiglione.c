#include <stdio.h>
#include "esercizio1_castiglione.h"

int main() {
    int choice, num1, num2;
    int numbers[] = {2, 4, 6, 8, 10};
    do {
        // Menu delle opzioni:
        printf("\nMenù:\n");
        printf("1. Addizione (+)\n2. Sottrazione (-)\n3. Moltiplicazione (*)\n4. Divisione (/)\n");
        printf("5. Modulo (%%)\n6. Potenza (^)\n7. Test di tutte le funzioni\n8. Esci\n\n");
        printf("Scegli un'opzione (1-8): ");
        scanf("%d", &choice);
        printf("\n");

        if (choice >= 1 && choice <= 6) {
            printf("Inserisci due numeri: ");
            scanf("%d %d", &num1, &num2);
        }

        printf("\n");

        switch (choice) {
            case 1: 
                printf("Risultato: %d\n", add(num1, num2)); 
                break;
            case 2: 
                printf("Risultato: %d\n", sub(num1, num2)); 
                break;
            case 3: 
                printf("Risultato: %d\n", mul(num1, num2)); 
                break;
            case 4: 
                printf("Risultato: %.2f\n", divi(num1, num2)); 
                break;
            case 5: 
                printf("Risultato: %d\n", mod(num1, num2)); 
                break;
            case 6: 
                printf("Risultato: %d\n", power(num1, num2)); 
                break;
            case 7: 
                test_all_operations(numbers, 5); 
                break;
            case 8: 
                printf("Uscita dal programma.\n"); 
                printf("\n");
                break;
            default: 
                printf("Opzione non valida, riprova.\n");
        }
    } while (choice != 8);
    return 0;
}
