#include <stdio.h>
#include <string.h>
#include "compitostatic_lezione09.h"

void analyze_word(char word[]) {
    int i = 0;
    int vowels = 0;
    int consonants = 0;
    while (word[i] != '\0') {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
            vowels++;
        } else {
            consonants++;
        }
        i++;
    }
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

int main() {

    char word[100];

    do{
        printf("Insert a word: ");
        scanf("%s", word);
        analyze_word(word);

    } while (word[0] == 'STOP');








    return 0;
}