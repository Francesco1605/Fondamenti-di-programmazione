#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funzione per verificare se una stringa è palindroma
int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Non è palindroma
        }
    }
    return 1; // È palindroma
}

// Funzione per verificare se una stringa contiene almeno un numero
int contains_number(const char *str) {
    while (*str) {
        if (isdigit(*str)) {
            return 1; // Contiene un numero
        }
        str++;
    }
    return 0; // Non contiene numeri
}

// Funzione per verificare se una stringa contiene almeno una vocale
int contains_vowel(const char *str) {
    while (*str) {
        char c = tolower(*str);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1; // Contiene una vocale
        }
        str++;
    }
    return 0; // Non contiene vocali
}

int main() {
    // Inizializzazione dell'array di stringhe
    const char *strings[6] = {"apple", "banana", "123hello", "Aardvark", "racecar", "world"};

    // Variabili per i risultati
    int starts_with_A = 0;
    int contains_digits = 0;
    int palindrome_count = 0;
    int all_longer_than_5 = 1; // Presumiamo che tutte siano lunghe > 5
    int all_contain_vowel = 1; // Presumiamo che tutte contengano una vocale
    const char *longest_str = strings[0], *shortest_str = strings[0];

    // Analisi delle stringhe
    for (int i = 0; i < 6; i++) {
        // Verifica se la stringa inizia con 'A' o 'a'
        if (strings[i][0] == 'A' || strings[i][0] == 'a') {
            starts_with_A++;
        }

        // Verifica se la stringa contiene almeno un numero
        if (contains_number(strings[i])) {
            contains_digits++;
        }

        // Verifica se la stringa è palindroma
        if (is_palindrome(strings[i])) {
            palindrome_count++;
        }

        // Trova la stringa più lunga e quella più corta
        int len = strlen(strings[i]);
        if (len > strlen(longest_str)) {
            longest_str = strings[i];
        }
        if (len < strlen(shortest_str)) {
            shortest_str = strings[i];
        }

        // Verifica se tutte le stringhe sono più lunghe di 5 caratteri
        if (len <= 5) {
            all_longer_than_5 = 0;
        }

        // Verifica se tutte le stringhe contengono almeno una vocale
        if (!contains_vowel(strings[i])) {
            all_contain_vowel = 0;
        }
    }

    // Stampa i risultati
    printf("Numero di stringhe che iniziano con 'A' o 'a': %d\n", starts_with_A);
    printf("Numero di stringhe che contengono almeno un numero: %d\n", contains_digits);
    printf("La stringa più lunga è: %s\n", longest_str);
    printf("La stringa più corta è: %s\n", shortest_str);
    printf("Numero di stringhe palindrome: %d\n", palindrome_count);

    // Messaggi se tutte le stringhe sono lunghe più di 5 o contengono almeno una vocale
    if (all_longer_than_5) {
        printf("Tutte le stringhe sono lunghe più di 5 caratteri.\n");
    }
    if (all_contain_vowel) {
        printf("Tutte le stringhe contengono almeno una vocale.\n");
    }

    return 0;
}
