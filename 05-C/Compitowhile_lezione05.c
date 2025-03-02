#include <stdio.h>

int main(void) {

  int numero, somma = 0, massimo = 0, lunghezza = 0;

  printf("Inserisci una sequenza di numeri interi positivi (0 per terminare)!\n");
  
  while (1) { // Ciclo infinito che termina solo con il break
    printf("Inserisci un numero (0 per terminare): ");
    scanf("%d", &numero);

    if (numero == 0) {
        break; // Termina il ciclo se l'utente inserisce 0
    }

    if (numero > 0) {
        somma += numero; // Aggiunge il numero alla somma
        lunghezza++;     // Incrementa la lunghezza della sequenza

        if (numero > massimo) {
            massimo = numero; // Aggiorna il massimo se il numero attuale è più grande
        }
    } else {
        printf("Numero negativo ignorato.\n");
    }
  }

  if (lunghezza == 0) {
    printf("Nessun numero valido inserito.\n");
  } else {
    printf("Somma totale: %d\n", somma);
    printf("Numero massimo: %d\n", massimo);
    printf("Lunghezza della sequenza: %d\n", lunghezza);
  }
  
  return 0;
}