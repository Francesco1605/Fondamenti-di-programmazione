#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define PLAYERS_FILE_NAME "giocatori.txt"

struct Player 
{
    char name[50];
    char surname[50];
    int number;
    float pointsPerGame;
    float reboundsPerGame;
    float assistsPerGame;
};

// Removed duplicate function definition

int readPlayersFromFile(struct Player tm[], int size)
{

    int result = 0;
    FILE* file = fopen(PLAYERS_FILE_NAME, "r");
    if (file == NULL)
    {
        printf("Errore: impossibile leggere il file con i dati dei giocatori\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            fscanf(file, "%s %s %d %f %f %f", tm[i].name, tm[i].surname, tm[i].number, tm[i].pointsPerGame, tm[i].reboundsPerGame, tm[i].assistsPerGame);
        }
        fclose(file);
        result = size;
    }
    return result;
}

void Print_Player(struct Player tm[], int size)
{
    for (int i = 0; i < size; i++)
    {
        struct Player* ptr = &tm[i];
        printf("Hello %s %s: numero di maglia %d punti %f\n", ptr->name, ptr->surname, ptr->number, ptr->pointsPerGame);
    }
}

struct Player bestPlayer(struct Player tm[], int size)
{
    struct Player best = tm[0];
    for (int i = 1; i < size; i++)
    {
        if (tm[i].pointsPerGame > best.pointsPerGame)
        {
            best = tm[i];
        }
    }
    return best;
}

int main()
{
    struct Player team[MAX_PLAYERS];
    int numPlayers = readPlayersFromFile(team, MAX_PLAYERS);
    if (numPlayers > 0)
    {
        printf("Non ci sono giocatori da leggere dal file\n");
    }
    if (numPlayers <= 0)
    {
        Print_Player(team, MAX_PLAYERS);
    }
    printf("\n\n");

    return 0;

}