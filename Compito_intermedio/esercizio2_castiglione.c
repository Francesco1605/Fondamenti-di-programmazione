#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "esercizio2_castiglione.h"
#define SIZE 7
#define MAX_LEN 20

// Conta le stringhe che iniziano con una vocale (A, E, I, O, U):
int count_vowel_start(char words[][MAX_LEN], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        char first = tolower(words[i][0]);
        if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
            count++;
        }
    }
    return count;
}

// Conta le stringhe che contengono almeno un numero (0-9):
int count_strings_with_number(char words[][MAX_LEN], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            if (isdigit(words[i][j])) {
                count++;
                break;
            }
        }
    }
    return count;
}

// Trova la stringa più lunga e quella più corta:
void find_longest_shortest(char words[][MAX_LEN], int size, char longest[], char shortest[]) {
    strcpy(longest, words[0]);
    strcpy(shortest, words[0]);

    for (int i = 1; i < size; i++) {
        if (strlen(words[i]) > strlen(longest)) {
            strcpy(longest, words[i]);
        }
        if (strlen(words[i]) < strlen(shortest)) {
            strcpy(shortest, words[i]);
        }
    }
}

// Conta le stringhe palindrome:
int count_palindromes(char words[][MAX_LEN], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int len = strlen(words[i]);
        int is_palindrome = 1;
        for (int j = 0; j < len / 2; j++) {
            if (tolower(words[i][j]) != tolower(words[i][len - j - 1])) {
                is_palindrome = 0;
                break;
            }
        }
        if (is_palindrome) {
            count++;
        }
    }
    return count;
}

// Conta il numero totale di caratteri nelle stringhe:
int total_characters(char words[][MAX_LEN], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += strlen(words[i]);
    }
    return total;
}

// Stampa le stringhe in ordine corretto:
void print_strings(char words[][MAX_LEN], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s", words[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

// Stampa le stringhe in ordine inverso:
void print_reversed_strings(char words[][MAX_LEN], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) printf(", ");
    }
    printf("\n");
}

// Stampa le stringhe in ordine inverso con caratteri invertiti:
void print_reversed_characters(char words[][MAX_LEN], int size) {
    for (int i = size - 1; i >= 0; i--) {
        int len = strlen(words[i]);
        for (int j = len - 1; j >= 0; j--) {
            printf("%c", words[i][j]);
        }
        if (i > 0) printf(", ");
    }
    printf("\n");
}

int main() {
    char words[SIZE][MAX_LEN] = {"elephant", "42trees", "Anna", "oasis", "civic", "mango", "Galaxy"};
    char longest[MAX_LEN], shortest[MAX_LEN];

    printf("Numero di stringhe che iniziano con una vocale: %d\n", count_vowel_start(words, SIZE));
    printf("Numero di stringhe con almeno un numero: %d\n", count_strings_with_number(words, SIZE));

    find_longest_shortest(words, SIZE, longest, shortest);
    printf("Stringa più lunga: \"%s\"\n", longest);
    printf("Stringa più corta: \"%s\"\n", shortest);

    printf("Numero di stringhe palindrome: %d\n", count_palindromes(words, SIZE));
    printf("Numero totale di caratteri: %d\n", total_characters(words, SIZE));

    printf("Elenco delle stringhe in ordine corretto: ");
    print_strings(words, SIZE);

    printf("Elenco delle stringhe in ordine inverso: ");
    print_reversed_strings(words, SIZE);

    printf("Elenco delle stringhe in ordine inverso con caratteri invertiti: ");
    print_reversed_characters(words, SIZE);

    return 0;
}
