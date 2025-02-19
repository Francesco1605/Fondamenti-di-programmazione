#include <stdio.h>
#include <string.h>
#include "compitostatic_lezione09.h"

int main() {
    int total_words = 0;
    size_t total_length = 0; // Cambiato a size_t per essere coerente con strlen
    char word[100];

    do {
        printf("Inserisci una parola: "); // Chiede all'utente di inserire una parola
        scanf("%s", word);

        if (strcmp(word, "stop") == 0) {
            break;
        } // Se l'utente inserisce "stop" il programma si ferma

        total_words++; // Somma totale delle parole analizzate
        size_t length = strlen(word); // Calcola la lunghezza della stringa dopo aver letto l'input
        total_length += length; // Somma totale della lunghezza delle parole

        analyze_word(word, total_words, total_length);

        printf("Totale parole analizzate: %d\n", total_words);
        printf("Lunghezza parola: %zu\n", length); // Utilizza %zu per stampare size_t
        printf("Totale lunghezza parole: %zu\n", total_length); // Utilizza %zu per stampare size_t
        printf("Media lunghezza parole: %.2f\n", (float)total_length / total_words);
        printf("\n");

    } while (1);

    return 0;
}