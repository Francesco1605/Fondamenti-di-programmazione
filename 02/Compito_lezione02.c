#include <stdio.h>
#include <string.h>

// Dichiarazione delle macro
#define NOME "Francesco"
#define COGNOME "Castiglione"
#define PERCENTUALE_R1 0.85
#define PERCENTUALE_R2 0.75
#define PERCENTUALE_R3 0.65
#define PERCENTUALE_R4 0.50
#define PERCENTUALE_R5 0.40

int main() {
    // Dichiarazione delle variabili
    char categoria[3]; // La categoria può essere R1, R2, R3, R4, R5
    double peso, recuperabile, irrecuperabile;

    // Stampa il messaggio introduttivo con il nome e il cognome
    printf("Ciao! Sono %s %s.\n", NOME, COGNOME);

    // Chiedi la categoria RAEE
    printf("Inserisci la categoria RAEE (R1, R2, R3, R4, R5): ");
    scanf("%s", categoria);

    // Chiedi il peso in kg
    printf("Inserisci il peso in kg.: ");
    scanf("%lf", &peso);

    // Calcola la percentuale di materiale recuperabile e irrecuperabile
    if (strcmp(categoria, "R1") == 0) {
        recuperabile = peso * PERCENTUALE_R1;
    } else if (strcmp(categoria, "R2") == 0) {
        recuperabile = peso * PERCENTUALE_R2;
    } else if (strcmp(categoria, "R3") == 0) {
        recuperabile = peso * PERCENTUALE_R3;
    } else if (strcmp(categoria, "R4") == 0) {
        recuperabile = peso * PERCENTUALE_R4;
    } else if (strcmp(categoria, "R5") == 0) {
        recuperabile = peso * PERCENTUALE_R5;
    } else {
        printf("Categoria non valida!\n");
        return 1; // Uscita con codice di errore
    }

    // Calcolo del peso irrecuperabile
    irrecuperabile = peso - recuperabile;

    // Stampa i risultati
    printf("\nPeso totale: %.2lf kg.\n", peso);
    printf("Recuperabile: %.2lf kg.\n", recuperabile);
    printf("Irrecuperabile: %.2lf kg.\n", irrecuperabile);

    // Messaggio di chiusura
    printf("Grazie per aver usato il nostro programma.\n");

    return 0;
}
