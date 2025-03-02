#include <stdio.h>
#include <string.h>

// Macro per calcolare l'IVA
#define CALCOLA_IVA(spesa) ((spesa) * 0.22)

int main() 
{
    char giorno[20];
    float spesa, iva, totale_con_iva;

    // Chiede all'utente di inserire il giorno della settimana e la spesa
    printf("Inserisci il giorno della settimana: ");
    scanf("%s", giorno);

    printf("Inserisci la spesa effettuata in questo giorno: ");
    scanf("%f", &spesa);

    // Calcolo dell'IVA e del totale con IVA
    iva = CALCOLA_IVA(spesa);
    totale_con_iva = spesa + iva;

    // Determinazione se il giorno è feriale o festivo
    if (strcmp(giorno, "sabato") == 0 || strcmp(giorno, "domenica") == 0) {
        printf("Giorno festivo: %s\n", giorno);
    } else if (strcmp(giorno, "lunedi") == 0 || strcmp(giorno, "martedi") == 0 ||
               strcmp(giorno, "mercoledi") == 0 || strcmp(giorno, "giovedi") == 0 ||
               strcmp(giorno, "venerdi") == 0) {
        printf("Giorno feriale: %s\n", giorno);
    } else {
        printf("Giorno non valido: %s\n", giorno);
        return 1; // Esce dal programma con codice di errore
    }

    // Stampa i risultati
    printf("Spesa senza IVA: %.2f euro\n", spesa);
    printf("IVA (22%%): %.2f euro\n", iva);
    printf("Totale con IVA: %.2f euro\n", totale_con_iva);

    return 0;
}
