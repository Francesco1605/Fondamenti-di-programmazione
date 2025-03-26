#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name, surname;
public:
    Person(const string& n, const string& s) : name(n), surname(s) {}
    virtual ~Person() {}
    string getFullName() const { return name + " " + surname; }
};

class Player : public Person {
private:
    int number;
    float pointsPerGame, reboundsPerGame, assistsPerGame;
    static int totalPlayers;
public:
    Player(const string& n, const string& s, int num, float ppg, float rpg, float apg)
        : Person(n, s), number(num), pointsPerGame(ppg), reboundsPerGame(rpg), assistsPerGame(apg) {
        totalPlayers++;
    }

    ~Player() {}

    void print() const {
        cout << "---------------------------" << endl;
        cout << "Nome: " << getFullName() << endl;
        cout << "Numero di maglia: " << number << endl;
        cout << "Punti per partita: " << pointsPerGame << endl;
        cout << "Rimbalzi per partita: " << reboundsPerGame << endl;
        cout << "Assist per partita: " << assistsPerGame << endl;
        cout << "---------------------------" << endl << endl;
    }

    float getPointsPerGame() const { return pointsPerGame; }
    static int getTotalPlayers() { return totalPlayers; }
};

int Player::totalPlayers = 0;

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
