#include <string.h>

void analyze_word(char word[], int *vowels, int *consonants) {
    int local_vowels = 0;
    int local_consonants = 0;
    size_t length = strlen(word);

        // Conteggio delle vocali e delle consonanti della parola inserita:
    for (size_t i = 0; i < length; i++) {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {

            local_vowels++;

        } else if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {

            local_consonants++;
        }
    }

    // Somma delle vocali e delle consonanti ad ogni parola:
    *vowels += local_vowels;
    *consonants += local_consonants;

    printf("Parola: %s\n", word); // Parola inserita
    printf("Vocali: %d, Consonanti: %d\n", local_vowels, local_consonants); // Vocali e consonanti della parola inserita
}