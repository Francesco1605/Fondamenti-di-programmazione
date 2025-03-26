#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

inline void end_ln(int x) {
    for (int i = 0; i < x; i++) {
        cout << endl;
    }
}

class Person {
protected:
    int age;
    string name;
    string surname;

public:
    Person() {}; 
    Person(const string& n, const string& s, int a) : name(n), surname(s), age(a) {}; 
    virtual ~Person() { cout << "~Person" << endl; } 

    string getFullName() const { return name + " " + surname; }
    int getAge() const { return age; }

    void setName(const string& n) { name = n; }
    void setSurname(const string& s) { surname = s; }
    void setAge(int a) { age = a; }
};

class BasketPlayer : public Person {
private:
    int number;
    float pointsPerGame;
    float reboundsPerGame;
    float assistsPerGame;

public:
    BasketPlayer(const string& n, const string& s, int a, int num, float ppg, float rpg, float apg) 
        : Person(n, s, a), number(num), pointsPerGame(ppg), reboundsPerGame(rpg), assistsPerGame(apg) {}

    void Print() const {
        cout << "---------------------------" << endl;
        cout << "Nome: " << getFullName() << endl;
        cout << "Età: " << getAge() << endl;
        cout << "Numero maglia: " << number << endl;
        cout << "Punti a partita: " << pointsPerGame << endl;
        cout << "Rimbalzi a partita: " << reboundsPerGame << endl;
        cout << "Assist a partita: " << assistsPerGame << endl;
        cout << "---------------------------" << endl << endl;
    }

    float getPointsPerGame() const { return pointsPerGame; }
    int getNumber() const { return number; }
};

int readPlayersFromFile(vector<BasketPlayer>& players, const string& filename) {
    static int totalPlayersRead = 0;

    ifstream file(filename);
    if (!file) {
        cout << "Errore nell'apertura del file" << endl;
        return -1;
    }

    string firstName, lastName;
    int age, number, count = 0;
    float ppg, rpg, apg;

    while (file >> firstName >> lastName >> age >> number >> ppg >> rpg >> apg) {
        players.emplace_back(firstName, lastName, age, number, ppg, rpg, apg);
        totalPlayersRead++;
        count++;
    }

    cout << "[DEBUG]  Numero di giocatori letti: " << totalPlayersRead << endl << endl;
    
    return count;
}

int main() { 
    cout << "Hello, World!" << endl;
    end_ln(2);

    vector<BasketPlayer> players;
    readPlayersFromFile(players, "giocatori.txt");

    cout << "--- Squadra letta dal file ---" << endl;
    for (const auto& p : players) {
        p.Print();
    }

    return 0;
}
