#include <stdio.h>

// Macro per calcolare la penale del 10%
#define CALCOLA_PENALE(importo) ((importo) * 0.10)

// Definizione per abilitare/disabilitare la penale
#define ABILITA_PENALE

// Soglia per il controllo della spesa totale
#define SOGLIA_SPESA 500.0

// Definizione per abilitare il debug
#define DEBUG

int main() {
    float elettricita, acqua, gas, internet;
    float totale, penale = 0.0;

    // Input delle spese
    printf("Inserisci la spesa per l'elettricità: ");
    scanf("%f", &elettricita);

    printf("Inserisci la spesa per l'acqua: ");
    scanf("%f", &acqua);

    printf("Inserisci la spesa per il gas: ");
    scanf("%f", &gas);

    printf("Inserisci la spesa per internet: ");
    scanf("%f", &internet);

    // Calcolo del totale
    totale = elettricita + acqua + gas + internet;

    // Calcolo della penale se abilitata
    #ifdef ABILITA_PENALE
        penale = CALCOLA_PENALE(totale);
    #endif

    // Debug: stampa delle spese
    #ifdef DEBUG
        printf("[DEBUG] Spesa elettricità: %.2f\n", elettricita);
        printf("[DEBUG] Spesa acqua: %.2f\n", acqua);
        printf("[DEBUG] Spesa gas: %.2f\n", gas);
        printf("[DEBUG] Spesa internet: %.2f\n", internet);
        printf("[DEBUG] Totale senza penale: %.2f\n", totale);
        printf("[DEBUG] Penale (se applicabile): %.2f\n", penale);
    #endif

    // Controllo se la spesa supera la soglia
    if (totale > SOGLIA_SPESA) {
        printf("Attenzione: la spesa totale supera la soglia di %.2f euro!\n", SOGLIA_SPESA);
    } else {
        printf("La spesa totale è entro la soglia di %.2f euro.\n", SOGLIA_SPESA);
    }

    // Suggerimenti di risparmio
    printf("Suggerimenti di risparmio:\n");
    switch ((int)(totale / 100)) {
        case 0:
        case 1:
        case 2:
            printf("- Ottimo lavoro! Continua così.\n");
            break;
        case 3:
        case 4:
            printf("- Considera di ridurre il consumo di gas o acqua.\n");
            break;
        case 5:
        case 6:
            printf("- Riduci l'uso di elettrodomestici energivori.\n");
            break;
        default:
            printf("- Necessario un piano di risparmio generale.\n");
            break;
    }

    // Riepilogo finale
    printf("\nRiepilogo:\n");
    printf("Spesa elettricità: %.2f euro\n", elettricita);
    printf("Spesa acqua: %.2f euro\n", acqua);
    printf("Spesa gas: %.2f euro\n", gas);
    printf("Spesa internet: %.2f euro\n", internet);
    printf("Totale senza penale: %.2f euro\n", totale);
    #ifdef ABILITA_PENALE
        printf("Penale applicata: %.2f euro\n", penale);
    #else
        printf("Penale non applicata.\n");
    #endif
    printf("Totale con penale: %.2f euro\n", totale + penale);

    return 0;
}
