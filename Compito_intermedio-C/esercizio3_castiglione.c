#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>  
#include "esercizio3_castiglione.h"

// Funzione per nascondere la parola con gli asterischi:
void mask_word(const char* word, char* masked_word) {
    size_t len = strlen(word);
    for (size_t i = 0; i < len; i++) {
        masked_word[i] = '*';
    }
    masked_word[len] = '\0';
}

// Funzione per controllare se la lettera inserita è presente nella parola nascosta:
int check_letter(const char* word, char* masked_word, char letter) {
    size_t len = strlen(word);
    int found = 0;

    for (size_t i = 0; i < len; i++) {
        if (word[i] == letter && masked_word[i] == '*') {
            masked_word[i] = letter;
            found = 1;
        }
    }
    return found;
}

int main() {
    char words[][20] = {"elephant", "banana", "computer", "galaxy", "puzzle", "giraffe"};
    char hidden_word[20];
    char masked_word[20];
    char guess;
    int attempts = 0;

    // Selezione casuale della parola:
    srand((unsigned int)time(NULL));
    strcpy(hidden_word, words[rand() % 6]);

    // Nascondi la parola con '*':
    mask_word(hidden_word, masked_word);

    printf("La parola da indovinare è: %s\n", masked_word);

    // Continua finché non si indovina la parola:
    while (strchr(masked_word, '*') != NULL) {
        
        // Input della lettera:
        do {
            printf("\nInserisci un solo carattere alfabetico: ");
            if (scanf(" %c", &guess) != 1 || !isalpha(guess)) {
                printf("Errore: Inserisci una sola lettera valida!\n");
                while (getchar() != '\n');  // Svuota il buffer di input
            } else {
                break;
            }
        } while (1);

        guess = tolower(guess); // Converti la lettera in minuscolo

        if (check_letter(hidden_word, masked_word, guess)) {
            printf("Lettera presente!\n");
        } else {
            printf("Lettera non presente!\n");
        }

        printf("Parola attuale: %s\n", masked_word);
        attempts++;
    }

    // Stampa il messaggio finale:
    printf("\nComplimenti! Hai indovinato la parola \"%s\" in %d tentativi!\n", hidden_word, attempts);

    return 0;
}
