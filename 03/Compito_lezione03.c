#include <stdio.h>
#include "operazioni.h"

int main(void) {
  
  // input utente:
  int primonumero;
  int secondonumero;
  
  printf("%s %s\n", NOME, COGNOME);
  printf("Inserisci il primo numero: ");
  scanf("%d", &primonumero);

  printf("Inserisci il secondo numero: ");
  scanf("%d", &secondonumero);
  printf("\n\n");
  
  // output del programma:
  printf("Somma: %d + %d = %d\n", primonumero, secondonumero, 
  SOMMA(primonumero, secondonumero));
  printf("Sottrazione: %d - %d = %d\n", primonumero, secondonumero, 
  SOTTRAZIONE(primonumero, secondonumero));
  printf("Moltiplicazione: %d * %d = %d\n", primonumero, secondonumero, 
  MOLTIPLICAZIONE(primonumero, secondonumero));
  printf("Divisione: %d / %d = %.2lf\n", primonumero, secondonumero, 
  DIVISIONE(primonumero, secondonumero));
  printf("Modulo: %d %% %d = %d\n", primonumero, secondonumero, 
  MODULO(primonumero, secondonumero));
  double calcolo_complesso = (SOMMA(primonumero, secondonumero) * 
  primonumero - secondonumero) / primonumero;
  printf("Calcolo complesso: (((%d + %d) * %d) - %d) / %d = %.2lf\n",   
  primonumero, secondonumero, primonumero, secondonumero, primonumero,
  calcolo_complesso);

  printf("Grazie per aver usato il nostro programma!\n");
  
  return 0;
}
