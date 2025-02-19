#include <stdio.h>
#include <string.h>
#include "compitostatic_lezione09.h"

void analyze_word(char word[]) {
    static int total_vowels = 0;
    static int total_consonants = 0;
    int local_vowels = 0;
    int local_consonants = 0;
    size_t length = strlen(word); // Calcola la lunghezza della stringa una volta

    // Conteggio delle vocali e delle consonanti della singola parola:
    for (size_t i = 0; i < length; i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
            local_vowels++;
        } else if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            local_consonants++;
        }
    }

    // Somma delle vocali e delle consonanti ad ogni parola:
    total_vowels += local_vowels;
    total_consonants += local_consonants;

    printf("Parola: %s\n", word);
    printf("Vocali nella parola: %d\n", local_vowels);
    printf("Consonanti nella parola: %d\n", local_consonants);
    printf("Totale vocali: %d\n", total_vowels);
    printf("Totale consonanti: %d\n", total_consonants);
}