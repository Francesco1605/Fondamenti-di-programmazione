#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#define ENDLN cout << endl << endl

inline void end_ln(int x) {
    for (int i = 0; i < x; i++) {
        cout << endl;
    }
}

class Person {
    private: // informazioni che possiamo modificare solo noi
    int age;

    protected: //
    string name;
    string surname;

    public: // informazioni che possono essere modificate da chiunque
    Person() {}; // costruttore nullo
    Person(string n, string s, int a) : name(n), surname(s), age(a) {}; // costruttore
    virtual ~Person() {cout << "~Person: " << name << endl;}; // distruttore

    // primo metodo:
    string getFullName() const {return name + " " + surname;}
    int getAge() const {return age;}

    // secondo metodo:
    void setName(string n) {name = n;}
    void setSurname(string s) {surname = s;}
    void setAge(int a) {age = a;}
};

class BasketPlayer : public Person {
    private:
    int number;
    float pointsPerGame;
    float reboundsPerGame;
    float assistsPerGame;

    public:
    BasketPlayer(string n, string s, int a, int num, float ppg, float rpg, float apg) : Person(n, s, a), number(num), pointsPerGame(ppg), reboundsPerGame(rpg), assistsPerGame(apg) {};

    void Print() const {
        cout << "Nome: " << name << " " << surname << endl;
        cout << "Età: " << getAge << endl;
        cout << "Numero maglia: " << number << endl;
        cout << "Punti a partita: " << pointsPerGame << endl;
        cout << "Rimbalzi a partita: " << reboundsPerGame << endl;
        cout << "Assist a partita: " << assistsPerGame << endl;
    }

    float getPointsPerGame() const {return pointsPerGame;}
    int getNumber() const {return number;}

};

int readPlayersFromFile(vector<BasketPlayer>& players, const string& filename) {

    static int totalPlayersRead = 0;

    fstream file(filename);
    if (!file) {
        cout << "Errore nell'apertura del file" << endl;
        return -1;
    }

    string firstName, lastName;
    int number;
    int count = 0;
    float ppg, rpg, apg;

    while (file >> firstName >> lastName >> number >> ppg >> rpg >> apg) {
        players.emplace_back(firstName, lastName, number, ppg, rpg, apg);
        totalPlayersRead++;
        count++;
    }

    cout << "[DEBUG]  Numero di giocatori letti: " << totalPlayersRead << endl << endl;
    
    return count;

}


int main()
{ 
    cout << "Hello, World!" << endl;

    ENDLN;

    end_ln(2);

    // se non vogliamo  scrivere a mano ogni volta il nome e il cognome di una persona, possiamo creare un oggetto che li contenga:
    vector<BasketPlayer> players;
    readPlayersFromFile(players, "giocatori.txt");

    cout << "--- Squadra letta dal file ---" << endl;
    for (const auto& p : players) {
        p.Print();
    }


    return 0;
}

    /* 
    - primo metodo per creare un oggetto:
    
    Person p1("James", "Lebron", 34);
    Person p2("Luka", "Doncic", 33);

    cout << p1.getFullName() << " " << p1.getAge() << endl;
    cout << p2.getFullName() << " " << p2.getAge() << endl;
    

    - secondo metodo per creare un oggetto:
    
    Person p3;
    p3.setName("Micheal");
    p3.setSurname("Jordan");

    cout << p3.getFullName() << endl;
    
    */