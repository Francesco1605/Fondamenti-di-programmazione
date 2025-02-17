#include <stdio.h>
#include <string.h>
#include "compitostatic_lezione09.h"

int main() {
    
    int total_words = 0;
    int total_vowels = 0;
    int total_consonants = 0;
    int total_length = 0;
    char word[100];
    

    do {
        printf("Inserisci una parola: "); // Chiede all'utente di inserire una parola
        scanf("%s", word);

        if (strcmp(word, "stop") == 0) {
            break;
        } // Se l'utente inserisce "stop" il programma si ferma

        size_t length = strlen(word);
        total_words++; // Somma totale delle parole analizzate
        total_length += length; // Somma totale della lunghezza delle parole

        analyze_word(word, &total_vowels, &total_consonants);

        printf("Totale vocali: %d, Totale consonanti: %d\n", total_vowels, total_consonants);
        printf("Totale parole analizzate: %d\n", total_words);
        printf("Lunghezza parola: %d\n", length);
        printf("Totale lunghezza parole: %d\n", total_length);
        printf("Media lunghezza parole: %.2f\n", (float)total_length / total_words);
        printf("\n");

    } while (1); // Ciclo infinito

    return 0;
}