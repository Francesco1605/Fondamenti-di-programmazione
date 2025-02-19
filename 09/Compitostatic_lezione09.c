#include <stdio.h>
#include <string.h>
#include "compitostatic_lezione09.h"

int main() {
    static int total_words = 0;
    static size_t total_length = 0;
    char word[100];

    do {

        printf("Inserisci una parola (stop per teminare): "); // Chiede all'utente di inserire una parola
        scanf("%s", word);

        analyze_word(word);

        if (strcmp(word, "stop") == 0) {
            printf("Programma terminato.\n");
            break;
        } // Se l'utente inserisce "stop" il programma si ferma

    } while (1);

    return 0;
}