#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>

class Person {
protected:
    std::string name;
    std::string surname;

public:
    Person(const std::string& name, const std::string& surname) : name(name), surname(surname) {}
    std::string getFullName() const {
        return name + " " + surname;
    }
};

class Player : public Person {
private:
    int number;
    float pointsPerGame;
    float reboundsPerGame;
    float assistsPerGame;
    static int totalPlayers; // Variabile statica per tenere traccia del numero totale di giocatori

public:
    Player(const std::string& name, const std::string& surname, int number, float points, float rebounds, float assists)
        : Person(name, surname), number(number), pointsPerGame(points), reboundsPerGame(rebounds), assistsPerGame(assists) {
        totalPlayers++; // Incremento la variabile statica ogni volta che viene creato un nuovo giocatore
    }

    void print() const {
        std::cout << "Nome: " << getFullName() << "\n"
                  << "Numero di maglia: " << number << "\n"
                  << "Punti per partita: " << pointsPerGame << "\n"
                  << "Rimbalzi per partita: " << reboundsPerGame << "\n"
                  << "Assist per partita: " << assistsPerGame << "\n\n";
    }

    float getPointsPerGame() const {
        return pointsPerGame;
    }

    static int getTotalPlayers() {
        return totalPlayers;
    }

    static void resetTotalPlayers() {
        totalPlayers = 0;
    }
};

// Inizializzazione della variabile statica fuori dalla classe
int Player::totalPlayers = 0;

int readPlayersFromFile(std::vector<Player>& players, const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Errore nell'apertura del file!\n";
        return 0;
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line) && count < 5) {
        std::istringstream iss(line);
        std::string name, surname;
        int number;
        float points, rebounds, assists;
        if (!(iss >> name >> surname >> number >> points >> rebounds >> assists)) {
            std::cerr << "Errore nel formato della riga: " << line << "\n";
            continue;
        }
        players.emplace_back(name, surname, number, points, rebounds, assists);
        count++;
    }
    std::cout << "Numero totale di giocatori letti fino ad ora: " << Player::getTotalPlayers() << "\n";
    return count;
}

Player bestScorer(const std::vector<Player>& players) {
    if (players.empty()) {
        throw std::runtime_error("Nessun giocatore presente!");
    }
    const Player* best = &players[0];
    for (const auto& player : players) {
        if (player.getPointsPerGame() > best->getPointsPerGame()) {
            best = &player;
        }
    }
    return *best;
}

int main() {
    std::vector<Player> players;
    readPlayersFromFile(players, "giocatori.txt");

    std::cout << "--- Squadra ---\n\n";
    for (const auto& player : players) {
        player.print();
    }

    try {
        Player topScorer = bestScorer(players);
        std::cout << "Il miglior marcatore della squadra è: " << topScorer.getFullName()
                  << " con " << topScorer.getPointsPerGame() << " punti a partita.\n";
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
