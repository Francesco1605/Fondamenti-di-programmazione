#include <stdio.h>

int main(void) {

  int numeri[10];
  int positiveSum = 0, negativeSum = 0;
  int max, min;
  int evenCount = 0, oddCount = 0;
  int allPositive = 1, allNegative = 1;
  int multipleOfFive = 0;
  
  // Chiediamo all'utente di inserire i 10 numeri:
  printf("Inserisci 10 numeri interi: ");

  for(int i = 0; i < 10; i++) {
    printf("Numero %d: ", i + 1);
    scanf("%d", &numeri[i]);

  // Calcoliamo la somma dei numeri positivi e dei numeri negativi:
  if (numeri[i] > 0) {
    positiveSum += numeri[i];
    allNegative = 0;
  } else if (numeri[i] < 0) {
    negativeSum += numeri[i];
    allPositive = 0;
  }
    
     // Calcolo del numero di numeri pari e dispari:
    if(numeri[i] % 2 == 0) {
      evenCount++;
    } else {
      oddCount++;
    }
    
    // Verifica se almeno un numero è multiplo di 5:
    if(numeri[i] % 5 == 0) {
      multipleOfFive = 1;
    }
    
    // Calcolo di massimo e minimo:
    if(i == 0) {
    max = min = numeri[i];
    } else {
      if(numeri[i] > max) {
        max = numeri[i];
      }
      if(numeri[i] < min) {
        min = numeri[i];
      }
    }
  }

   // Stampa delle informazioni calcolate:
   printf("\nSomma dei numeri positivi: %d\n", positiveSum);
   printf("Somma dei numeri negativi: %d\n", negativeSum);
   printf("Somma di numeri pari: %d\n", evenCount);
   printf("Somma di numeri dispari: %d\n", oddCount);
   printf("Valore massimo: %d\n", max);
   printf("Valore minimo: %d\n", min);

   // Verifica se tutti i numeri sono positivi o negativi:
  if(allPositive) {
    printf("Tutti i numeri sono positivi.\n");
  } else if(allNegative) {
    printf("Tutti i numeri sono negativi.\n");
  }

   // Verifica se almeno un numero è multiplo di 5:
  if(multipleOfFive) {
    printf("Almeno un numero è multiplo di 5.\n");
  }
  
  return 0;
  
}