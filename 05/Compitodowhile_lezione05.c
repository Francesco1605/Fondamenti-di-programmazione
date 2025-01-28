#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int numeroSegreto, tentativo, tentativi = 0;

  // Inizializza il generatore di numeri casuali
  srand(time(NULL));
  numeroSegreto = rand() % 100 + 1; // Numero casuale tra 1 e 100

  printf("Indovina il numero segreto tra 1 e 100!\n\n");

  do {
      printf("Inserisci un numero: ");

      // Verifica che l'input sia valido
      if (scanf("%d", &tentativo) != 1 || tentativo <= 0) {
          printf("Inserisci solo numeri interi positivi!\n");
          // Pulisce il buffer di input
          while (getchar() != '\n');
          continue;
      }

      tentativi++;

      if (tentativo > numeroSegreto) {
          printf("Troppo alto! Riprova.\n");
      } else if (tentativo < numeroSegreto) {
          printf("Troppo basso! Riprova.\n");
      } else {
          printf("Complimenti! Hai indovinato il numero in %d tentativi.\n", tentativi);
      }
  } while (tentativo != numeroSegreto);
  
  return 0;
    
}