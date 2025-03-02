
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10

// definizione della struct player
typedef struct {
    char name[50];
    int number;
    float pointsPerGame;
    float reboundsPerGame;
    float assistsPerGame;
} Player;

// funzione per leggere i giocatori da un file
int readPlayersFromFile(Player players[], const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("errore nell'apertura del file %s\n", filename);
        return 0;
    }

    int count = 0;
    char line[256];
    
    while (count < MAX_PLAYERS && fgets(line, sizeof(line), file)) {
        // Ignora righe vuote
        if (line[0] == '\n' || line[0] == '\0') {
            continue;
        }
        
        // Leggi nome, cognome e statistiche
        char firstName[25], lastName[25];
        if (sscanf(line, "%s %s %d %f %f %f", 
                firstName, lastName, &players[count].number, 
                &players[count].pointsPerGame, &players[count].reboundsPerGame, 
                &players[count].assistsPerGame) == 6) {
            
            // Combina nome e cognome
            sprintf(players[count].name, "%s %s", firstName, lastName);
            count++;
        }
    }

    fclose(file);
    return count;
}

// funzione per stampare un giocatore
void printPlayer(const Player* p) {
    printf("nome: %s\nnumero di maglia: %d\n", p->name, p->number);
    printf("punti per partita: %.2f\nrimbalzi per partita: %.2f\nassist per partita: %.2f\n\n", 
           p->pointsPerGame, p->reboundsPerGame, p->assistsPerGame);
}

// funzione per trovare il miglior marcatore
Player bestScorer(Player players[], int size) {
    Player best = players[0];
    for (int i = 1; i < size; i++) {
        if (players[i].pointsPerGame > best.pointsPerGame) {
            best = players[i];
        }
    }
    return best;
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers = 0;

    // Prima lettura dal primo file
    numPlayers = readPlayersFromFile(players, "giocatori1.txt");

    printf("--- squadra ---\n\n");
    for (int i = 0; i < numPlayers; i++) {
        printPlayer(&players[i]);
    }

    // trovare e stampare il miglior marcatore
    Player topScorer = bestScorer(players, numPlayers);
    printf("il miglior marcatore della squadra è: %s con %.2f punti a partita.\n", 
           topScorer.name, topScorer.pointsPerGame);

    // Seconda lettura dal secondo file
    numPlayers = readPlayersFromFile(players, "giocatori2.txt");

    printf("--- squadra dal secondo file ---\n\n");
    for (int i = 0; i < numPlayers; i++) {
        printPlayer(&players[i]);
    }

    // trovare e stampare il miglior marcatore dal secondo file
    topScorer = bestScorer(players, numPlayers);
    printf("il miglior marcatore della squadra è: %s con %.2f punti a partita.\n", 
           topScorer.name, topScorer.pointsPerGame);

    return 0;
}
