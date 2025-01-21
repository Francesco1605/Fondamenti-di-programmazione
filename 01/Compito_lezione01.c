#include <stdio.h>

int main()

{
    // Dichiarazione delle variabili
    char nome[50];
    char cognome[50];

    // Input dell'utente
    printf("Inserisci il tuo nome: ");
    scanf("%s", nome); 

    printf("Inserisci il tuo cognome: ");
    scanf("%s", cognome);

    // Output del programma
    printf("\nBenvenuto, %s %s!\n", nome, cognome);
    printf("Grazie per aver usato il nostro programma.\n");
    printf("Ti auguriamo Buone Feste\n");

    // Disegno dell'albero di Natale
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("*******\n");
    printf("  ***\n");

    return 0;
}