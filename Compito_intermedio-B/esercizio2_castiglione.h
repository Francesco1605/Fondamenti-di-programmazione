// Dichiarazione delle funzioni:
#ifndef ESERCIZIO2_CASTIGLIONE_H
#define ESERCIZIO2_CASTIGLIONE_H

#define SIZE 7
#define MAX_LEN 20

int count_vowel_start(char words[][MAX_LEN], int size);
int count_strings_with_number(char words[][MAX_LEN], int size);
void find_longest_shortest(char words[][MAX_LEN], int size, char longest[], char shortest[]);
int count_palindromes(char words[][MAX_LEN], int size);
int total_characters(char words[][MAX_LEN], int size);
void print_strings(char words[][MAX_LEN], int size);
void print_reversed_strings(char words[][MAX_LEN], int size);
void print_reversed_characters(char words[][MAX_LEN], int size);

#endif 
