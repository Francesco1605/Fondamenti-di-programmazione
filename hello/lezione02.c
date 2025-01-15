#include <stdio.h>
#include <stdbool.h>

// definizione di macros (ogni volta che scriverò NEW_LINE avrò printf("\n"); ecc...):
#define NEW_LINE printf("\n");
#define DEBUG_PRINT(x) printf("[DEBUG] - ");printf("%s", x);printf("\n");
#define PI_GRECO 3.141592653589793


int main()

{

 //print the message "Hello World!!!" to the console:
    // \n is the shortcut for new line:
    printf("Hello World!!!\n\n\n");

    // variable of 32 chars:
    char name[32];

    // ask for name:
    printf("Inserisci il tuo nome: ");

    // read the input of the user:
    scanf("%s", name);

    // print a message with the name entered:
    printf("\nHello\t%s\n\n\n", name);

int i = 10;
printf("Il valore intero è: %d\n", i);

float f = 10.10;
printf("Inserisci il valore intero: ");
scanf("%f", &f);
NEW_LINE;

printf("=== AREA DEL CERCHIO ===");
NEW_LINE;
printf("Inserisci il raggio: ");
scanf("%f", &f);
NEW_LINE;

float area = f * f * PI_GRECO;
float funny = (f + f - PI_GRECO) / 10.0;

printf("L'area del cerchio è %f", area);
NEW_LINE;
printf("Calcolo con tutti gli operatori matematici %f", funny);
NEW_LINE;
DEBUG_PRINT("Programma terminato");

NEW_LINE;
NEW_LINE;
return 0;

}