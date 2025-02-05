#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Compitofunzioni2_lezione07.h"

void count_strings_ending_with_a(char strings[][50], int num_strings) {
    int count_end_a = 0;
    for (int i = 0; i < num_strings; i++) {
        size_t len = strlen(strings[i]);
        if (len > 0 && (strings[i][len - 1] == 'A' || strings[i][len - 1] == 'a')) {
            count_end_a++;
        }
    }
    printf("Numero di stringhe che finiscono per 'A' o 'a': %d\n", count_end_a);
}

void count_strings_containing_digit(char strings[][50], int num_strings) {
    int count_contains_digit = 0;
    for (int j = 0; j < num_strings; j++) {
        size_t len = strlen(strings[j]);
        for (size_t k = 0; k < len; k++) {
            if (isdigit(strings[j][k])) {
                count_contains_digit++;
                break;
            }
        }
    }
    printf("Numero di stringhe che contengono almeno un numero: %d\n", count_contains_digit);
}

void find_longest_and_shortest_string(char strings[][50], int num_strings) {
    size_t max_len = 0, min_len = 50;
    char *longest_string = NULL;
    char *shortest_string = NULL;

    for (int i = 0; i < num_strings; i++) {
        size_t len = strlen(strings[i]);
        if (len > max_len) {
            max_len = len;
            longest_string = strings[i];
        }
        if (len < min_len) {
            min_len = len;
            shortest_string = strings[i];
        }
    }

    printf("La stringa più lunga è: '%s'\n", longest_string);
    printf("La stringa più corta è: '%s'\n", shortest_string);
}

int is_palindrome(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

void count_and_print_palindromes(char strings[][50], int num_strings) {
    int count_palindromes = 0;
    printf("Stringhe palindrome: ");
    for (int i = 0; i < num_strings; i++) {
        if (is_palindrome(strings[i])) {
            printf("'%s'\n", strings[i]);
            count_palindromes++;
        }
    }
    printf("Numero di stringhe palindrome: %d\n", count_palindromes);
}

void sort_strings_by_length(char strings[][50], int num_strings) {
    for (int i = 0; i < num_strings - 1; i++) {
        for (int j = i + 1; j < num_strings; j++) {
            if (strlen(strings[i]) > strlen(strings[j])) {
                char temp[50];
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
    printf("Stringhe ordinate per lunghezza: ");
    for (int i = 0; i < num_strings; i++) {
        printf("'%s' ", strings[i]);
    }
    printf("\n");
}

int contains_vowel(char *str) {
    char vowels[] = "aeiouAEIOU";
    for (size_t i = 0; i < strlen(str); i++) {
        if (strchr(vowels, str[i])) {
            return 1;
        }
    }
    return 0;
}

void check_special_conditions(char strings[][50], int num_strings) {
    int all_longer_than_5 = 1;
    int all_contain_vowel = 1;

    printf("Stringhe più lunghe di 5 caratteri e che contengono almeno una vocale:\n");
    for (int i = 0; i < num_strings; i++) {
        int longer_than_5 = strlen(strings[i]) > 5;
        int contains_vowel_flag = contains_vowel(strings[i]);

        if (longer_than_5) {
            printf("La stringa '%s' è più lunga di 5 caratteri.\n", strings[i]);
        } else {
            all_longer_than_5 = 0;
        }

        if (contains_vowel_flag) {
            printf("La stringa '%s' contiene almeno una vocale.\n", strings[i]);
        } else {
            all_contain_vowel = 0;
        }

        if (longer_than_5 && contains_vowel_flag) {
            printf("La stringa '%s' è più lunga di 5 caratteri e contiene almeno una vocale.\n", strings[i]);
        }
    }
}


int main() {
    char strings[6][50] = {"Anna", "banana", "apple", "A1pha", "racecar", "123"};
    int num_strings = 6;

    count_strings_ending_with_a(strings, num_strings);
    count_strings_containing_digit(strings, num_strings);
    find_longest_and_shortest_string(strings, num_strings);
    count_and_print_palindromes(strings, num_strings);
    sort_strings_by_length(strings, num_strings);
    check_special_conditions(strings, num_strings);
    return 0;
}