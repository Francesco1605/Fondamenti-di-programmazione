#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "player.h"

using namespace std;

// inizializzazione della variabile statica
int Player::totalPlayers = 0;

// implementazione dei metodi di person
Person::Person(const string& n, const string& s) : name(n), surname(s) {}
Person::~Person() {}
string Person::getFullName() const { return name + " " + surname; }

// implementazione dei metodi di player
Player::Player(const string& n, const string& s, int num, float ppg, float rpg, float apg)
    : Person(n, s), number(num), pointsPerGame(ppg), reboundsPerGame(rpg), assistsPerGame(apg) {
    totalPlayers++;
}

Player::~Player() {}

void Player::print() const {
    cout << "---------------------------" << endl;
    cout << "Nome: " << getFullName() << endl;
    cout << "Numero di maglia: " << number << endl;
    cout << "Punti per partita: " << pointsPerGame << endl;
    cout << "Rimbalzi per partita: " << reboundsPerGame << endl;
    cout << "Assist per partita: " << assistsPerGame << endl;
    cout << "---------------------------" << endl << endl;
}

float Player::getPointsPerGame() const { return pointsPerGame; }
int Player::getTotalPlayers() { return totalPlayers; }

// funzione per leggere i giocatori dal file
int readPlayersFromFile(vector<Player>& players, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Errore nell'apertura del file: " << filename << endl;
        return 0;
    }

    string firstName, lastName;
    int number;
    float ppg, rpg, apg;
    int count = 0;

    while (file >> firstName >> lastName >> number >> ppg >> rpg >> apg) {
        if (players.size() >= 10) break;
        players.emplace_back(firstName, lastName, number, ppg, rpg, apg);
        count++;
    }
    file.close();

    cout << "Giocatori letti in questa chiamata: " << count << endl;
    cout << "Totale giocatori letti finora: " << Player::getTotalPlayers() << endl << endl;
    return count;
}

// funzione per trovare il miglior marcatore
Player bestScorer(const vector<Player>& players) {
    if (players.empty()) {
        cerr << "Errore: nessun giocatore disponibile." << endl;
        exit(1);
    }

    const Player* best = &players[0];
    for (const auto& player : players) {
        if (player.getPointsPerGame() > best->getPointsPerGame()) {
            best = &player;
        }
    }
    return *best;
}

// funzione principale
int main() {
    vector<Player> players;

    readPlayersFromFile(players, "giocatori1.txt");
    readPlayersFromFile(players, "giocatori2.txt");

    cout << "--- Squadra ---" << endl;
    for (const auto& player : players) {
        player.print();
    }

    Player best = bestScorer(players);
    cout << "Il miglior marcatore della squadra è: " << best.getFullName()
         << " con " << best.getPointsPerGame() << " punti a partita." << endl;

    return 0;
}
