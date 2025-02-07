#include <stdio.h>
#include "esercizio1_castiglione.h"

// Funzioni per le operazioni:
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float divi(int a, int b) { 
    return (b != 0) ? (float)a / b : 0; 
}
int mod(int a, int b) {
    return (b != 0) ? a % b : 0;
}
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

// Funzione per testare tutte le operazioni:
void test_all_operations(int arr[], int size) {
    printf("\nTest delle operazioni sui numeri {2, 4, 6, 8, 10}:\n");
    for (int i = 0; i < size - 1; i++) {
        printf("%d + %d = %d\n", arr[i], arr[i+1], add(arr[i], arr[i+1]));
        printf("%d - %d = %d\n", arr[i+1], arr[i], sub(arr[i+1], arr[i]));
        printf("%d * %d = %d\n", arr[i], arr[i+1], mul(arr[i], arr[i+1]));
        printf("%d / %d = %.2f\n", arr[i+1], arr[i], divi(arr[i+1], arr[i]));
        printf("%d %% %d = %d\n", arr[i], arr[i+1], mod(arr[i], arr[i+1]));
        printf("%d ^ 2 = %d\n", arr[i+1], power(arr[i+1], 2));
    }
}

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
